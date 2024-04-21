#include "Pots.h"

Pots::Pots()
{
	pinMode(SPI_CHIP_SELECT, OUTPUT);
};

void Pots::setToPreset(Preset &preset)
{
	setValue(BOOST, preset.Boost);
	setValue(TREBLE, preset.Treble);
	setValue(MID, preset.Middle);
	setValue(BASS, preset.Bass);
	setValue(VOLUME, preset.Cut);
};

void Pots::setValue(Pot pot, int value)
{
	digitalWrite(SPI_CHIP_SELECT, LOW);
	delay(100);

	SPI.transfer(pot);
	SPI.transfer(value);

	delay(100);

	digitalWrite(SPI_CHIP_SELECT, HIGH);
}