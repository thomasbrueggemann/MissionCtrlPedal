#include "Fader.h"

Fader::Fader(int wiperPin, int touchSensorPin, int motorAPin, int motorBPin)
	: wiperPin(wiperPin),
	  touchSensorPin(touchSensorPin),
	  motorAPin(motorAPin),
	  motorBPin(motorBPin)
{
	analogWrite(motorAPin, 0);
	analogWrite(motorBPin, 0);
	Serial.println("Fader created");
}

void Fader::SetDestination(int position)
{
	positionDestination = constrain(position, 0, 255);
}

int Fader::GetCurrentPosition()
{
	return int(analogRead(wiperPin) / 4);
}

void Fader::Loop()
{
	/*fader_pos = int((filter_amt * last_fader_pos) + ((1.0 - filter_amt) * int(analogRead(fader) / 4)));
	if (abs(fader_pos - last_fader_pos) > 1)
	{
		Serial.println(fader_pos);
		if (motor_release_state == false)
		{
			go_to_position(saved_positions[current_saved_position]);
		}
		last_fader_pos = fader_pos;
	}*/

	int positionCurrent = GetCurrentPosition();
	Serial.print("Current position: ");
	Serial.println(positionCurrent);
	Serial.print("Destination position: ");
	Serial.println(positionDestination);

	if (abs(positionCurrent - positionDestination) <= 4)
	{
		stopFader();
		return;
	}

	if (positionCurrent > positionDestination)
	{
		speed = 2.25 * abs(positionCurrent - positionDestination) / 256 + 0.2;
		speed = constrain(speed, -1.0, 1.0);

		if (speed > 0.0)
		{
			moveFaderUp();
		}
	}

	if (positionCurrent < positionDestination)
	{
		speed = 2.25 * abs(positionCurrent - positionDestination) / 256 - 0.2;
		speed = constrain(speed, -1.0, 1.0);

		if (speed > 0.0)
		{
			moveFaderDown();
		}
	}
}

void Fader::moveFaderUp()
{
	Serial.println("Moving fader up");
	analogWrite(motorAPin, 0);
	analogWrite(motorBPin, MAX_SPEED);
}

void Fader::moveFaderDown()
{
	Serial.println("Moving fader down");
	analogWrite(motorAPin, MAX_SPEED);
	analogWrite(motorBPin, 0);
}

void Fader::stopFader()
{
	analogWrite(motorAPin, 0);
	analogWrite(motorBPin, 0);
}
