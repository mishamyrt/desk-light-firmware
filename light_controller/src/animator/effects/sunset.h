#pragma once

#include "Arduino.h"
#include "FastLED.h"
#include "../effects_common.h"
#include "../../light/light.h"

#define SUNSET_STAGE_STEP_COUNT 255
const float SUNSET_STEP = 1.0 / SUNSET_STAGE_STEP_COUNT;

typedef struct EffectStage {
  uint8_t center;
  uint8_t side;
};

class SunsetEffect: public Effect {
public:
  void draw () {
    progress = SUNSET_STEP * (float)step;
    center.hue = blend_values(
      stages[current].center,
      stages[next].center,
      progress
    );
    side.hue = blend_values(
      stages[current].side,
      stages[next].side,
      progress
    );
    fill_gradient(
      Light.leds,
      LED_CENTER,
      side,
      side,
      center
    );
    Light.mirrorLEDs();
    if (step == 255) {
      step = 1;
      current = next;
      // If current is last, then next is first
      if (current == 5) {
        next = 0;
      } else {
        next = current + 1;
      }
    } else {
      step++;
    }
  }

  void prepare () {
    current = 0;
    next = 1;
  }

  uint8_t stepCount() {
    return 0;
  }

  uint8_t stepDelay() {
    return 30;
  }

private:
  uint8_t current;
  uint8_t next;
  CHSV center = CHSV(30, 255, 255);
  CHSV side = CHSV(30, 255, 128);
  const EffectStage stages[6] = {
    {35, 18},
    {33, 14},
    {31, 10},
    {29, 7},
    {20, 4},
    {18, 2}
  };
};
