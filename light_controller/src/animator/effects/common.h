#pragma once

#include "Arduino.h"

class Effect {
public:
  virtual void draw() = 0;
};

extern uint8_t idx;
extern uint8_t delta;
extern float progress;
extern uint8_t current_effect;
