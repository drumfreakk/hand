#include <Servo.h>

Servo servo;

char inp;

void setup() {
  Serial.begin(9600);
  Serial.println("What pin is the servo attached to");

  bool recieved = false;
  
  while(!recieved){
    while(Serial.available() > 0){
      inp = Serial.read();
      servo.attach(static_cast<int>(inp));
      recieved = true;
    }
  }

}

void loop() {
  Serial.println("Set angle: ");
  
  while(Serial.available() > 0){
    inp = Serial.read();

    servo.write(static_cast<int>(inp))

    Serial.println("Set servo to" + inp + " degrees");
  }  

}
