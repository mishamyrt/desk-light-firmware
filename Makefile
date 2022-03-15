.PHONY: compile

DEVICE_PATH = /dev/tty.wchusbserial11440
PROJECT_NAME = DeskLight
FQBN = arduino:avr:nano:cpu=atmega328old

compile:
	cd ws2812_controller && \
	arduino-cli compile --fqbn $(FQBN) $(PROJECT_NAME)
flash:
	cd ws2812_controller && \
	arduino-cli upload -p $(DEVICE_PATH) --fqbn $(FQBN) $(PROJECT_NAME)
flash-remote:
	sh -c scripts/flash-remote.sh
