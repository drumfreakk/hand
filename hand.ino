
#define SERVOS 2   // het aantal servos dat je gebruikt

#include <BetterServo.h>

int pin[5] = {2, 3, 4, 5, 6};   // de pinnen, als je minder dan vijf servos gebruikt gebruikt het de eerste pinnen

BetterServo vingers[SERVOS];

void turnAsOneA(BetterServo *servos, Position *endPositions, int wait){
	Serial.println("Hi");
	for(int i = 0; i < endPositions->amount; i++){
		servos[i].turn(endPositions->positions[i], 0);
		if(endPositions->positions[i] == NULL){
			Serial.println("NULL");
		}
		Serial.println(endPositions->positions[i]);
	}
	Serial.println("");
	delay(wait);
}


Position pos[2];

void testPos(Position *toTest){
	Serial.println(toTest->positions[0]);
	Serial.println(toTest->positions[1]);
	Serial.println(toTest->amount);
}

void setup() { 
	Serial.begin(9600);	

	pos[0].positions[0] = 30;
	pos[0].positions[1] = 30;
	pos[1].positions[0] = 140;
	pos[1].positions[1] = 140;
	
	for(int x = 0; x < SERVOS; x++){
		vingers[x].setLimits(0, 150);
		vingers[x].attach(pin[x]);
		vingers[x].turn(30);
	}
}

void loop() {    	
	turnAsOneA(vingers, &pos[0], 2000); 
	turnAsOneA(vingers, &pos[1], 2000);
}
