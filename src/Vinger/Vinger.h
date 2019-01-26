#ifndef VINGER_H
#define VINGER_H

#include <Servo.h>

#include "Arduino.h"

struct Vin{
int posi = 0;
	Servo serv;
};

void turnFor(Vin &turn, int deg, int stp = 1);
void turnBack(Vin &turn, int deg, int stp = 1);
void turn(Vin &turn, int deg, int stp = 1);
/*
class Vinger
{
private:
	int posi = 0;
	Servo serv;

public:
	Vinger(){}
	Vinger(int posi) : posi(posi){}

	uint8_t attach(int pin);

	void turnFor(int deg, int stp = 1);
	void turnBack(int deg, int stp = 1);

	void turn(int deg, int stp = 1);
};
*/
#endif
