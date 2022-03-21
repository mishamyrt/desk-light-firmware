#include "Arduino.h"
#include "FastLED.h"
#include "../../light/light.h"
#include "../../animator/effects.h"

// Format: [cmd, is_inverted, count, {from, to}]
bool handle_set_color_zones(uint8_t *message, uint8_t message_length) {
  if (message_length < 4) {
    return false;
  }
  Crossfade.is_zones_inverted = message[1];
  Crossfade.zones_count = message[2];
  uint8_t zone_offset;
  for (int i = 0; i < Crossfade.zones_count; i++) {
    zone_offset = (i * 2) + 3;
    Crossfade.zones[i].from = message[zone_offset];
    Crossfade.zones[i].to = message[zone_offset+1];
  }
  return true;
}

// Format: [cmd, brightness, {r, g, b}]
bool handle_set_color(uint8_t *message, uint8_t message_length) {
  if (message_length < 5) {
    return false;
  }
  Crossfade.setNextBrightness(message[1]);
  uint8_t color_offset;
  for (int i = 0; i < Crossfade.zones_count; i++) {
    color_offset = (i * 3) + 2;
    Crossfade.setNextColor(i, CRGB(
      message[color_offset],
      message[color_offset + 1],
      message[color_offset + 2]
    ));
  }
  Animator.startEffect(Crossfade);
  return true;
}
