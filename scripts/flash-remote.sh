#!/bin/sh
DEVICE_PATH=/dev/ttyUSB0
DIST_FOLDER=dist
FQBN=arduino:avr:nano:cpu=atmega328old

ssh lightstrip "rm -rf $DIST_FOLDER"
scp -r "$DIST_FOLDER" "lightstrip:$DIST_FOLDER"
ssh lightstrip "
sudo service light-server stop
arduino-cli upload --input-dir $DIST_FOLDER -p $DEVICE_PATH --fqbn $FQBN
sudo service light-server start
"
