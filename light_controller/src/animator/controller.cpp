#include "controller.h"
#include "effects.h"
#include "../light/controller.h"

uint8_t current_effect = 0;

void EffectsController::initialize() {
  Crossfade.zones[0].idx_from = 0;
  Crossfade.zones[0].idx_to = LED_COUNT - 1;
  Crossfade.zones_count = 1;
}

void EffectsController::stopEffect() {
  current_effect = EFFECT_NONE;
}

void EffectsController::handleFrame() {
  switch (current_effect) {
    case EFFECT_CROSSFADE:
      Crossfade.draw();
      break;
    default:
      stopEffect();
      break;
  }
}

EffectsController Animator;

