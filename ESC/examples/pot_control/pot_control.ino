/*
 * ESC potentiometer control demo
 * Dan Nixon
 * 05/01/2014
 * http://dan-nixon.com
 */

#include "Servo.h" //Needed for ESC
#include "ESC.h"

ESC esc;

void setup()
{
  Serial.begin(115200);     //Let's have some debug data
  esc.attach(9);            //Our ESC is on pin 9
  esc.control_max(1023);    //Max. throttle is max analogRead value
}
 
void loop()
{
  int val = analogRead(0);    //Get a value from the pot.
  if(val <= 10) val = 0;      //Becasue no pot. is perfect
  int speed = esc.speed(val); //Set the ESC speed
  Serial.print(speed);        //Print some debug data
  Serial.print("\t-\t");      //Some nicely formatted debug data
  Serial.println(esc.read()); //Lots of nicely formatted debug data
  delay(10);                  //yukkuri shiteitte ne
}
