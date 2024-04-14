#include "Banks.h"
#include "Footswitches.h"
#include "SegmentDisplay.h"
#include "LED.h"
#include "SettingsButtons.h"

#define BAUD_RATE 115200

LED leg;
SegmentDisplay segmentDisplay;
Banks banks(leg, segmentDisplay);
Footswitches footswitches(banks);
SettingsButtons settingsButtons;

void setup()
{
	Serial.begin(BAUD_RATE);
}

void loop()
{
	footswitches.check();
	settingsButtons.check();
}