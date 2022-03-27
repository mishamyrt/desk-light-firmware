# Desk Light Firmware [![Build](https://github.com/mishamyrt/desk-light-firmware/actions/workflows/build.yaml/badge.svg)](https://github.com/mishamyrt/desk-light-firmware/actions/workflows/build.yaml)

Firmware for Arduino Nano which implements smart strip functions controlled via USB. Used to light my desk.

## Setup

To get started, you need to install this firmware on your Arduino. To do this, run the commands in the project folder:

```
make compile
make flash
```

## Communication

For communication, the [Dap](./light_controller/src/dap/) is used.

## Commands

The available commands and their codes are described in the file [commands.h](./light_controller/src/commands/commands.h).

## Effects

The available effects and their codes are described in the file [effects.h](./light_controller/src/animator/effects.h).
