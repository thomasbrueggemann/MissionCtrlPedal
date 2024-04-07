#include "Banks.h"

#define MAX_BANKS 10
#define MAX_PRESETS 4

Banks::Banks()
{
	currentBank = 0;
	currentPreset = 0;
}

void Banks::setPreset(byte preset)
{
	currentPreset = preset;
}

void Banks::bankUp()
{
	currentBank = (currentBank + 1) % MAX_BANKS;
	setPreset(0);
}

void Banks::bankDown()
{
	currentBank = (currentBank - 1 + MAX_BANKS) % MAX_BANKS;
	setPreset(0);
}

byte Banks::getCurrentBank()
{
	return currentBank;
}

byte Banks::getCurrentPreset()
{
	return currentPreset;
}
