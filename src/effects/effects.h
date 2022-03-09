extern int effect;
extern int index;

void stop_effect();
void start_effect(int new_effect);

#define EFFECT_NONE 0
#define EFFECT_FILL_FROM_CENTER 1
#define EFFECT_FILL_TO_CENTER 2
#define EFFECT_SMOOTH_BRIGHTNESS 3
#define EFFECT_COLOR_TWEEN 4
