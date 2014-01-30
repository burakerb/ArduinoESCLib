/*
 * Arduino ESC library
 * Dan Nixon
 * 05/01/2014
 * http://dan-nixon.com
 */

#include "ESC.h"

ESC::ESC()
{
  this->i_control_min = DEFAULT_CONTROL_MIN;
  this->i_control_max = DEFAULT_CONTROL_MAX;
  this->i_servo_min = DEFAULT_SERVO_MIN;
  this->i_servo_max = DEFAULT_SERVO_MAX;
}

ESC::~ESC()
{
  this->stop();
  this->servo.detach();
}

void ESC::attach(int pin)
{
  this->i_pin = pin;
  this->servo.attach(pin);
}

int ESC::arm() { return this->i_armed; }

int ESC::arm(int armed)
{
  this->i_armed = armed;
  if(!this->i_armed)
    this->stop();
  return this->arm();
}

int ESC::speed() { return this->i_speed; }

int ESC::speed(int speed)
{
  if(!this->servo.attached())
    return ERROR_STATE;
  if((speed > this->i_control_max) || (speed < this->i_control_min))
    return ERROR_RANGE;
  if((speed > 0) && !this->i_armed)
    return ERROR_STATE;
  this->i_speed = speed;
  this->i_microtime = map(this->i_speed, this->i_control_min, this->i_control_max, this->i_servo_min, this->i_servo_max);
  this->servo.writeMicroseconds(this->i_microtime);
  return this->speed();
}

int ESC::stop() { return this->speed(0); }

int ESC::read()
{
  if(!this->servo.attached())
    return ERROR_STATE;
  return this->servo.read();
}

int ESC::read_microseconds() { return this->i_microtime; }

int ESC::control_min() { return this->i_control_min; }
int ESC::control_max() { return this->i_control_max; }

int ESC::control_min(int control_min)
{
  if(control_min >= this->i_control_max)
    return ERROR_RANGE;
  this->i_control_min = control_min;
  return this->control_min();
}

int ESC::control_max(int control_max)
{
  if(control_max <= this->i_control_min)
    return ERROR_RANGE;
  this->i_control_max = control_max;
  return this->control_max();
}

int ESC::output_min() { return this->i_servo_min; }
int ESC::output_max() { return this->i_servo_max; }

int ESC::output_min(int servo_min)
{
  if((servo_min >= this->i_servo_max) || (servo_min < 0))
    return ERROR_RANGE;
  this->i_servo_min = servo_min;
  return this->output_min();
}

int ESC::output_max(int servo_max)
{
  if(servo_max <= this->i_servo_min)
    return ERROR_RANGE;
  this->i_servo_max = servo_max;
  return this->output_max();
}
