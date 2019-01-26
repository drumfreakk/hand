#include "src/Vinger/Vinger.h"

const int servos = 1;

int maxTurn = 150;  // het aantal graden dat het draait, dit is ongeveer het max met deze servos
int minTurn = 0;

Vinger vinger[servos];   // het aantal servos dat je gebruikt

void setup() {
  Serial.begin(9600);

  int pin[5] = {2, 3, 4, 5, 6};   // de pinnen, als je minder dan vijf servos gebruikt gebruikt het de eerste pinnen
  for(int x = 0; x < servos; x++){
    vinger[x].attach(pin[x]);
  }
  
}

void loop() {
  
  // turn all fingers forward and back one by one
  for(auto &toturn : vinger){ 
    toturn.turnFor(maxTurn);
    toturn.turnBack(minTurn);
  }
/*
  // turn all fingers forward
  for(int x = 0; x <= maxTurn; x += 2){
    for(auto &toturn : vinger){
      toturn.turnFor(x, 2);
    }
  }

  // turn all fingers back
  for(int x = maxTurn; x >= minTurn; x -= 2){
    for(auto &toturn : vinger){
      toturn.turnBack(x, 2);
    }
  }*/
}
