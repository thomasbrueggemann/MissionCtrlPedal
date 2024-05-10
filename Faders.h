#ifndef FADERS_H
#define FADERS_H

#include "Preset.h"
#include "Fader.h"
#include "Pins.h"
#include "Pots.h"

class Faders
{
public:
	Faders(Pots &pots);
	void MoveToPreset(Preset &preset);
	Preset GetCurrentValues();
	void Loop();

private:
	Fader boostFader;
	Fader bassFader;
	Fader middleFader;
	Fader trebleFader;
	Fader cutFader;
	Pots &pots;
};

#endif // FADERS_H