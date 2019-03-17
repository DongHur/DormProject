/* In this code, we try to stop random people from coming in here.
*/
#include <Keypad.h>
#include <Servo.h>
#include <Wire.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
int COUNTER = 0;
const char act_password[] = {'2', '4', '8', '3', '6'};
char curr_password[] = {'0', '0', '0', '0', '0'};

Servo myservo1;
Servo myservo2;


char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {12, 11, 10}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    if (key == '#') {
      Serial.println("Sanity Checkz");
      reset_curr_pass();
      Serial.println("IF STATEMENT 1");
    }
    else{
      curr_password[COUNTER] = key;
      
      Serial.print("Counter = ");
      Serial.println(COUNTER);

      Serial.print("Curr_password");
      for (int a = 0; a < 5; a = a + 1){
        Serial.print(curr_password[a]);
      }
      if (COUNTER == 4) {
        bool is_valid = true;
        for (int i = 0; i < 5; i = i + 1) {
          if (curr_password[i] != act_password[i]){
            is_valid = false;
          }
        }
        if (is_valid == true) {
          open_door();
        }
        reset_curr_pass();
      }
      else {
        COUNTER += 1;
      }
    }

    
    

    
//    else if (int(key) == act_password[COUNTER]) {
//      Serial.println("Sanity Checkz 2");
//      COUNTER = COUNTER + 1;
//      if (COUNTER == 5) {
//        Serial.println("OPEN DOOR");
////        open_door();
//      }
//      Serial.println("IF STATEMENT 2");
//    }
    Serial.println();
    Serial.println(key);
  }
}

void reset_curr_pass() {
  for (int i = 0; i < 5; i = i + 1) {
    curr_password[i] = '0';
  }
  COUNTER = 0;
}

void open_door() {
  Serial.print("Got em");
      
      myservo1.attach(4); //attach servos in this pin
      myservo2.attach(5);
      
      myservo1.write(0); 
      myservo2.write(0); 
      
      delay(7000);  // opens door for 7 seconds
      
      myservo1.detach();
      myservo2.detach();
}

