#pragma once

#include "Arduino.h"
#include "FastLED.h"
#include "effects_common.h"
#include "../light/light.h"

class EffectsController {
public:
  void initialize();

  void startEffect (Effect &effect) {
    progress = 0;
    step = 1;
    state = STATE_ANIMATE;
    current_effect = &effect;
    current_effect->prepare();
    step_count = current_effect->stepCount();
    step_delay = current_effect->stepDelay();
  }

  void handleFrame() {
    if (state == STATE_READY) {
      return;
    }
    current_effect->draw();
    Light.apply();
    if (step_count != 0) {
      if (step == step_count) {
        state = STATE_READY;
      } else {
        step++;
      }
    }
    delay(step_delay);
  }

private:
  enum {
    STATE_READY = 0,
    STATE_ANIMATE = 1
  };

  Effect *current_effect;
  uint8_t step_delay;
  uint8_t step_count;
  uint8_t state = STATE_READY;
};
