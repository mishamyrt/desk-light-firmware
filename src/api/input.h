#include <Arduino.h>
// 128 for command, 1 for terminator
#define INPUT_BUFFER_SIZE 129
#define INPUT_TERMINATOR 0x1337

void handle_input(int length);
extern uint8_t input_buffer[INPUT_BUFFER_SIZE];
