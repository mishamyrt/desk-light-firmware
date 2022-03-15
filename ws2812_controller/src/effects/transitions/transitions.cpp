#include "../effects.h"
#include "Arduino.h"

uint8_t start_color[3];
uint8_t target_color[3];
uint8_t target_brightness;
uint8_t start_brightness;
int new_value;

void step_to_target(uint8_t target, uint8_t *current, int step, bool stop) {
  if (target > *current) {
    new_value = *current + step;
    if (new_value > target) {
      new_value = target;
      if (stop) stop_effect();
    }
  } else if (target < *current) {
    new_value = *current - step;
    if (new_value < target) {
      new_value = target;
      if (stop) stop_effect();
    }
  } else if (target == *current) {
    if (stop) stop_effect();
  }
  *current = new_value;
}
