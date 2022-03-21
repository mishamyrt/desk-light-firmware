#pragma once

#include "Arduino.h"
#include "FastLED.h"
#include "../effects_common.h"
#include "../../light/light.h"

class RainbowEffect: public Effect {
public:
  void draw () {
    first_color.hue = getHue(0);
    second_color.hue = getHue(60);
    third_color.hue = getHue(120);

    fill_gradient(
      Light.leds,
      LED_CENTER,
      first_color,
      second_color,
      third_color,
      FORWARD_HUES
    );

    Light.mirrorLEDs();

    global_hue++;
    if (global_hue > 255) {
      global_hue = 0;
    }
  }

  void prepare () {
    global_hue = 0;
  }

  uint8_t stepCount() {
    return 0;
  }

  uint8_t stepDelay() {
    return 40;
  }

private:
  uint8_t getHue(uint8_t hue_shift) {
    hue = global_hue + hue_shift;
    if (hue > 255) {
      hue -= 255;
    }
    return hue;
  }

  CHSV first_color = CHSV(0, 255, 255);
  CHSV second_color = CHSV(0, 255, 255);
  CHSV third_color = CHSV(0, 255, 255);
  int global_hue;
  int hue;
};
