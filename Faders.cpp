#include "Faders.h"

Faders::Faders(Pots &pots)
	: boostFader(FADER_BOOST_WIPER_PIN, FADER_BOOST_MOTOR_A_PIN, FADER_BOOST_MOTOR_B_PIN, pots, Pot::BOOST),
	  bassFader(FADER_BASS_WIPER_PIN, FADER_BASS_MOTOR_A_PIN, FADER_BASS_MOTOR_B_PIN, pots, Pot::BASS),
	  middleFader(FADER_MIDDLE_WIPER_PIN, FADER_MIDDLE_MOTOR_A_PIN, FADER_MIDDLE_MOTOR_B_PIN, pots, Pot::MID),
	  trebleFader(FADER_TREBLE_WIPER_PIN, FADER_TREBLE_MOTOR_A_PIN, FADER_TREBLE_MOTOR_B_PIN, pots, Pot::TREBLE),
	  cutFader(FADER_CUT_WIPER_PIN, FADER_CUT_MOTOR_A_PIN, FADER_CUT_MOTOR_B_PIN, pots, Pot::CUT),
	  pots(pots)
{
}

void Faders::MoveToPreset(Preset &preset)
{
	boostFader.SetDestination(preset.Boost);
	bassFader.SetDestination(preset.Bass);
	middleFader.SetDestination(preset.Middle);
	trebleFader.SetDestination(preset.Treble);
	cutFader.SetDestination(preset.Cut);
}

Preset Faders::GetCurrentValues()
{
	Preset p;
	p.Boost = boostFader.GetCurrentPosition();
	p.Bass = bassFader.GetCurrentPosition();
	p.Middle = middleFader.GetCurrentPosition();
	p.Treble = trebleFader.GetCurrentPosition();
	p.Cut = cutFader.GetCurrentPosition();

	return p;
}

void Faders::Loop()
{
	boostFader.Loop();
	bassFader.Loop();
	middleFader.Loop();
	trebleFader.Loop();
	cutFader.Loop();
}
