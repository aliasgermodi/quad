#include <Servo.h>
#include <Wire.h>
#include <SoftwareSerial.h>

int bluetoothTx = 4;
int bluetoothRx = 3;
Servo escf;
Servo escb;
Servo escl;
Servo escr;
int led = 13;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);


//int throttlePin = 0;
//int v=0;
void setup()
{
  pinMode(led,OUTPUT);
  digitalWrite(led,HIGH);
  
  escf.attach(10); //front
  escb.attach(5);  //back
  escl.attach(9);  //left
  escr.attach(6);  //right
  Serial.begin(9600);
  escf.write(0);
  escb.write(0);
  escl.write(0);
  escr.write(0);
  //delay(1);
  //Setup Bluetooth serial connection to android
  bluetooth.begin(115200);
  bluetooth.print("$$$");
  delay(100);
  bluetooth.println("U,9600,N");
  bluetooth.begin(9600);
  
}

void loop()
{
  
  char input;
//  while(bluetooth.available()>0)    // read any serial input
//  {
//    input += (char) bluetooth.read();  // read one char at a time
//    delay(5);  // delay of 5ms for next char 
//  }
  if(bluetooth.available())
  {
    input = (char)bluetooth.read();
    Serial.print(input);
  
    //Serial.write(input);
  
      if(input == 'o' || input == 'w' || input == 's') //on
      {
        Serial.println("LOW");
        escf.write(20);
        escb.write(20);  
        escl.write(20);  
        escr.write(20);  
      }
  
      else if(input == 'f')  //forward
      {
        escf.write(40);
        escb.write(60);  
        escl.write(60);  
        escr.write(60);  
      }
      else if(input == 'b')  //back
      {
        escf.write(60);
        escb.write(40);  
        escl.write(60);  
        escr.write(60);  
      }
      else if(input == 'l') //left
      {
        escf.write(60);
        escb.write(60);  
        escl.write(40);  
        escr.write(60);  
      }
      else if(input == 'r')  //right
      {
        escf.write(60);
        escb.write(60);  
        escl.write(60);  
        escr.write(40);  
      }
      else if(input == 'q')  //off
      {
        escf.write(0);
        escb.write(0);  
        escl.write(0);
        escr.write(0);  
      }
      else if(input == 't')  //lift
      {
        escf.write(50);
        escb.write(50);  
        escl.write(50);  
        escr.write(50);  
      }
  
  }  
}

