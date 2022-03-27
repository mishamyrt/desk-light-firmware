.PHONY: compile

DEVICE_PATH = /dev/tty.wchusbserial11440
OUT_PATH = dist
SRC_PATH = light_controller
PROJECT_NAME = DeskLight
FQBN = GyverCore:avr:nano:serial=gyverUart
AC = arduino-cli --config-file config.json

compile:
	cd $(SRC_PATH) && \
	$(AC) compile \
		--output-dir ../$(OUT_PATH) \
		--fqbn $(FQBN) \
		$(PROJECT_NAME)
flash:
	cd $(SRC_PATH) && \
	$(AC) upload -p $(DEVICE_PATH) --fqbn $(FQBN) $(PROJECT_NAME)
flash-remote:
	sh -c scripts/flash-remote.sh
setup:
	$(AC) core update-index
	$(AC) core install GyverCore:avr
	$(AC) core install arduino:avr
	$(AC) lib install FastLED
