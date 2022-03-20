#include "src/dap/dap.h"
#include "src/light/light.h"
#include "src/commands/handler.h"
#include "src/animator/controller.h"
#include "src/animator/controller.h"

void setup() {
  Dap.connect();
  Dap.registerHandler(handle_command);
  Light.initialize();
  Animator.initialize();
}

void loop() {
  Dap.handleInput();
  Animator.handleFrame();
}
