#include "Arduino.h"
#include "commands.h"

bool handle_command(uint8_t *command, uint8_t command_length) {
  switch (command[0]) {
    case COMMAND_POWER_ON:
      return handle_power_on(command, command_length);
    case COMMAND_POWER_OFF:
      return handle_power_off();
    case COMMAND_SET_COLOR:
      return handle_set_color(command, command_length);
    case COMMAND_SET_COLOR_ZONES:
      return handle_set_color_zones(command, command_length);
    case COMMAND_START_EFFECT:
      return handle_start_effect(command, command_length);
    case COMMAND_SET_TEMPERATURE:
      return handle_set_temperature(command, command_length);
    default:
      break;
  }
}
