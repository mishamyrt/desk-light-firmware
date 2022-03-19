#pragma once

#include "Arduino.h"
#include "FastLED.h"

#define LED_DT 13
#define LED_COUNT 120
#define MAX_ZONES_COUNT 24

typedef struct Zone {
  uint8_t length;
  uint8_t start;
  bool reverse;
};

class LightController {
  public:
    void initialize();
    void setLED(uint8_t idx, CRGB color);
    void setLEDs(CRGB color);
    // void setZoneLEDs(CRGB color);
    void apply();

    // struct Zone zones[MAX_ZONES_COUNT];
    uint8_t brightness;

  private:
    CRGB current_color;
    struct CRGB leds[LED_COUNT];
};
