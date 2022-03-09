#include "FastLED.h"
#include "Arduino.h"
#include "../effects.h"
#include "transitions.h"
#include "../../light/hardware.h"
#include "../../light/api.h"
#include "../../../lightstrip.h"

#define COLOR_TWEEN_STEPS 20.0
float COLOR_STEP = (float)1 / COLOR_TWEEN_STEPS;

void color_tween_transition () {
  index++;
  float progress = (float)COLOR_STEP * index;
  for (int i = 0; i < 3; i++) {
    color[i] = calculate_middle_value(start_color[i], target_color[i], progress);
  }
  apply_current_color();
  if (index == COLOR_TWEEN_STEPS) {
    stop_effect();
  } else {
    delay(5);
  }
}
