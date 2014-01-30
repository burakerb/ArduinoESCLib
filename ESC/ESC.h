/*
 * Arduino ESC library
 * Dan Nixon
 * 05/01/2014
 * http://dan-nixon.com
 */

#ifndef ESC_H
#define ESC_H

#define ERROR_STATE -1
#define ERROR_RANGE -2

#define DEFAULT_CONTROL_MIN 0
#define DEFAULT_CONTROL_MAX 100
#define DEFAULT_SERVO_MIN 700
#define DEFAULT_SERVO_MAX 2500

#include <Arduino.h>
#include <Servo.h>

class ESC
{
  public:
    ESC();
    ~ESC();
    void attach(int);
    int arm();
    int arm(int);
    int speed();
    int speed(int);
    int stop();
    int read();
    int read_microseconds();
    int control_min();
    int control_max();
    int control_min(int);
    int control_max(int);
    int output_min();
    int output_max();
    int output_min(int);
    int output_max(int);

  private:
    Servo servo;
    int i_pin;
    int i_armed;
    int i_speed;
    int i_microtime;
    int i_control_min;
    int i_control_max;
    int i_servo_min;
    int i_servo_max;
};

#endif
