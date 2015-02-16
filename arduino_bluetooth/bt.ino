#include <Wire.h>
#include <SoftwareSerial.h>

int bluetoothTx = 4;
int bluetoothRx = 3;
int led = 13;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  pinMode(led,OUTPUT);
  //Setup usb serial connection to computer
  Serial.begin(9600);

  //Setup Bluetooth serial connection to android
  bluetooth.begin(115200);
  bluetooth.print("$$$");
  delay(100);
  bluetooth.println("U,9600,N");
  bluetooth.begin(9600);
}

void loop()
{
  
  //Read from bluetooth and write to usb serial
  if(bluetooth.available())
  {
    char toSend = (char)bluetooth.read();
    Serial.print(toSend);
  }

// Only really used to test to see if the Arduino is receiving the correct message
//Read from usb serial to bluetooth
  if(Serial.available())
    {
      char toSend = (char)Serial.read();
      bluetooth.print(toSend);
    }
  }

