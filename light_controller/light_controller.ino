#include "src/dap/dap.h"
#include "src/light/light.h"
#include "src/commands/handler.h"

void setup() {
  Dap.connect();
  Dap.registerHandler(handle_command);
  Light.initialize();
}

void loop() {
  Dap.handleInput();
}
