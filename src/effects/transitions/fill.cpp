#include "FastLED.h"
#include "../effects.h"
#include "transitions.h"
#include "../../light/hardware.h"
#include "../../light/api.h"

extern int LED_CENTER;

/**
 * Fills strip with colors from or to center
 */
void color_fill_transition(bool from_center) {
  if (index > LED_CENTER) {
    color[0] = target_color[0];
    color[1] = target_color[1];
    color[2] = target_color[2];
    stop_effect();
  }
  CRGB rgb = CRGB(target_color[0], target_color[1], target_color[2]);
  if (from_center) {
    leds[LED_CENTER + index] = rgb;
    leds[LED_CENTER - index - 1] = rgb;
  } else {
    leds[index] = rgb;
    leds[LED_COUNT - index] = rgb;
  }
  index++;
  apply();
  delay(5);
}
