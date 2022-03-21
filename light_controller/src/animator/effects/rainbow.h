#pragma once

#include "Arduino.h"
#include "FastLED.h"
#include "../effects_common.h"
#include "../../light/light.h"

class RainbowEffect: public Effect {
public:
  void draw () {
    hue = hue + 5;
    if (step >= LED_COUNT) {
      step = 0;
    }
    if (hue > 255) {
      hue = 0;
    }
    Light.setLED(step, CHSV(hue, 255, 255));
    step++;
  }

  void prepare () {
    hue = 0;
  }

  uint8_t stepCount() {
    return 0;
  }

  uint8_t stepDelay() {
    return 10;
  }

private:
  int hue;
};
