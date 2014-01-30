REFERENCE
=========

__```ESC::ESC()```__

Creates a new ESC object and sets default values for control input range and servo output range.

__```ESC::~ESC()```__

Stops the ESC and detaches the wrapped Servo object.

__```void ESC::attach(int pin)```__

Attaches the wrapped Servo object to ```pin```.

__```int ESC::arm([int armed])```__

Optionally arms or disarms the ESC and returned the armed state.  
Note that this only affects calls to ```speed(int)```, hence eill not protect against direct control of the ESC pin.

__```int ESC::speed([int speed])```__

Optionally sets and returns a new ESC speed.

__```int ESC::stop()```__

Equivalent of ```ESC::speed(0)```.

__```int ESC::read()```__

Returns the servo output value by calling ```Servo::read()``` on the wrapped Servo object.

__```int ESC::read_microseconds()```__

Returns the servo output timing in microseconds.

__```int ESC::control_min([int control_min])```__

Default: 0  
Optionally sets and returns the minimum input value, i.e. the input value to be passed to ```ESC::speed(int)``` which corresponds to zero throttle.  
This can be set to a value most appopriate for the application.  

__```int ESC::control_max([int control_max])```__

Default: 100  
Optionally sets and returns the maximum input value, i.e. the input value to be passed to ```ESC::speed(int)``` which corresponds to full throttle.  
This can be set to a value most appopriate for the application.

__```int ESC::output_min([int servo_min])```__

Default: 700  
Optionally sets and returns the minimum servo output timing value in microseconds, i.e. the value passed to ```Servo::writeMicroseconds(int)``` on the wrapped Servo object for zero throttle (usually best close to zero).

__```int ESC::output_max([int servo_max])```__

Default: 2500  
Optionally sets and returns the maximum servo output timing value in microseconds, i.e. the value passed to ```Servo::writeMicroseconds(int)``` on the wrapped Servo object for full throttle (usually best close to 180).
