ArduinoESCLib
=============

An Arduino library for controlling ESCs

Allows easy interfacing to Electronics Speed Controllers for brushless motors using the Arduino [Servo](http://arduino.cc/en/reference/servo) library.

Installation
------------

1.  Obtain a copy of this repository by your preferred means (clone, Zip archive)
2.  Copy the ```ESC``` folder to your Arduino libraries folder

Usage
-----

See full [reference](https://github.com/DanNixon/ArduinoESCLib/blob/master/REFERENCE.md).

By default the library accepts a value for speed between 0 and 100 and will output a servo timing value between 700us and 2500us, these values can be changed with the appropriate functions described in the reference (the default values can be changed in ```ESC.h```).

It may take a little trial and error to find values wich work perfectly with a given ESC, however since most ESCs have the ability to set the throttle range then the default servo output range should work in most cases.

The ability to change the control range is simply there for convinience and can be changed to best meet the needs of your application, note that a wider input range (hence more integer values) will not necessarily give you finer motor control.

There is an examples showing basic usage of the library and a sample for configuring thr throttle range automatically (I have kept this a seperate sketch from the library as I am unsure of how well it works on other ESCs, any utility I put into the library I want to be sure will work on the majority of controllers).
