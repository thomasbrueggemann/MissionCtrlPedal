#include "SettingsButtons.h"

SettingsButtons::SettingsButtons() : ampswitchButton(AMPSWITCH_BUTTON_PIN), bypassButton(BYPASS_TYPE_BUTTON_PIN)
{
	byte ampSwitchState = EEPROM.read(AMPSWITCH_ADDRESS);
	digitalWrite(AMPSWITCH_LED_PIN, ampSwitchState);

	byte bypassState = EEPROM.read(BYPASS_ADDRESS);
	digitalWrite(BYPASS_TYPE_LED_PIN, bypassState);
}

void SettingsButtons::check()
{
	checkButton(ampswitchButton);
	checkButton(bypassButton);
}

void SettingsButtons::checkButton(Button2 &btn)
{
	if (btn.wasPressed())
	{
		switch (btn.read())
		{
		case single_click:
			if (btn.getPin() == AMPSWITCH_BUTTON_PIN)
			{
				toggleStatefulButton(AMPSWITCH_ADDRESS, AMPSWITCH_LED_PIN, AMPSWITCH_RELAY_PIN);
			}
			else if (btn.getPin() == BYPASS_TYPE_BUTTON_PIN)
			{
				toggleStatefulButton(BYPASS_ADDRESS, BYPASS_TYPE_LED_PIN, BYPASS_TYPE_RELAY_PIN);
			}

			break;
		}
	}
}

void SettingsButtons::toggleStatefulButton(byte address, byte ledPin, byte relayPin)
{
	byte state = EEPROM.read(address);
	state = !state;
	EEPROM.update(address, state);

	digitalWrite(ledPin, state);
	digitalWrite(relayPin, state);
};