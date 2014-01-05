REFERENCE
=========

__```ESC::ESC()```__

Creates a new ESC object and sets default values for control input range and servo output range.

__```ESC::~ESC()```__

Stops the ESC and detaches the wrapped Servo object.

__```void ESC::attach(int pin)```__

Attaches the wrapped Servo object to ```pin```.

__```int ESC::speed([int speed])```__

Optionally sets and returns a new ESC speed.

__```int ESC::stop()```__

Equivalent of ```ESC::speed(0)```.

__```int ESC::read()```__

Returns the servo output value by calling ```Servo::read()``` on the wrapped Servo object.

__```int ESC::control_min([int control_min])```__

Optionally sets and returns the minimum input value, i.e. the input value to be passed to ```ESC::speed(int)``` which corresponds to zero throttle.

__```int ESC::control_max([int control_max])```__

Optionally sets and returns the maximum input value, i.e. the input value to be passed to ```ESC::speed(int)``` which corresponds to full throttle.

__```int ESC::servo_min([int servo_min])```__

Optionally sets and returns the minimum servo output value, i.e. the value passed to ```Servo::write(int)``` on the wrapped Servo object for zero throttle.

__```int ESC::servo_max([int servo_max])```__

Optionally sets and returns the maximum servo output value, i.e. the value passed to ```Servo::write(int)``` on the wrapped Servo object for full throttle.
