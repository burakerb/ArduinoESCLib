/*
 * Turnigy ESC throttle programming sketch
 * Allows programming of the ESC throttle range using pre programmed Arduino.
 * Tested on Turnigy Plush ESC but may work on others.
 * After programming Arduino connect ESC BEC to Arduino Vin or use USB power.
 * Ensure Arduino resets just after connecting power to the ESC.
 * Dan Nixon
 * 06/01/2014
 * http://dan-nixon.com
 */

#include "Servo.h" //Needed for ESC
#include "ESC.h"

ESC esc;

int ramp_delay = 50;      //Delay when ramping through throttle range

void setup()
{
  pinMode(13, OUTPUT);
  esc.attach(9);          //ESC signal to pin 9

  esc.control_min(0);     //Ensure these settings match those in your RC code
  esc.control_max(100);
  esc.output_min(10);
  esc.output_max(179);

  esc.speed(esc.control_max());
  delay(4000);                    //May need to be tuned on a per-ESC basis
  esc.speed(esc.control_min());
  delay(5000);                    //May need to be tuned on a per-ESC basis

  //Ramp though throttle range when finished, pin 13 LED will light to show this is happening after programming has finished
  digitalWrite(13, HIGH);
  for(int s = esc.control_min(); s <= esc.control_max(); s++)
  {
    esc.speed(s);
    delay(ramp_delay);
  }
  for(int s = esc.control_max(); s >= esc.control_min(); s--)
  {
    esc.speed(s);
    delay(ramp_delay);
  }
  esc.stop();
  digitalWrite(13, LOW);
}

void loop() {}
