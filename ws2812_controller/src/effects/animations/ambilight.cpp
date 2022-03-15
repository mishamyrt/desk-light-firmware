#include <Arduino.h>
#include "../animation.h"
#include "../../light/hardware.h"
#include "../../light/api.h"
#include "../../../lightstrip.h"
#include "../effects.h"
#include "../helpers.h"

#define AMBILIGHT_TRANSITION_STEPS 12
const float AMBILIGHT_TRANSITION_STEP = 1.0 / AMBILIGHT_TRANSITION_STEPS;

ambilight_zone zones[AMBILIGHT_ZONES_MAX];
uint8_t zones_count;

void set_zone_middle_color(int zone_index, float ratio) {
  for (int i = 0; i < 3; i++) {
    // zones[zone_index].color[i] = zones[zone_index].target_color[i];
    zones[zone_index].color[i] = calculate_middle_value(
      zones[zone_index].previous_color[i],
      zones[zone_index].target_color[i],
      ratio
    );
  }
}

void update_zone_color(int zone_index) {
  int zone_length = zones[zone_index].index_to - zones[zone_index].index_from;
  for (int j = 0; j < zone_length; j++) {
    index = j + zones[zone_index].index_from;
    if (is_inverted) {
      index = LED_COUNT - index;
    }
    leds[index] = CRGB(
      zones[zone_index].color[0],
      zones[zone_index].color[1],
      zones[zone_index].color[2]
    );
  }
}

void animate_ambilight() {
  if (effect_index >= AMBILIGHT_TRANSITION_STEPS) {
    stop_effect();
  }
  effect_index++;
  progress = (float)AMBILIGHT_TRANSITION_STEP * effect_index;
  for (int i = 0; i < zones_count; i++) {
    if (is_same_color(zones[i].color, zones[i].target_color)) {
      continue;
    }
    set_zone_middle_color(i, progress);
    update_zone_color(i);
  }
  delay(2);
  apply();
}
