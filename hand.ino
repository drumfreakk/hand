#include "src/Vinger/Vinger.h"

#define MAXTURN 150  // het max aantal graden dat het draait, dit is ongeveer het max met deze servos
#define MINTURN 0    // het min aantal graden dat het draait, dit is ongeveer het max met deze servos

#define SERVOS 1   // het aantal servos dat je gebruikt
#define PINS {2, 3, 4, 5, 6} //

 int pin[5] = {2, 3, 4, 5, 6};   // de pinnen, als je minder dan vijf servos gebruikt gebruikt het de eerste pinnen

Vinger vingers[SERVOS];

void setup() {
  Serial.begin(9600);
 
  for(int x = 0; x < SERVOS; x++){  // deze werkt
    vingers[x].setLimits(MINTURN, MAXTURN);
    vingers[x].attach(pin[x]);
  }
/*
  for(auto &servo : vinger){        // mischien werkt dit met regel 5
    servo.attach(pin[servo.vingers]);
  }*/
}

void loop() {
  
  // draai alle servos heen en terug, omstebeurt
  for(Vinger &toTurn : vingers){ 
    toTurn.turn(toTurn.getMax());
    toTurn.turn(toTurn.getMin());
//    toturn.turnFor(maxTurn);
//    toturn.turnBack(minTurn);
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
