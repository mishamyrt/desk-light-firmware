#include "FastLED.h"
#include "lightstrip.h"
#include "src/api/input.h"
#include "src/effects/handler.h"
#include "src/effects/helpers.h"
#include "src/light/hardware.h"

#define BOUD_RATE 2000000
#define INPUT_TIMEOUT 50

int payload_length = 0;
int previous_payload_length = 0;
int input_index = 0;

void send(int data) {
  Serial.println(data);
}

void send_log(rgb_color payload) {
  Serial.println(101010);
  for (int i = 0; i < 3; i++) {
    Serial.print(payload[i]);
    Serial.print(" ");
  }
  Serial.print('\n');
}

void send_log(int payload) {
  Serial.println(101010);
  Serial.println(payload);
}

void send_log(char* data) {
  Serial.println(101010);
  Serial.println(data);
}

void setup() {
  Serial.begin(BOUD_RATE);
  Serial.setTimeout(INPUT_TIMEOUT);
  initialize_hardware();
  send(1);
}

void loop() {
  if (Serial.available() > 0) {
    payload_length = Serial.readBytes(input_buffer, 48);
    handle_input(payload_length);
  }
  handle_frame();
}
