#ifndef BANKS_H
#define BANKS_H

#include "SegmentDisplay.h"
#include "LED.h"

class Banks
{
public:
	Banks(LED &led, SegmentDisplay &segmentDisplay);

	void SetPreset(byte preset);
	void BankUp();
	void BankDown();

	byte GetCurrentBank();
	byte GetCurrentPreset();

private:
	byte currentBank;
	byte currentPreset;

	SegmentDisplay &segmentDisplay;
	LED &led;

	void updateDisplay();
};

#endif