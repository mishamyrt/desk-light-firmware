#include "Arduino.h"
#include "transitions/transitions.h"
#include "effects.h"
#include "../light/api.h"
#include "../light/hardware.h"
#include "helpers.h"
#include "../../lightstrip.h"

void start_color_transition(uint8_t r, uint8_t g, uint8_t b, uint8_t transition) {
  target_color[0] = r;
  target_color[1] = g;
  target_color[2] = b;
  copy_colors(start_color, color);
  start_effect(transition);
}

void fill_from_center(uint8_t r, uint8_t g, uint8_t b) {
  start_color_transition(r, g, b, EFFECT_FILL_FROM_CENTER);
}

void fill_to_center(uint8_t r, uint8_t g, uint8_t b) {
  start_color_transition(r, g, b, EFFECT_FILL_TO_CENTER);
}

void tween_color(uint8_t r, uint8_t g, uint8_t b, uint8_t new_brightness) {
  start_brightness = brightness;
  target_brightness = new_brightness;
  start_color_transition(r, g, b, EFFECT_COLOR_TWEEN);
}
