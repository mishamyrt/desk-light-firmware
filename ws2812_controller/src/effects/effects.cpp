#include <Arduino.h>
#include "../../lightstrip.h"
#include "effects.h"

int LED_CENTER = int(LED_COUNT / 2);
uint8_t effect = EFFECT_NONE;
int index;
int effect_index;
float progress;

void start_effect(uint8_t new_effect) {
  index = 0;
  progress = 0;
  effect = new_effect;
}

void stop_effect() {
  effect = EFFECT_NONE;
}
