#include "Faders.h"

Faders::Faders()
	: /*boostFader(FADER_BOOST_WIPER_PIN, FADER_BOOST_TOUCH_SENSOR_PIN, FADER_BOOST_MOTOR_A_PIN, FADER_BOOST_MOTOR_B_PIN),
	  bassFader(FADER_BASS_WIPER_PIN, FADER_BASS_TOUCH_SENSOR_PIN, FADER_BASS_MOTOR_A_PIN, FADER_BASS_MOTOR_B_PIN),
	  middleFader(FADER_MIDDLE_WIPER_PIN, FADER_MIDDLE_TOUCH_SENSOR_PIN, FADER_MIDDLE_MOTOR_A_PIN, FADER_MIDDLE_MOTOR_B_PIN),
	  trebleFader(FADER_TREBLE_WIPER_PIN, FADER_TREBLE_TOUCH_SENSOR_PIN, FADER_TREBLE_MOTOR_A_PIN, FADER_TREBLE_MOTOR_B_PIN),*/
	  cutFader(FADER_CUT_WIPER_PIN, FADER_CUT_TOUCH_SENSOR_PIN, FADER_CUT_MOTOR_A_PIN, FADER_CUT_MOTOR_B_PIN)
{
}

void Faders::MoveToPreset(Preset &preset)
{
	int randomInt = random(0, 145);
	cutFader.SetDestination(randomInt);
}

Preset Faders::GetCurrentValues()
{
	return Preset();
}

void Faders::Loop()
{
	/*boostFader.Loop();
	bassFader.Loop();
	middleFader.Loop();
	trebleFader.Loop();*/
	cutFader.Loop();
}
