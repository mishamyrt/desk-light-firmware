#include "Arduino.h"
#include "transitions/transitions.h"
#include "effects.h"
#include "../light/api.h"
#include "../../lightstrip.h"

void start_color_transition(uint8_t r, uint8_t g, uint8_t b, int transition) {
  target_color[0] = r;
  target_color[1] = g;
  target_color[2] = b;
  start_color[0] = color[0];
  start_color[1] = color[1];
  start_color[2] = color[2];
  start_effect(transition);
}

void fill_from_center(uint8_t r, uint8_t g, uint8_t b) {
  start_color_transition(r, g, b, EFFECT_FILL_FROM_CENTER);
}

void fill_to_center(uint8_t r, uint8_t g, uint8_t b) {
  start_color_transition(r, g, b, EFFECT_FILL_TO_CENTER);
}

void tween_color(uint8_t r, uint8_t g, uint8_t b) {
  start_color_transition(r, g, b, EFFECT_COLOR_TWEEN);
}

void smooth_brightness(uint8_t target) {
  target_brightness = target;
  start_effect(EFFECT_SMOOTH_BRIGHTNESS);
}
