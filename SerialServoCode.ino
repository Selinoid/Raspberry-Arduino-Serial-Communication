#include <Servo.h>

char receivedChar;
boolean newData = false;

Servo myservo;

void setup() {
  
  Serial.begin(9600);
  
  
  myservo.attach(8);    
}

void loop() {

recvInfo();
startservo();

}

void recvInfo() {
  
  if (Serial.available() > 0) {
    
    receivedChar = Serial.read();
    newData = true;
  }  
}

void startservo() {
  
  int servo = (receivedChar - '0');
  
  while(newData == true) {
    
    myservo.write(90);
    delay(2000);
    myservo.write(0);
    
    newData = false;
    
  }
}
