#include <Servo.h>

Servo esc;
//int throttlePin = 0;
//int v=0;
void setup()
{
esc.attach(9);
Serial.begin(9600);
esc.write(0);
delay(1);
}

void loop()
{
//int throttle = analogRead(throttlePin);
//throttle = map(throttle, 0, 1023, 0, 179);
 
  //esc.write(50);
 for(int i=0;i<170;i++)
 {
   delay(250);  
   Serial.println(i);
   esc.write(i);
 }
}
