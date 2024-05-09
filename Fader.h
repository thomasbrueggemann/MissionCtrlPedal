#ifndef FADER_H
#define FADER_H

#include <Arduino.h>
#include "FaderTouchSensor.h"

#define TOUCH_SENSOR_THRESHOLD 300
#define MAX_SPEED 183

class Fader
{
public:
	Fader(int wiperPin, int touchSensorPin, int motorAPin, int motorBPin);

	void SetDestination(int position);
	int GetCurrentPosition();
	void Loop();

private:
	int motorAPin;
	int motorBPin;
	int wiperPin;
	int touchSensorPin;

	int positionDestination;
	float speed = 1.0;

	void moveFaderUp();
	void moveFaderDown();
	void stopFader();
};

#endif // FADER_H