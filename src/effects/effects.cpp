#include "../../lightstrip.h"
#include "effects.h"

int LED_CENTER = int(LED_COUNT / 2);
int effect = EFFECT_NONE;
int index;

void start_effect(int new_effect) {
  index = 0;
  effect = new_effect;
}

void stop_effect() {
  effect = EFFECT_NONE;
}
