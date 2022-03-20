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
    };
    void setLED(uint8_t idx, CRGB color) {
      leds[idx] = color;
    };
    void setLEDFromEnd(uint8_t idx, CRGB color) {
      leds[LED_COUNT - idx] = color;
    };
    void setLEDs(CRGB color) {
      for (int i = 0; i < LED_COUNT; i++) {
        leds[i] = color;
      }
    };
    // void setZoneLEDs(CRGB color);
    void apply() {
      LEDS.show();
    };

    // struct Zone zones[MAX_ZONES_COUNT];
    uint8_t brightness;

  private:
    struct CRGB leds[LED_COUNT];
};
