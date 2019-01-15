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
  // turn all fingers forward and back one by one
  for(auto &toturn : vinger){   // each finger
    toturn.posi = 0;            // set the position to 0;
    turnFor(toturn, maxTurn);   // turn to maxTurn
    
    toturn.posi = maxTurn;      // set the position to maxTurn
    turnBack(toturn, 0);  // turn to 0
    
    toturn.posi = 0;            // set the position to 0
  }

  // turn all fingers forward
  for(int x = 0; x <= maxTurn; x += 1){  // turn all the fingers one degree by one
    for(auto &toturn : vinger){          // each finger
      turnFor(toturn, x);                // turn
    }
  }

  for(auto &toturn: vinger){             // each finger
    toturn.posi = maxTurn;               // set the position to max
  }

  // turn all fingers back
  for(int x = maxTurn; x >= 0; x -= 1){  // one degree by one
    for(auto &toturn : vinger){          // each finger
      turnBack(toturn, x);                // turn
    }
  }
}


void turnFor(Vinger &turn, int deg){
  Servo &serv = turn.serv;
  int &pos = turn.posi;
  
  for (pos; pos <= deg; pos += 1) {
    serv.write(pos);
    delay(15);
  }
}

void turnBack(Vinger &turn, int deg){
  Servo &serv = turn.serv;
  int &pos = turn.posi;

  for (pos; pos >= deg; pos -= 1) {
    serv.write(pos);
    delay(15);
  }
}
