#include "FastLED.h"
#include "Arduino.h"
#include "../effects.h"
#include "transitions.h"
#include "../../light/hardware.h"
#include "../../light/api.h"
#include "../../../lightstrip.h"
#include "../helpers.h"

#define COLOR_TWEEN_STEPS 20
const float COLOR_STEP = 1.0 / COLOR_TWEEN_STEPS;

void set_middle_color(float ratio) {
  for (int i = 0; i < 3; i++) {
    color[i] = calculate_middle_value(start_color[i], target_color[i], ratio);
  }
}

void color_tween_transition () {
  index++;
  progress = COLOR_STEP * (float)index;
  if (!is_same_color(target_color, color)) {
    set_middle_color(progress);
  }
  if (brightness != target_brightness) {
    brightness = calculate_middle_value(start_brightness, target_brightness, progress);
  }
  apply_current_color();
  if (index == COLOR_TWEEN_STEPS) {
    stop_effect();
  } else {
    delay(5);
  }
}
