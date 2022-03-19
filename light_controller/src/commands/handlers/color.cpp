#include "Arduino.h"
#include "FastLED.h"
#include "../../light/light.h"

// Message format: [cmd, r, g, b, brightness]

void handle_set_color(uint8_t *message, uint8_t message_length) {
  if (message_length < 5) {
    // TODO: Throw error
    return;
  }
  Light.setLEDs(CRGB(
    message[1],
    message[2],
    message[3]
  ));
  Light.brightness = message[4];
  Light.apply();
}
