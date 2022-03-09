#include "effects.h"
#include "transitions/transitions.h"
#include "../../lightstrip.h"

int previous_effect = EFFECT_NONE;

void handle_frame() {
  // if (effect == EFFECT_NONE && previous_effect != EFFECT_NONE) {
  //   send(0);
  // }
  // previous_effect = effect;
  switch (effect) {
    case EFFECT_FILL_FROM_CENTER:
      color_fill_transition(true);
      break;
    case EFFECT_FILL_TO_CENTER:
      color_fill_transition(false);
      break;
    case EFFECT_SMOOTH_BRIGHTNESS:
      smooth_brightness_transition();
      break;
    case EFFECT_COLOR_TWEEN:
      color_tween_transition();
      break;
  }
}
