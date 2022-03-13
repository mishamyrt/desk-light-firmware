#include <Arduino.h>
#include "helpers.h"

#define AMBILIGHT_ZONES_MAX 24

typedef struct ambilight_zone {
  int index_from;
  int index_to;
  rgb_color target_color;
  rgb_color previous_color;
  rgb_color color;
};

extern ambilight_zone zones[AMBILIGHT_ZONES_MAX];
extern uint8_t zones_count;
extern bool is_inverted;
