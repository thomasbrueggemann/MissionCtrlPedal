#include "Fader.h"

Fader::Fader(int wiperPin, int touchSensorPin, int motorAPin, int motorBPin)
	: touchSensor(touchSensorPin, TOUCH_SENSOR_THRESHOLD),
	  wiperPin(wiperPin),
	  touchSensorPin(touchSensorPin),
	  motorAPin(motorAPin),
	  motorBPin(motorBPin)
{
	analogWrite(motorAPin, 0);
	analogWrite(motorBPin, 0);
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
	if (touchSensor.IsTouched())
	{
		stopFader();
		delay(60);
		return;
	}

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
	analogWrite(motorBPin, 255);
}

void Fader::moveFaderDown()
{
	analogWrite(motorAPin, 255);
	analogWrite(motorBPin, 0);
}

void Fader::stopFader()
{
	analogWrite(motorAPin, 0);
	analogWrite(motorBPin, 0);
}