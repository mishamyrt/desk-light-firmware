#include "Arduino.h"
#include "FastLED.h"
#include "../../light/light.h"

void handle_power_on(uint8_t *message, uint8_t message_length) {
  if (message_length < 5) {
    // TODO: Throw error
    return;
  }
  Light.setLEDs(CRGB(
    message[1],
    message[2],
    message[3]
  ));
  Light.apply();
}

void handle_power_off() {
  Light.setLEDs(CRGB::Black);
  Light.apply();
}
