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
        .setCorrection(0xFF8C8C); // 255, 140, 140
      setLEDs(CRGB::Black);
      apply();
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

    /// Applies current LED array status and brightness
    void apply() {
      LEDS.setBrightness(brightness);
      LEDS.show();
    };

    uint8_t brightness;

  private:
    struct CRGB leds[LED_COUNT];
};
