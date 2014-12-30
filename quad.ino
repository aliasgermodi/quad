/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int front = 13;
int back = 9;
int left = 10;
int right = 11;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(front, OUTPUT);
  pinMode(back, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
 Serial.begin(9600);     
}

// the loop routine runs over and over again forever:
void loop() {
  String input = "";
  
  while(Serial.available()>0)    // read any serial input
  {
    input += (char) Serial.read();  // read one charfff at a time
    delay(5);  // delay of 5ms for next char 
  }
  
  if(input == "front")
  {
     analogWrite(front, 10);
     analogWrite(back, 255);
     analogWrite(left, 255);
     analogWrite(right, 255);
  }
  else if(input == "back")
  {
     analogWrite(front, 255);
     analogWrite(back, 10);
     analogWrite(left, 255);
     analogWrite(right, 255);
  }
  else if(input == "left")
  {
     analogWrite(front, 255);
     analogWrite(back, 255);
     analogWrite(left, 10);
     analogWrite(right, 255);
  }
  else if(input == "right")
  {
     analogWrite(front, 255);
     analogWrite(back, 255);
     analogWrite(left, 255);
     analogWrite(right, 10);
  }
}
