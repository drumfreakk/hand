#include "src/Vinger/Vinger.h"

const int servos = 1;   // het aantal servos dat je gebruikt

int Vinger::vingers = 0;  // mischien werkt dit, samen met regel 21 tot 23

int maxTurn = 150;  // het max aantal graden dat het draait, dit is ongeveer het max met deze servos
int minTurn = 0;    // het min aantal graden dat het draait, dit is ongeveer het max met deze servos

Vinger vinger[servos];

void setup() {
  Serial.begin(9600);

  int pin[5] = {2, 3, 4, 5, 6};   // de pinnen, als je minder dan vijf servos gebruikt gebruikt het de eerste pinnen
 
  for(int x = 0; x < servos; x++){  // deze werkt
    vinger[x].attach(pin[x]);
  }
/*
  for(auto &servo : vinger){        // mischien werkt dit met regel 5
    servo.attach(pin[servo.vingers]);
  }*/
}

void loop() {
  
  // draai alle servos heen en terug, omstebeurt
  for(auto &toturn : vinger){ 
    toturn.turnFor(maxTurn);
    toturn.turnBack(minTurn);
  }
/*
  // draai alle servos heen
  for(int x = 0; x <= maxTurn; x += 2){
    for(auto &toturn : vinger){
      toturn.turnFor(x, 2);
    }
  }

  // draai alle servos terug
  for(int x = maxTurn; x >= minTurn; x -= 2){
    for(auto &toturn : vinger){
      toturn.turnBack(x, 2);
    }
  }*/
}
