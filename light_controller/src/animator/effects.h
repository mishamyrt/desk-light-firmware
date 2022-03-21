#pragma once

#include "Arduino.h"
#include "controller.h"
#include "effects/crossfade.h"
#include "effects/rainbow.h"

/// The class that controls all strip animations
extern EffectsController Animator;

// Available effects
extern CrossfadeEffect Crossfade;
extern RainbowEffect Rainbow;
