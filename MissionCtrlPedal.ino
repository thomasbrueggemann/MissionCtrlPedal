#include "Button2.h"
#include "PresetBanks.h"

#define BAUD_RATE 115200
#define LONG_PRESS_TIME 800

#define BUTTON_PIN_A 2
#define BUTTON_PIN_B 3

PresetBanks presetBanks;
Button2 buttonA(BUTTON_PIN_A), buttonB(BUTTON_PIN_B);

void handlePress(Button2 &btn)
{
	if (btn == buttonA)
	{
		Serial.println("A pressed");
	}
	else if (btn == buttonB)
	{
		Serial.println("B pressed");
	}
}

void handleLongClick(Button2 &btn)
{
	if (btn == buttonA)
	{
		Serial.println("A long pressed");
	}
	else if (btn == buttonB)
	{
		Serial.println("B long pressed");
	}
}

void handleDoubleClick(Button2 &btn)
{
	if (btn == buttonA)
	{
		Serial.println("A double pressed");
	}
	else if (btn == buttonB)
	{
		Serial.println("B double pressed");
	}
}

void setup()
{
	Serial.begin(BAUD_RATE);

	buttonA.setLongClickTime(LONG_PRESS_TIME);
	buttonA.setPressedHandler(handlePress);
	buttonA.setLongClickDetectedHandler(handleLongClick);
	buttonA.setDoubleClickHandler(handleDoubleClick);

	buttonB.setLongClickTime(LONG_PRESS_TIME);
	buttonB.setPressedHandler(handlePress);
	buttonB.setLongClickDetectedHandler(handleLongClick);
	buttonB.setDoubleClickHandler(handleDoubleClick);
}

void loop()
{
	buttonA.loop();
	buttonB.loop();

	delay(10);
}