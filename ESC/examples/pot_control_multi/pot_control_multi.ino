/*
 * ESC potentiometer control demo with multiple ESCs connected to consecutive pins
 * Dan Nixon
 * 05/01/2014
 * http://dan-nixon.com
 */

#include "Servo.h" //Needed for ESC
#include "ESC.h"

#define ESC_COUNT 4

ESC esc[ESC_COUNT];

void setup()
{
  Serial.begin(115200);
  int first_pin = 8;                    //First pin we are using for ESCs
  for(int i = 0; i < ESC_COUNT; i++)    //Configure each ESC
  {
    esc[i].attach(first_pin + i);
    esc[i].control_max(1023);
    esc[i].arm(1);
  }
}
 
void loop()
{
  int val = analogRead(0);             //Get a value from the pot.
  if(val <= 10) val = 0;               //Becasue no pot. is perfect
  for(int i = 0; i < ESC_COUNT; i++)   //For each ESC
    esc[i].speed(val);                 //Set the speed
  Serial.println(val);                //Print some debug data
  delay(10);                           //yukkuri shiteitte ne
}
