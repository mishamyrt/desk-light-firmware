#include <Arduino.h>

typedef uint8_t rgb_color[3];

uint8_t calculate_middle_value(uint8_t first, uint8_t second, float ratio);
void copy_colors(uint8_t* target, rgb_color source);
bool is_same_color (rgb_color first, rgb_color second);
