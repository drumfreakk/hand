#include "Vinger.h"

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

