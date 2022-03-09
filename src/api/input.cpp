#include "FastLED.h"
#include "commands.h"
#include "../light/api.h"
#include "../light/hardware.h"
#include "../../lightstrip.h"

uint8_t input_buffer[100];

void handle_input(int length) {
  switch (input_buffer[0])
  {
    case COMMAND_POWER_OFF:
      apply_power(false);
      break;
    case COMMAND_POWER_ON:
      apply_power(true);
      break;
    case COMMAND_SET_BRIGHTNESS:
      apply_brightness(input_buffer[1]);
      break;
    case COMMAND_SET_COLOR:
      apply_color(input_buffer[1], input_buffer[2], input_buffer[3]);
      break;
  }
}

