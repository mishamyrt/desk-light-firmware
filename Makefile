.PHONY: compile

DEVICE_PATH = /dev/tty.wchusbserial11440
OUT_PATH = dist
SRC_PATH = light_controller
PROJECT_NAME = DeskLight
FQBN = GyverCore:avr:nano:serial=gyverUart

compile:
	cd $(SRC_PATH) && \
	arduino-cli compile \
		--output-dir ../$(OUT_PATH) \
		--fqbn $(FQBN) \
		$(PROJECT_NAME)
flash:
	cd $(SRC_PATH) && \
	arduino-cli upload -p $(DEVICE_PATH) --fqbn $(FQBN) $(PROJECT_NAME)
flash-remote:
	sh -c scripts/flash-remote.sh
