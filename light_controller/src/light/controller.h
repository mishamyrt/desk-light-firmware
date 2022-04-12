#pragma once

#include "Arduino.h"
#include "FastLED.h"

#define LED_DT 13
#define LED_COUNT 120

class LightController {
  public:
    void initialize() {
      LEDS
        .addLeds<WS2811, LED_DT, GRB>(leds, LED_COUNT)
        .setCorrection(0xFF7A60); // 255, 122, 96
      setLEDs(CRGB::Black);
      apply();
    }

    /// Mirrors into the second half of the strip what is in the first half
    void mirrorLEDs() {
      for (uint8_t i = 0; i < (LED_COUNT / 2); i++) {
        leds[LED_COUNT - i] = leds[i];
      }
    }

    void setLED(uint8_t idx, CRGB color) {
      leds[idx] = color;
    }

    void setLEDs(CRGB color) {
      setLEDs(color, 0, LED_COUNT);
    }

    void setLEDs(CRGB color, uint8_t from, uint8_t to) {
      for (uint8_t i = from; i < to; i++) {
        setLED(i, color);
      }
    }

    void setBrightness(uint8_t new_brightness) {
      brightness = new_brightness;
      LEDS.setBrightness(brightness);
    }

    /// Applies current LED array status and brightness
    void apply() {
      LEDS.show();
    }

    uint8_t brightness;
    struct CRGB leds[LED_COUNT];
};
