#!/bin/sh

# User defined constants
SSH_HOST="lightstrip"
DEVICE_PATH="/dev/ttyUSB0"
FIRMWARE_PATH="./dist/light_controller.ino.with_bootloader.hex"
FQBN="arduino:avr:nano:cpu=atmega328old"

# Internal constant
FIRMWARE_NAME="$(basename $FIRMWARE_PATH)"

# Action
echo "Creating temporary directory"
TEMP_DIR="$(ssh $SSH_HOST mktemp -d)"
REMOTE_FIRMWARE_PATH="$TEMP_DIR/$FIRMWARE_NAME"
echo "Sending firmware"
scp "$FIRMWARE_PATH" "$SSH_HOST:$REMOTE_FIRMWARE_PATH"
ssh $SSH_HOST "
echo 'Stopping server'
sudo service light-server stop
echo 'Flashing firmware'
arduino-cli upload -t -i $REMOTE_FIRMWARE_PATH -p $DEVICE_PATH -b $FQBN
echo 'Starting server'
sudo service light-server start
echo 'Cleaning up'
rm -rf $TEMP_DIR
echo 'Done ☺️'
"
