#include "FastLED.h"
#include "hardware.h"
#include "../../lightstrip.h"

struct CRGB leds[LED_COUNT];
uint8_t brightness = 128;

void apply() {
  LEDS.setBrightness(brightness);
  LEDS.show();
}

void fill_leds(uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 0; i < LED_COUNT; i++) {
    leds[i].setRGB(r, g, b);
  }
}

void initialize_hardware() {
  LEDS
    .addLeds<WS2811, LED_DT, GRB>(leds, LED_COUNT)
    .setCorrection(0xFF8C8C); // 255, 140, 140
  fill_leds(0, 0, 0);
  apply();
}
