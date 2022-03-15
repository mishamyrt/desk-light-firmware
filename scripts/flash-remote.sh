#!/bin/sh
DEVICE_PATH=/dev/ttyUSB0
SOURCE_FOLDER=ws2812_controller
FQBN=arduino:avr:nano:cpu=atmega328old

ssh lightstrip "rm -rf $SOURCE_FOLDER"
scp -r "$SOURCE_FOLDER" "lightstrip:$SOURCE_FOLDER"
ssh lightstrip "
cd $SOURCE_FOLDER
arduino-cli compile --fqbn $FQBN $SOURCE_FOLDER
sudo service light-server stop
arduino-cli upload -p $DEVICE_PATH --fqbn $FQBN $SOURCE_FOLDER
sudo service light-server start
"
