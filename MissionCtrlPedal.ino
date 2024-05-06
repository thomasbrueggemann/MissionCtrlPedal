#include "Banks.h"
#include "Footswitches.h"
#include "SegmentDisplay.h"
#include "LED.h"
#include "SettingsButtons.h"
#include "Pots.h"

#include <Arduino.h>
#include <SPI.h>
#include "Faders.h"

#define BAUD_RATE 115200

LED leg;
Pots pots;
Faders faders;
SegmentDisplay segmentDisplay;
Banks banks(leg, segmentDisplay);
Footswitches footswitches(banks, pots, faders);
SettingsButtons settingsButtons;

void setup()
{
	Serial.begin(BAUD_RATE);
	SPI.begin();
}

void loop()
{
	footswitches.Loop();
	settingsButtons.Loop();
	faders.Loop();
}