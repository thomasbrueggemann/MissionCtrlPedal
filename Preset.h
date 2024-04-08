#ifndef PRESET_H
#define PRESET_H

#include <Arduino.h>

class Preset
{
public:
	byte Cut;
	byte Bass;
	byte Middle;
	byte Treble;
	byte Boost;
	bool AmpSwitch;
};

#endif // PRESET_H