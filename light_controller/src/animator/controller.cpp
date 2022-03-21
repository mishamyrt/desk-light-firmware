#include "controller.h"
#include "effects.h"

void EffectsController::initialize() {
  Crossfade.zones[0].from = 0;
  Crossfade.zones[0].to = LED_COUNT;
  Crossfade.zones_count = 1;
}
