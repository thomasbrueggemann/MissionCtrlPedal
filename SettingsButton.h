#ifndef SETTINGSBUTTON_H
#define SETTINGSBUTTON_H

#include "Button2.h"

#define AMPSWITCH_BUTTON_PIN 44
#define AMPSWITCH_LED_PIN 45
#define BYPASS_BUTTON_PIN 46
#define BYPASS_LED_PIN 47

class SettingsButton
{
public:
	SettingsButton();
	void check();

private:
	Button2 ampswitchButton;
	Button2 bypassButton;

	void checkButton(Button2 &btn);
};

#endif // SETTINGSBUTTON_H