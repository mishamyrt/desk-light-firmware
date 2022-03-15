#include "../effects/transition.h"
#include "../effects/effects.h"
#include "../effects/helpers.h"
#include "hardware.h"

rgb_color color;

void apply_power (bool state) {
  if (state) {
    fill_from_center(color[0], color[1], color[2]);
  } else {
    fill_to_center(0, 0, 0);
  }
}

void apply_brightness(uint8_t value) {
  smooth_brightness(value);
}

void apply_current_color() {
  fill_leds(color[0], color[1], color[2]);
  apply();
}

void apply_color(uint8_t r, uint8_t g, uint8_t b) {
  tween_color(r, g, b);
}

void apply_ambilight_colors() {
  progress = 0;
  effect_index = 0;
}

// void apply_color_raw(uint8_t r, uint8_t g, uint8_t b) {
//   color[0] = r;
//   color[1] = g;
//   color[2] = b;
//   apply_current_color()
// }
