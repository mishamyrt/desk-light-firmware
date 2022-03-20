#pragma once

#include "Arduino.h"
#include "FastLED.h"

class Effect {
public:
  virtual void draw() = 0;
  virtual void prepare() = 0;
  // Equals zero if animation is infinite
  virtual uint8_t stepCount() = 0;
  virtual uint8_t stepDelay() = 0;
};

inline uint8_t blend_values(uint8_t first, uint8_t second, float ratio) {
  return (second * ratio) + (first * (1 - ratio));
}

inline CRGB blend_rgb(CRGB first, CRGB second, float ratio) {
  return CRGB(
    blend_values(first.red, second.red, ratio),
    blend_values(first.green, second.green, ratio),
    blend_values(first.blue, second.blue, ratio)
  );
}

extern float progress;
extern uint8_t step;
extern uint8_t delta;
extern uint8_t current_effect;
