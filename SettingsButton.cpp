#include "SettingsButton.h"

SettingsButton::SettingsButton() : ampswitchButton(AMPSWITCH_BUTTON_PIN), bypassButton(BYPASS_BUTTON_PIN)
{
}

void SettingsButton::check()
{
	checkButton(ampswitchButton);
	checkButton(bypassButton);
}

void SettingsButton::checkButton(Button2 &btn)
{
	if (btn.wasPressed())
	{
		switch (btn.read())
		{
		case single_click:
			handlePress(btn);
			break;
		}
	}
};