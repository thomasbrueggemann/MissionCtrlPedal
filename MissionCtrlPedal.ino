#include "Banks.h"
#include "Footswitches.h"
#include "SegmentDisplay.h"

#define BAUD_RATE 115200

LED leg;
SegmentDisplay segmentDisplay;
Banks banks(leg, segmentDisplay);
Footswitches footswitches(banks);

void setup()
{
	Serial.begin(BAUD_RATE);
}

void loop()
{
	footswitches.check();

	delay(10);
}