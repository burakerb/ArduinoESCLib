/*
 * Arduino ESC library
 * Dan Nixon
 * 05/01/2014
 * http://dan-nixon.com
 */

#ifndef ESC_H
#define ESC_H

#define DEFAULT_CONTROL_MIN 0
#define DEFAULT_CONTROL_MAX 100
#define DEFAULT_SERVO_MIN 10
#define DEFAULT_SERVO_MAX 169

#include <Arduino.h>
#include <Servo.h>

class ESC
{
  public:
    ESC();
    ~ESC();
    void attach(int);
    int speed();
    int speed(int);
    int stop();
    int read();
    int control_min();
    int control_max();
    int control_min(int);
    int control_max(int);
    int servo_min();
    int servo_max();
    int servo_min(int);
    int servo_max(int);
  private:
    Servo servo;
    int i_pin;
    int i_speed;
    int i_control_min;
    int i_control_max;
    int i_servo_min;
    int i_servo_max;
};

#endif
