#ifndef FADERS_H
#define FADERS_H

#include "Preset.h"
#include "Fader.h"
#include "Pins.h"

class Faders
{
public:
	Faders();
	void MoveToPreset(Preset &preset);
	Preset GetCurrentValues();
	void Loop();

private:
	Fader boostFader;
	Fader bassFader;
	Fader middleFader;
	Fader trebleFader;
	Fader cutFader;
};

#endif // FADERS_H