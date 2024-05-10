#ifndef FADER_H
#define FADER_H

#include <Arduino.h>
#include "Pots.h"

#define TOUCH_SENSOR_THRESHOLD 12
#define MAX_SPEED 255

class Fader
{
public:
	Fader(int wiperPin, int touchSensorPin, int motorAPin, int motorBPin, Pots &pots, Pot faderPot);

	void SetDestination(int position);
	int GetCurrentPosition();
	void Loop();

private:
	int motorAPin;
	int motorBPin;
	int wiperPin;
	int touchSensorPin;
	Pots &pots;
	Pot faderPot;

	unsigned long liveModeLastUpdateTime = 0;
	int liveModeLastPosition = 0;
	bool destinationReached = true;
	int positionDestination;
	float speed = 1.0;

	void liveUpdatePotValue(int positionCurrent);
	void moveFaderUp();
	void moveFaderDown();
	void stopFader();
};

#endif // FADER_H