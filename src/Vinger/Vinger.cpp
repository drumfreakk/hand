#include "Vinger.h"

uint8_t Vinger::attach(int pin){
	return Vinger::servo.attach(pin);	
}

void Vinger::turnFor(int deg, int step){
  int &pos = Vinger::position;
  
  for (pos; pos <= deg; pos += step) {
    Vinger::servo.write(pos);
    delay(15);
  }
}

void Vinger::turnBack(int deg, int step){
  int &pos = Vinger::position;

  for (pos; pos >= deg; pos -= step) {
    Vinger::servo.write(pos);
    delay(15);
  }
}

void Vinger::turn(int deg, int step){
  if(deg > Vinger::position){
    Vinger::turnBack(deg, step);
  }
  else if(deg < Vinger::position){
    Vinger::turnFor(deg, step);
  }
}

int Vinger::getMin(){
	return Vinger::minPos;
}
int Vinger::getMax(){
	return Vinger::maxPos;
}

int Vinger::setLimits(int min, int max){
	Vinger::minPos = min;
	Vinger::maxPos = max;
}

