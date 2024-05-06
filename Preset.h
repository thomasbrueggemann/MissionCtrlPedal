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

	void Print()
	{
		Serial.print("Cut: ");
		Serial.print(Cut);

		Serial.print(", Bass: ");
		Serial.print(Bass);

		Serial.print(", Middle: ");
		Serial.print(Middle);

		Serial.print(", Treble: ");
		Serial.print(Treble);

		Serial.print(", Boost: ");
		Serial.println(Boost);
	}
};

#endif // PRESET_H