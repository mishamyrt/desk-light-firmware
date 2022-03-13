#include "src/effects/helpers.h"

#define LED_COUNT 120
#define LED_DT 13

void send(int payload);
void send_log(int payload);
void send_log(char* payload);
void send_log(rgb_color payload);
