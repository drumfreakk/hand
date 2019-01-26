#include "Vinger.h"


void turnFor(Vin &turn, int deg, int stp = 1){
  Servo &serv = turn.serv;
  int &pos = turn.posi;
  
  for (pos; pos <= deg; pos += 1) {
    serv.write(pos);
    delay(15);
  }
}

void turnBack(Vin &turn, int deg, int stp = 1){
  Servo &serv = turn.serv;
  int &pos = turn.posi;

  for (pos; pos >= deg; pos -= stp) {
    serv.write(pos);
    delay(15);
  }
}

void turn(Vin &turn, int deg, int stp = 1){
  if(deg > turn.posi){
    turnBack(turn, deg, stp);
  }
  else if(deg < turn.posi){
    turnFor(turn, deg, stp);
  }
}

/*
uint8_t Vinger::attach(int pin){
	Serial.println("attak");
	return Vinger::serv.attach(pin);	
}

void Vinger::turnFor(int deg, int stp = 1){
Serial.println("for");
  Servo &serv = Vinger::serv;
  int &pos = Vinger::posi;
  
  for (pos; pos <= deg; pos += 1) {
    serv.write(pos);
    delay(15);
  }
}

void Vinger::turnBack(int deg, int stp = 1){
Serial.println("back");
  Servo &serv = Vinger::serv;
  int &pos = Vinger::posi;

  for (pos; pos >= deg; pos -= stp) {
    serv.write(pos);
    delay(15);
  }
}

void Vinger::turn(int deg, int stp = 1){
	Serial.println("hi");
  if(deg > Vinger::posi){
    Vinger::turnBack(deg, stp);
  }
  else if(deg < Vinger::posi){
    Vinger::turnFor(deg, stp);
  }
}
*/
