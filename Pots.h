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
	VOLUME = 4
};

class Pots
{
public:
	Pots();
	void setToPreset(Preset &preset);
	void setValue(Pot pot, int value);
};

#endif // POTS_H