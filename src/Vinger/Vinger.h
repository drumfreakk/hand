#ifndef VINGER_H
#define VINGER_H

#include <Servo.h>

#include "Arduino.h"

class Vinger
{
private:
	int position = 0;
	Servo servo;

	int minPos, maxPos;

public:

	Vinger() : minPos(0), maxPos(150){}
	Vinger(int min, int max) : minPos(min), maxPos(max){}

	uint8_t attach(int pin);

	void turnFor(int deg, int step = 1);
	void turnBack(int deg, int step = 1);

	void turn(int deg, int step = 1);

	int getMin();
	int getMax();	

	int setLimits(int min, int max);
};

#endif
