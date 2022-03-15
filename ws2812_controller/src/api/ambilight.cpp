#include <Arduino.h>
#include "input.h"
#include "../light/api.h"
#include "../effects/animation.h"
#include "../../lightstrip.h"
#include "../effects/helpers.h"

int buffer_index;

// COMMAND_AMBILIGHT is_inverted zones_count {index_from index_to}
void parse_ambilight_zones() {
  buffer_index = 3;
  is_inverted = input_buffer[1];
  zones_count = input_buffer[2];
  for (uint8_t i = 0; i < zones_count; i++) {
    zones[i].index_from = input_buffer[buffer_index++];
    zones[i].index_to = input_buffer[buffer_index++];
  }
}

// COMMAND_SET_AMBILIGHT_COLOR {r g b}
void parse_ambilight_colors(int length) {
  if (length != zones_count * 3) {
    return;
  }
  buffer_index = 1;
  for (int i = 0; i < zones_count; i++) {
    copy_colors(zones[i].previous_color, zones[i].color);
    zones[i].target_color[0] = input_buffer[buffer_index++];
    zones[i].target_color[1] = input_buffer[buffer_index++];
    zones[i].target_color[2] = input_buffer[buffer_index++];
    // send_log("new_color");
    // send_log(i);
    // send_log(zones[i].target_color);
  }
}
