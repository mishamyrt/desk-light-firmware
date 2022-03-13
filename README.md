# Desk Light Firmware

Firmware for Arduino Nano which implements smart strip functions controlled via USB. Used to light my desk.

## Setup

To get started, you need to install this firmware on your Arduino. To do this, run the commands in the project folder:

```
make compile
make flash
```

## Сonnection

The serial port is used to communicate with the control device. The connection speed is 9600 baud.

## Commands

The unit receives commands over the serial port as a sequence of integers. The first value is the command, followed by the arguments. The available commands are listed in the [commands.h](src/api/commands.h) file.  Some of the commands can change the read mode and after the command is executed the reception of commands will stop until a special command is received.

The command and argument list must be followed by the ending number 4919 or `0x1337`. Important: The command arguments must not contain this number, otherwise the device will consider it an end character and will abort the reading.

### Examples

Enable light strip.

```
0x1 0xBEE
```

Set brightness to 50%.

```
0x2 0x80 0xBEE
```

Set color to red.

```
0x3 0xFF 0x0 0x0 0xBEE
```
