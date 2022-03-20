#pragma once

#include "Arduino.h"
#include "config.h"

/*
  Message structure:
  0xFE 0xEF $N $D(N times) $checksum
 */

class Dap_ {
public:
  void connect() {
    Serial.begin(BOUD_RATE);
    Serial.setTimeout(INPUT_TIMEOUT);
    sendSuccess();
  };
  void handleInput();
  void registerHandler(void (*handler)(uint8_t *message, uint8_t message_length));

  uint8_t message_buffer[INPUT_BUFFER_SIZE];
  uint8_t message_length;

private:
  void (*message_handler)(uint8_t *message, uint8_t message_length);
  bool moveToMessage();
  void sendError();
  void sendSuccess();
  void sendCode(uint8_t code);
  void readMessage();
  uint8_t calculateChecksum();

  enum {
    CODE_SUCCESS = 0,
    CODE_ERROR = 1
  };
};

extern Dap_ Dap;
