#include <Servo.h>

Servo escf;
Servo escb;
Servo escl;
Servo escr;


//int throttlePin = 0;
//int v=0;
void setup()
{

escf.attach(6);
escb.attach(9);
escl.attach(11);
escr.attach(10);
Serial.begin(9600);
escf.write(0);
escb.write(0);
escl.write(0);
escr.write(0);
delay(1);
}

void loop()
{
//int throttle = analogRead(throttlePin);
//throttle = map(throttle, 0, 1023, 0, 179);
 
  
/*
 for(int i=0;i<170;i++)
 {
   delay(250);  
   Serial.println(i);
   escf.write(i);
   escb.write(i);  
   escl.write(i);  
   escr.write(i);

 }*/
   escf.write(10);
   escb.write(10);  
   escl.write(10);  
   escr.write(10);
}
