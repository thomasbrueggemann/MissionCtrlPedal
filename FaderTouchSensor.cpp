#include "FaderTouchSensor.h"

FaderTouchSensor::FaderTouchSensor(int pin, int threshold = 300) // tune the threshold value to your hardware
{
	pin = pin;
	threshold = threshold;
}

void FaderTouchSensor::Begin()
{
	baseline = readTouch();
}

bool FaderTouchSensor::IsTouched()
{
	return (readTouch() > baseline + threshold);
}

int FaderTouchSensor::readTouch()
{
	pinMode(pin, OUTPUT);
	digitalWrite(pin, HIGH);
	pinMode(pin, INPUT);

	int i = 0;

	while (digitalRead(pin))
	{
		i++;
	}

	return i;
}