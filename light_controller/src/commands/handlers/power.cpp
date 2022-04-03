#include "Arduino.h"
#include "FastLED.h"
#include "../../animator/effects.h"

bool handle_power_on(uint8_t *message, uint8_t message_length) {
  if (message_length < 4) {
    return false;
  }
  Crossfade.resetZones();
  Crossfade.setNextColor(0, CRGB(
    message[1],
    message[2],
    message[3]
  ));
  Animator.startEffect(Crossfade);
  return true;
}

void handle_power_off() {
  Crossfade.resetZones();
  Crossfade.setNextColor(0, CRGB::Black);
  Animator.startEffect(Crossfade);
}
