#include "Pots.h"

Pots::Pots()
{
	pinMode(SPI_CHIP_SELECT, OUTPUT);
}

void Pots::SetToPreset(Preset &preset)
{
	SetValue(BOOST, preset.Boost);
	SetValue(TREBLE, preset.Treble);
	SetValue(MID, preset.Middle);
	SetValue(BASS, preset.Bass);
	SetValue(CUT, preset.Cut);
}

void Pots::SetValue(Pot pot, int value)
{
	Serial.print("Setting pot ");
	Serial.print(pot);
	Serial.print(" to ");
	Serial.println(value);

	digitalWrite(SPI_CHIP_SELECT, LOW);
	delay(100);

	SPI.transfer(pot);
	SPI.transfer(value);

	delay(50);

	digitalWrite(SPI_CHIP_SELECT, HIGH);
}