#ifndef VINGER_H
#define VINGER_H

#include <Servo.h>

struct Vinger{
  int posi = 0;
  Servo serv;
};

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

void turnFor(Vinger &turn, int deg, int stp){
  Servo &serv = turn.serv;
  int &pos = turn.posi;
  
  for (pos; pos <= deg; pos += stp) {
    serv.write(pos);
    delay(15);
  }
}

void turnBack(Vinger &turn, int deg, int stp){
  Servo &serv = turn.serv;
  int &pos = turn.posi;

  for (pos; pos >= deg; pos -= stp) {
    serv.write(pos);
    delay(15);
  }
}

#endif
