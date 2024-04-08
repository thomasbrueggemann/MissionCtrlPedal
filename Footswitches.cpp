#include "Footswitches.h"
#include "Button2.h"

Footswitches::Footswitches(Banks &banks)
	: banks(banks), footswitch1(FOOTSWITCH_PIN_1), footswitch2(FOOTSWITCH_PIN_2), footswitch3(FOOTSWITCH_PIN_3), footswitch4(FOOTSWITCH_PIN_4)
{
}

void Footswitches::check()
{
	checkFootswitch(footswitch1, 0);
	checkFootswitch(footswitch2, 1);
	checkFootswitch(footswitch3, 2);
	checkFootswitch(footswitch4, 3);
}

void Footswitches::checkFootswitch(Button2 &footswitch, byte footswitchId)
{
	if (footswitch.wasPressed())
	{
		switch (footswitch.read())
		{
		case single_click:
			handlePress(footswitchId);
			break;
		case double_click:
			handleDoublePress(footswitchId);
			break;
		case long_click:
			handleLongPress(footswitchId);
			break;
		}
	}
};

void Footswitches::handlePress(byte footswitchId)
{
	banks.SetPreset(footswitchId);
};

void Footswitches::handleLongPress(byte footswitchId)
{
	Serial.print("Store preset for bank ");
	Serial.print(banks.GetCurrentBank());
	Serial.print(" and preset ");
	Serial.println(banks.GetCurrentPreset());

	// TODO: implement preset storing
};

void Footswitches::handleDoublePress(byte footswitchId)
{
	switch (footswitchId)
	{
	case 0:
		banks.BankDown();
		break;
	case 3:
		banks.BankUp();
		break;
	}
};