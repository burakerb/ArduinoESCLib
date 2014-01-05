REFERENCE
=========

ESC::ESC()
----------

Creates a new ESC object and sets default values for control input range and servo output range.

ESC::~ESC()
----------

Stops the ESC and detaches the wrapped Servo object.

void ESC::attach(int pin)
-------------------------

Attaches the wrapped Servo object to ```pin```.

int ESC::speed([int speed])
---------------------------

Optionally sets and returns a new ESC speed.

int ESC::stop()
---------------

Equivalent of ```ESC::speed(0)```.

int ESC::read()
---------------

Returns the servo output value by calling ```Servo::read()``` on the wrapped Servo object.

int ESC::control_min([int control_min])
---------------------------------------

Optionally sets and returns the minimum input value, i.e. the input value to be passed to ```ESC::speed(int)``` which corresponds to zero throttle.

int ESC::control_max([int control_max])
---------------------------------------

Optionally sets and returns the maximum input value, i.e. the input value to be passed to ```ESC::speed(int)``` which corresponds to full throttle.

int ESC::servo_min([int servo_min])
-----------------------------------

Optionally sets and returns the minimum servo output value, i.e. the value passed to ```Servo::write(int)``` on the wrapped Servo object for zero throttle.

int ESC::servo_max([int servo_max])
-----------------------------------

Optionally sets and returns the maximum servo output value, i.e. the value passed to ```Servo::write(int)``` on the wrapped Servo object for full throttle.
