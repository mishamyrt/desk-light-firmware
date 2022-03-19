#include "dap.h"
#include "Arduino.h"
#include "config.h"

const uint8_t MESSAGE_HEADER_FIRST = 0xFE;
const uint8_t MESSAGE_HEADER_SECOND = 0xEF;
const uint8_t MESSAGE_HEADER[2] = { 0xFE, 0xEF };

void Dap_::handleInput() {
    if (Serial.available() > 0) {
      readMessage();
    }
}

bool Dap_::moveToMessage() {
  uint8_t cur;
  uint8_t index = 0;
  bool looks_like_message = false;

  while(index < INPUT_BUFFER_SIZE) {
    cur = Serial.read();
    switch (cur) {
      case -1:
        return false;
        break;
      case MESSAGE_HEADER_FIRST:
        looks_like_message = true;
        break;
      case MESSAGE_HEADER_SECOND:
        if (looks_like_message) {
          return true;
        }
        looks_like_message = false;
        break;
      default:
        looks_like_message = false;
        break;
    }
    index++;
  }
}

void Dap_::registerHandler(void (*handler)(uint8_t *message, uint8_t message_length)) {
  message_handler = handler;
}

void Dap_::sendError() {
  sendCode(CODE_ERROR);
}

void Dap_::sendSuccess() {
  sendCode(CODE_SUCCESS);
}

void Dap_::sendCode(uint8_t code) {
  Serial.write(MESSAGE_HEADER_FIRST); // Header
  Serial.write(MESSAGE_HEADER_SECOND);
  Serial.write(1); // Length
  Serial.write(code); // Payload
  Serial.write(code); // Checksum
}

void Dap_::readMessage() {
  bool messageFound = moveToMessage();
  if (!messageFound) {
    sendError();
    return;
  }
  message_length = Serial.read();
  if (message_length > INPUT_BUFFER_SIZE || message_length <= 0) {
    sendError();
    return;
  }
  uint8_t index = 0;
  uint8_t cur;
  while (index < message_length) {
    cur = Serial.read();
    if (cur == -1) {
      sendError();
      return;
    }
    message_buffer[index] = cur;
    index++;
  }
  cur = Serial.read();
  if (cur == -1) {
    sendError();
    return;
  }
  uint8_t check = calculateChecksum();
  if (check != cur) {
    sendError();
    return;
  }
  message_handler(message_buffer, message_length);
  sendSuccess();
  return;
}

uint8_t Dap_::calculateChecksum() {
  int checksum = 0;
  for (uint8_t i = 0; i < message_length; i++) {
    checksum += message_buffer[i];
    if (checksum > 255) {
      checksum -= 255;
    }
  }
  return checksum;
}

Dap_ Dap;
