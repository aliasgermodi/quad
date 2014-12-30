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
  
  String input = "";

  while(Serial.available()>0)    // read any serial input
  {
    input += (char) Serial.read();  // read one char at a time
    delay(5);  // delay of 5ms for next char 
  }
    
  if(input == "on")
  {
    escf.write(10);
    escb.write(10);  
    escl.write(10);  
    escr.write(10);  
  }
  
  else if(input == "front")
  {
    escf.write(40);
    escb.write(50);  
    escl.write(50);  
    escr.write(50);  
  }
  else if(input == "back")
  {
    escf.write(50);
    escb.write(40);  
    escl.write(50);  
    escr.write(50);  
  }
  else if(input == "left")
  {
    escf.write(50);
    escb.write(50);  
    escl.write(40);  
    escr.write(50);  
  }
  else if(input == "right")
  {
    escf.write(50);
    escb.write(50);  
    escl.write(50);  
    escr.write(40);  
  }
    else if(input == "off")
  {
    escf.write(0);
    escb.write(0);  
    escl.write(0);  
    escr.write(0);  
  }
  else if(input == "up")
  {
    escf.write(40);
    escb.write(40);  
    escl.write(40);  
    escr.write(40);  
  }
}

