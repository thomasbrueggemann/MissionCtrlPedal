#include "PresetBanks.h"

#define MAX_BANKS 10
#define MAX_PRESETS 4

PresetBanks::PresetBanks()
{
	currentBank = 0;
	currentPreset = 0;
}

void PresetBanks::setPreset(byte preset)
{
	currentPreset = preset;
}

void PresetBanks::bankUp()
{
	currentBank = (currentBank + 1) % MAX_BANKS;
}

void PresetBanks::bankDown()
{
	currentBank = (currentBank - 1 + MAX_BANKS) % MAX_BANKS;
}

byte PresetBanks::getCurrentBank()
{
	return currentBank;
}

byte PresetBanks::getCurrentPreset()
{
	return currentPreset;
}
