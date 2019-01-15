#include <Servo.h>

int maxTurn = 180;

struct Vinger{
  int posi = 0;
  Servo serv;
};

Vinger vinger[5];

void setup() {
  Serial.begin(9600);

  int pin[5] = {2, 3, 4, 5, 6};
  for(int x = 0; x < 5; x++){
    vinger[x].serv.attach(pin[x]);
  }
  
}

void loop() {
  for(auto &toturn : vinger){ // turn all fingers forward and back one by one
    turnFor(toturn, maxTurn); 
    turnBack(toturn, maxTurn);
  }
  
  for(int x = 0; x <= maxTurn; x += 1){ // turn all fingers forward
    for(auto &toturn : vinger){
      turnFor(toturn, x); 
    }
  }
  
  for(int x = maxTurn; x >= 0; x -= 1){ // turn all fingers back
    for(auto &toturn : vinger){
      turnFor(toturn, x); 
    }
  }
}


void turnFor(Vinger &ving, int out){
  Servo &serv = ving.serv;
  int &pos = ving.posi;
  
  for (pos = 0; pos <= out; pos += 1) {
    serv.write(pos);
    delay(15);
  }
}

void turnBack(Vinger &ving, int out){
  Servo &serv = ving.serv;
  int &pos = ving.posi;

  for (pos = out; pos >= 0; pos -= 1) {
    serv.write(pos);
    delay(15);
  }
}
