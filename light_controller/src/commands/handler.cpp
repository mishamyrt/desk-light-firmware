#include "Arduino.h"
#include "commands.h"

void handle_command(uint8_t *command, uint8_t command_length) {
  switch (command[0]) {
    case COMMAND_POWER_ON:
      handle_power_on(command, command_length);
      break;
    case COMMAND_POWER_OFF:
      handle_power_off();
      break;
    case COMMAND_SET_COLOR:
      handle_set_color(command, command_length);
      break;
    case COMMAND_SET_COLOR_ZONES:
      handle_set_color_zones(command, command_length);
      break;
    default:
      break;
  }
}
