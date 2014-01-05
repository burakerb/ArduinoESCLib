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

int ESC::speed(int speed)
{
  if(!this->servo.attached())
    return -1;
  this->i_speed = speed;
  int value = map(this->i_speed, this->i_control_min, this->i_control_max, this->i_servo_min, this->i_servo_max);
  this->servo.write(value);
  return this->i_speed;
}

int ESC::speed()
{
  return this->i_speed;
}

int ESC::stop()
{
  return this->speed(0);
}

int ESC::read()
{
  return this->servo.read();
}

int ESC::control_min()
{
  return this->i_control_min;
}

int ESC::control_max()
{
  return this->i_control_max;
}

int ESC::control_min(int control_min)
{
  //TODO: Check for dodgy input
  this->i_control_min = control_min;
  return 0;
}

int ESC::control_max(int control_max)
{
  //TODO: Check for dodgy input
  this->i_control_max = control_max;
  return 0;
}

int ESC::servo_min()
{
  return this->i_servo_min;
}

int ESC::servo_max()
{
  return this->i_servo_max;
}

int ESC::servo_min(int servo_min)
{
  //TODO: Check for dodgy input
  this->i_servo_min = servo_min;
  return 0;
}

int ESC::servo_max(int servo_max)
{
  //TODO: Check for dodgy input
  this->i_servo_max = servo_max;
  return 0;
}
