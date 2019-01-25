#include "Vinger.h"

int maxTurn = 150;  // het aanatl graden dat het draait, dit is ongeveer het max met deze servos

Vinger vinger[5];   // het aantal servos dat je gebruikt

void setup() {
  Serial.begin(9600);

  int pin[5] = {2, 3, 4, 5, 6};   // de pinnen, als je minder dan vijf servos gebruikt gebruikt het de eerste pinnen
  for(int x = 0; x < 5; x++){
    vinger[x].serv.attach(pin[x]);
  }
  
}

void loop() {
  // turn all fingers forward and back one by one
  for(auto &toturn : vinger){   // each finger
  //  toturn.posi = 0;            // set the position to 0;
    turnFor(toturn, maxTurn);   // turn to maxTurn
    
  //  toturn.posi = maxTurn;      // set the position to maxTurn
    turnBack(toturn, 0);  // turn to 0
    
  //  toturn.posi = 0;            // set the position to 0
  }

  // turn all fingers forward
  for(int x = 0; x <= maxTurn; x += 2){  // turn all the fingers one degree by one
    for(auto &toturn : vinger){          // each finger
      turnFor(toturn, x, 2);                // turn
    }
  }

  for(auto &toturn: vinger){             // each finger
  //  toturn.posi = maxTurn;               // set the position to max
  }

  // turn all fingers back
  for(int x = maxTurn; x >= 0; x -= 2){  // one degree by one
    for(auto &toturn : vinger){          // each finger
      turnBack(toturn, x, 2);                // turn
    }
  }
}
