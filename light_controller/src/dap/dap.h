#pragma once

#include "Arduino.h"
#include "config.h"

#define MESSAGE_HEADER_FIRST 0xFE
#define MESSAGE_HEADER_SECOND 0xEF

/*
  Message structure:
  0xFE 0xEF $N $D(N times) $checksum
 */

class DapConnector {
public:
  void connect() {
    Serial.begin(BOUD_RATE);
    Serial.setTimeout(INPUT_TIMEOUT);
    sendSuccess();
  }

  void handleInput() {
    if (Serial.available() > 4) {
      // Parse message
      if (!readMessage()) {
        sendError();
        return;
      }
      // Run message handler
      if (message_handler(message_buffer, message_length)) {
        sendSuccess();
      } else {
        sendError();
      }
    }
  }

  void registerHandler(bool (*handler)(uint8_t *m, uint8_t l)) {
    message_handler = handler;
  }

private:
  void sendError() {
    sendCode(CODE_ERROR);
  }

  void sendSuccess() {
    sendCode(CODE_SUCCESS);
  }

  void sendCode(uint8_t code) {
    Serial.write(MESSAGE_HEADER_FIRST); // Header
    Serial.write(MESSAGE_HEADER_SECOND);
    Serial.write(1); // Length
    Serial.write(code); // Payload
    Serial.write(code); // Checksum. For single number messages will equal the code
  }

  uint8_t calculateChecksum() {
    int checksum = 0;
    for (uint8_t i = 0; i < message_length; i++) {
      checksum += message_buffer[i];
      if (checksum > 255) {
        checksum -= 255;
      }
    }
    return checksum;
  }

  /// Searches the message start sequence ([0xFE, 0xEF]) in the input buffer.
  bool findStartSequence() {
    while(true) {
      current_value = Serial.read();
      if (current_value == MESSAGE_HEADER_SECOND && previous_value == MESSAGE_HEADER_FIRST) {
        return true;
      } else if (current_value == -1) {
        return false;
      }
      previous_value = current_value;
    }
  }

  /// Reads the input buffer until it finds a header. Returns a flag that says whether the header was read successfully.
  /// Header structure: [0xFE, 0xEF, $message_length]. Message length must be greater than zero and less than the input buffer size.
  bool readHeader() {
    if (!findStartSequence()) {
      return false;
    }
    message_length = Serial.read();
    if (message_length > INPUT_BUFFER_SIZE || message_length <= 0) {
      return false;
    }
    return true;
  }

  /// Reads the body of the message and writes it to the buffer
  bool readBody() {
    index = 0;
    while (index < message_length) {
      current_value = Serial.read();
      if (current_value == -1) {
        return false;
      }
      message_buffer[index] = current_value;
      index++;
    }
    return true;
  }

  /// Reads the last byte of the message and checks that it contains the correct checksum
  bool checkMessage() {
    current_value = Serial.read();
    if (current_value == -1 || calculateChecksum() != current_value) {
      return false;
    }
    return true;
  }

  bool readMessage() {
    if (!readHeader()) {
      return false;
    }
    if (!readBody()) {
      return false;
    }
    if (!checkMessage()) {
      return false;
    }
    return true;
  }

  bool (*message_handler)(uint8_t *message, uint8_t message_length);
  uint8_t index;
  uint8_t current_value;
  uint8_t previous_value;
  uint8_t message_buffer[INPUT_BUFFER_SIZE];
  uint8_t message_length;
  enum {
    CODE_SUCCESS = 0xEE,
    CODE_ERROR = 0xFF
  };
};

extern DapConnector Dap;
