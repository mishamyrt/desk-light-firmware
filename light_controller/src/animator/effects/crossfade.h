#pragma once

#include "Arduino.h"
#include "FastLED.h"
#include "../../light/light.h"
#include "common.h"

#define ZONES_MAX_COUNT 24
#define CROSSFADE_STEPS_COUNT 20
const float CROSSFADE_STEP = 255 / CROSSFADE_STEPS_COUNT;

typedef struct Zone {
  int idx_from;
  int idx_to;
  CRGB target_color;
  CRGB previous_color;
  CRGB color;
};

inline uint8_t blend_uint8(uint8_t current, const uint8_t target, uint8_t amount) {
  if (current == target) return;
  if (current < target) {
    delta = scale8_video(target - current, amount);
    current += delta;
  } else {
    delta = scale8_video(current - target, amount);
    current -= delta;
  }
  return current;
}

inline CRGB blend_colors(CRGB first, CRGB second, float ratio) {
  return CRGB(
    blend_uint8(first.red, second.red, ratio),
    blend_uint8(first.green, second.green, ratio),
    blend_uint8(first.blue, second.blue, ratio)
  );
}

class CrossfadeEffect : public Effect {
public:
  void draw() {
    idx++;
    progress = CROSSFADE_STEP * idx;
    for (int i = 0; i < zones_count; i++) {
      drawZone(i, progress);
    }
    if (Light.brightness != target_brightness) {
      Light.brightness = blend_uint8(start_brightness, target_brightness, progress);
    }

    Light.apply();
    if (idx == CROSSFADE_STEPS_COUNT) {
      current_effect = 0;
    } else {
      delay(5);
    }
  }

  uint8_t target_brightness;
  uint8_t start_brightness;
  uint8_t zones_count;
  Zone zones[ZONES_MAX_COUNT];

private:
  void drawZone(uint8_t zone_idx, uint8_t ratio) {
    if (zones[zone_idx].target_color == zones[zone_idx].color) {
      return;
    }
    zones[zone_idx].color = blend_colors(
      zones[zone_idx].previous_color,
      zones[zone_idx].target_color,
      ratio
    );
    for (int i = zones[zone_idx].idx_from; i < zones[zone_idx].idx_to; i++) {
      Light.setLED(i, zones[zone_idx].color);
    }
  };
};
