#ifndef SETTINGSBUTTON_H
#define SETTINGSBUTTON_H

#include "Button2.h"
#include "Pins.h"
#include <EEPROM.h>

#define AMPSWITCH_ADDRESS 2000
#define BYPASS_ADDRESS 2001

class SettingsButtons
{
public:
	SettingsButtons();
	void Check();

private:
	Button2 ampswitchButton;
	Button2 bypassButton;

	void checkButton(Button2 &btn);
	void toggleStatefulButton(byte address, byte ledPin, byte relayPin);
};

#endif // SETTINGSBUTTON_H