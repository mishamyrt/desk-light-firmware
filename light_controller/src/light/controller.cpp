#include "light.h"
#include "Arduino.h"
#include "FastLED.h"

void LightController::initialize() {
  LEDS
    .addLeds<WS2811, LED_DT, GRB>(leds, LED_COUNT)
    .setCorrection(0xFF8C8C); // 255, 140, 140
  setLEDs(CRGB::Black);
  apply();
}

void LightController::apply() {
  LEDS.show();
}

void LightController::setLEDs(CRGB color) {
  for (int i = 0; i < LED_COUNT; i++) {
    leds[i] = color;
  }
}

void LightController::setLED(uint8_t idx, CRGB color) {
  leds[idx] = color;
}
