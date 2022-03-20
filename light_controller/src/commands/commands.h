#pragma once

#include "Arduino.h"

#define COMMAND_POWER_OFF 0
bool handle_power_off();

#define COMMAND_POWER_ON 1
bool handle_power_on(uint8_t *message, uint8_t message_length);

#define COMMAND_SET_COLOR 2
bool handle_set_color(uint8_t *message, uint8_t message_length);

#define COMMAND_SET_COLOR_ZONES 3
bool handle_set_color_zones(uint8_t *message, uint8_t message_length);

#define COMMAND_START_EFFECT 4
bool handle_start_effect(uint8_t *message, uint8_t message_length) ;
