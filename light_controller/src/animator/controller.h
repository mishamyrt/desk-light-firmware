#pragma once

#include "Arduino.h"
#include "effects.h"
#include "effects/common.h"

extern uint8_t current_effect;

class EffectsController {
public:
  void initialize();

  void stopEffect();

  void startEffect(uint8_t new_effect) {
    current_effect = new_effect;
    progress = 0;
    idx = 0;
  };

  void handleFrame();
};

extern EffectsController Animator;
