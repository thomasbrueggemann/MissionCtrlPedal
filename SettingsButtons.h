#ifndef SETTINGSBUTTON_H
#define SETTINGSBUTTON_H

#include "Button2.h"
#include <EEPROM.h>

#define AMPSWITCH_BUTTON_PIN 44
#define AMPSWITCH_LED_PIN 45
#define AMPSWITCH_ADDRESS 2000
#define AMPSWITCH_RELAY_PIN 48

#define BYPASS_BUTTON_PIN 46
#define BYPASS_LED_PIN 47
#define BYPASS_ADDRESS 2001
#define BYPASS_RELAY_PIN 49

class SettingsButtons
{
public:
	SettingsButtons();
	void check();

private:
	Button2 ampswitchButton;
	Button2 bypassButton;

	void checkButton(Button2 &btn);
	void toggleStatefulButton(byte address, byte ledPin, byte relayPin);
};

#endif // SETTINGSBUTTON_H