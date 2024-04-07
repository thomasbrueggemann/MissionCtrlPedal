#include "Banks.h"

#define MAX_BANKS 10
#define MAX_PRESETS 4

Banks::Banks(LED &led, SegmentDisplay &segmentDisplay) : segmentDisplay(segmentDisplay), led(led)
{
	currentBank = 0;
	SetPreset(0);

	updateDisplay();
}

void Banks::SetPreset(byte preset)
{
	currentPreset = preset;
	led.TurnOn(currentPreset);
}

void Banks::BankUp()
{
	currentBank = (currentBank + 1) % MAX_BANKS;
	SetPreset(0);
	updateDisplay();
}

void Banks::BankDown()
{
	currentBank = (currentBank - 1 + MAX_BANKS) % MAX_BANKS;
	SetPreset(0);
	updateDisplay();
}

byte Banks::GetCurrentBank()
{
	return currentBank;
}

byte Banks::GetCurrentPreset()
{
	return currentPreset;
}

void Banks::updateDisplay()
{
	segmentDisplay.DisplayNumber(currentBank + 1);
}