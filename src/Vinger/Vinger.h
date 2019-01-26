#ifndef VINGER_H
#define VINGER_H

#include <Servo.h>

#include "Arduino.h"

class Vinger
{
public:

	static int vingers;

	int posi = 0;
	Servo serv;

	Vinger(){
		fingers += 1;
	}
	Vinger(int posi) : posi(posi){
		fingers += 1;
	}

	uint8_t attach(int pin);

	void turnFor(int deg, int stp = 1);
	void turnBack(int deg, int stp = 1);

	void turn(int deg, int stp = 1);
};

#endif
