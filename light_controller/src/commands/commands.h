#pragma once

#include "Arduino.h"

#define COMMAND_POWER_OFF 0
inline void handle_power_off();

#define COMMAND_POWER_ON 1
inline void handle_power_on(uint8_t *message, uint8_t message_length);

#define COMMAND_SET_COLOR 2
inline void handle_set_color(uint8_t *message, uint8_t message_length);
