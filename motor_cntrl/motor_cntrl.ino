#include <Servo.h>

Servo escf;
Servo escb;
Servo escl;
Servo escr;
int led = 13;


//int throttlePin = 0;
//int v=0;
void setup()
{
  pinMode(led,OUTPUT);
  digitalWrite(led,HIGH);
  
  escf.attach(10);
  escb.attach(5);
  escl.attach(9);
  escr.attach(6);
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
    escf.write(20);
    escb.write(20);  
    escl.write(20);  
    escr.write(20);  
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

