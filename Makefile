.PHONY: compile

DEVICE_PATH = /dev/tty.wchusbserial11440
PROJECT_NAME = DeskLight
FQBN = arduino:avr:nano:cpu=atmega328old

compile:
	arduino-cli compile --fqbn $(FQBN) $(PROJECT_NAME)
flash:
	arduino-cli upload -p $(DEVICE_PATH) --fqbn $(FQBN) $(PROJECT_NAME)
