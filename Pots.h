#ifndef POTS_H
#define POTS_H

#include <SPI.h>
#include "Pins.h"
#include "Preset.h"

enum Pot
{
	BOOST = 0,
	TREBLE = 1,
	MID = 2,
	BASS = 3,
	CUT = 4
};

class Pots
{
public:
	Pots();
	void SetToPreset(Preset &preset);
	void SetValue(Pot pot, int value);
};

#endif // POTS_H