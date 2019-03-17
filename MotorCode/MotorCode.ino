#include <Servo.h>
#include <Wire.h>
void setup() {
 Serial.begin(9600);
}

void loop() {
  if (YOURCODE = TRUE){
      Serial.print("Got em");
      
      myservo1.attach(6); //attach servos in this pin
      myservo2.attach(5);
      
      myservo1.write(0); //keep 
      myservo2.write(0); //keep
      
      delay(7000);  // opens door for 7 seconds
      
      myservo1.detach();
      myservo2.detach();
}
