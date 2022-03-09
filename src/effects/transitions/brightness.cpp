#include "FastLED.h"
#include "../effects.h"
#include "transitions.h"
#include "../../light/hardware.h"
#include "../../../lightstrip.h"

void smooth_brightness_transition() {
  step_to_target(target_brightness, &brightness, 2, true);
  apply();
  delay(2);
}
