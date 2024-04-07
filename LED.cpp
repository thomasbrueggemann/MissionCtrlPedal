#include "LED.h"

#define LED_PIN_1 2
#define LED_PIN_2 3
#define LED_PIN_3 4
#define LED_PIN_4 5

void LED::TurnOn(byte ledId)
{
	int ledPins[] = {LED_PIN_1, LED_PIN_2, LED_PIN_3, LED_PIN_4};

	for (int i = 0; i < 4; i++)
	{
		if (i == ledId)
		{
			digitalWrite(ledPins[i], HIGH);
		}
		else
		{
			digitalWrite(ledPins[i], LOW);
		}
	}
}