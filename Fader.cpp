#include "Fader.h"

Fader::Fader(int wiperPin, int touchSensorPin, int motorAPin, int motorBPin)
	: wiperPin(wiperPin),
	  touchSensorPin(touchSensorPin),
	  motorAPin(motorAPin),
	  motorBPin(motorBPin)
{
	analogWrite(motorAPin, 0);
	analogWrite(motorBPin, 0);
	destinationReached = true;
}

void Fader::SetDestination(int position)
{
	positionDestination = constrain(position, 0, 255);
	destinationReached = false;
}

int Fader::GetCurrentPosition()
{
	int position = int(analogRead(wiperPin));
	position = map(position, 0, 660, 0, 255);
	return position;
}

void Fader::Loop()
{
	if (destinationReached)
	{
		stopFader();
		return;
	}

	int positionCurrent = GetCurrentPosition();

	if (abs(positionCurrent - positionDestination) <= 4)
	{
		destinationReached = true;
		stopFader();
		return;
	}

	if (positionCurrent > positionDestination)
	{
		speed = 2.25 * abs(positionCurrent - positionDestination) / 256 + 0.2;
		speed = constrain(speed, -1.0, 1.0);

		if (speed > 0.0)
		{
			moveFaderDown();
		}
	}

	if (positionCurrent < positionDestination)
	{
		speed = 2.25 * abs(positionCurrent - positionDestination) / 256 - 0.2;
		speed = constrain(speed, -1.0, 1.0);

		if (speed > 0.0)
		{
			moveFaderUp();
		}
	}
}

void Fader::moveFaderUp()
{
	analogWrite(motorAPin, 0);
	analogWrite(motorBPin, MAX_SPEED);
}

void Fader::moveFaderDown()
{
	analogWrite(motorAPin, MAX_SPEED);
	analogWrite(motorBPin, 0);
}

void Fader::stopFader()
{
	analogWrite(motorAPin, 0);
	analogWrite(motorBPin, 0);
}