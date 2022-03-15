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

### Examples

Enable light strip.

```
0x1
```

Set color to white and brightness to 50%.

```
0x3 0xFF 0xFF 0xFF 0x80
```

Set color to red and brightness to 100%.

```
0x3 0xFF 0x0 0x0 0xFF
```
