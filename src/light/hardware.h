#include "FastLED.h"
#include "../../lightstrip.h"

extern uint8_t brightness;
extern struct CRGB leds[LED_COUNT];

void set_brightness(uint8_t new_brightness);
void apply();
void fill_leds(uint8_t r, uint8_t g, uint8_t b);
void initialize_hardware();
