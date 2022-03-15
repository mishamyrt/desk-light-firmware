#include "Arduino.h"

extern uint8_t start_color[3];
extern uint8_t target_color[3];
extern uint8_t target_brightness;

int step_to_target(uint8_t target, uint8_t *current, int step, bool stop);

void color_fill_transition(bool from_center);
void smooth_brightness_transition();
void color_tween_transition();
