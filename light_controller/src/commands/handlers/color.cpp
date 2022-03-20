#include "Arduino.h"
#include "FastLED.h"
#include "../../light/light.h"
#include "../../animator/effects.h"
#include "../../animator/controller.h"

// Format: [cmd, count, {from, to}]
void handle_set_color_zones(uint8_t *message, uint8_t message_length) {
  if (message_length < 4) {
    // TODO: Send error
    return;
  }
  Crossfade.zones_count = message[1];
  uint8_t offset = 2;
  for (int i = 0; i < Crossfade.zones_count; i++) {
    Crossfade.zones[0].idx_from = message[offset]++;
    Crossfade.zones[0].idx_to = message[offset]++;
  }
}

// Format: [cmd, brightness, {r, g, b}]
void handle_set_color(uint8_t *message, uint8_t message_length) {
  if (message_length < 5) {
    // TODO: Send error
    return;
  }
  Crossfade.target_brightness = message[1];
  uint8_t offset = 3;
  for (int i = 0; i < Crossfade.zones_count; i++) {
    Crossfade.zones[i].target_color = CRGB(
      message[offset++],
      message[offset++],
      message[offset++]
    );
    Crossfade.zones[i].previous_color = Crossfade.zones[i].color;
  }
  Animator.startEffect(EFFECT_CROSSFADE);
}
