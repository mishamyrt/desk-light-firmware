#include "FastLED.h"
#include "lightstrip.h"
#include "src/api/input.h"
#include "src/effects/handler.h"
#include "src/light/hardware.h"

int payload_length = 0;

void send(int data) {
  Serial.println(data);
}

int recieve() {
  while (!Serial.available());
  return Serial.parseInt();
}

void send_log(int payload) {
  Serial.println(101010);
  delay(10);
  Serial.println(payload);
}

void setup() {
  Serial.begin(9600);
  initialize_hardware();
  send(1);
}

void loop() {
  if (Serial.available() > 0) {
    payload_length = Serial.readBytesUntil(0x256, input_buffer, sizeof(input_buffer) - 1);
    handle_input(payload_length);
  }
  handle_frame();
}
