# Arduino Joystick Remote Control
Generic Remote Control. This is used to control my RC OmniWhell Car.

## BOM
- Arduino Uno R3
- HC-12 RF Wireless Module
- Arduino Joystick Shield
- 9V Battery
- 9V Battery Adaptor
- Switch Button
- 3D Printed Case
- 3D Printed Cover

## Required Libraries
- featherfly/SoftwareSerial@^1.0
- madleech/Button@^1.0.0

## Issues
- Due to Button Deboucing, some consecutive presses might not be triggered. This could be solved by either using another button/deboucing library or tweaking the current code.

## Schematic
![](https://github.com/lucasltt/ArduJoystick/raw/master/img/diagram.jpg)
