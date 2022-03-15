#include "FastLED.h"
#include "commands.h"
#include "ambilight.h"
#include "input.h"
#include "../light/api.h"
#include "../light/hardware.h"
#include "../../lightstrip.h"
#include "../effects/effects.h"
#include "../effects/animation.h"

uint8_t input_buffer[INPUT_BUFFER_SIZE];

void handle_input(int length) {
  // send_log(input_buffer[0]);
  switch (input_buffer[0])
  {
    case COMMAND_POWER_OFF:
      apply_power(false);
      break;
    case COMMAND_POWER_ON:
      color[0] = input_buffer[1];
      color[1] = input_buffer[2];
      color[2] = input_buffer[3];
      apply_power(true);
      break;
    case COMMAND_SET_BRIGHTNESS:
      apply_brightness(input_buffer[1]);
      break;
    case COMMAND_SET_COLOR:
      apply_color(input_buffer[1], input_buffer[2], input_buffer[3]);
      break;
    case COMMAND_START_AMBILIGHT:
      parse_ambilight_zones();
      break;
    case COMMAND_SET_AMBILIGHT_COLOR:
      parse_ambilight_colors(length - 1);
      start_effect(EFFECT_AMBILIGHT);
      apply_ambilight_colors();
      break;
    case COMMAND_STOP_ANIMATION:
      stop_effect();
      break;
  }
}

// COMMAND_AMBILIGHT invert zones_count {start_index count}
// 4 1 3 0 40 41 40 81 40

