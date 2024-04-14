#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include "Pins.h"

class LED
{
public:
	void TurnOn(byte ledId);
};

#endif // LED_H