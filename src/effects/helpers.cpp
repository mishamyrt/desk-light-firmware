#include "helpers.h"
#include "../../lightstrip.h"
#include "animation.h"
#include <Arduino.h>

uint8_t calculate_middle_value(uint8_t first, uint8_t second, float ratio) {
  // send_log(ratio * 10000);
  if (ratio >= 1 || ratio < 0) {
    return second;
  }
  return (second * ratio) + (first * (1.0 - ratio));
}

void copy_colors(uint8_t *target, rgb_color source) {
  target[0] = source[0];
  target[1] = source[1];
  target[2] = source[2];
}

bool is_same_color (rgb_color first, rgb_color second) {
  return \
    first[0] == second[0] && \
    first[1] == second[1] && \
    first[2] == second[2];
}
