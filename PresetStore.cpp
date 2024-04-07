#include "PresetStore.h"

#include <EEPROM.h>

/*

EEPROM address format
----------------------
0 = cut, preset 0, bank 0
1 = bass
2 = mid
3 = treble
4 = boost
5 = ampswitch
6 = cut, preset 1, bank 0
7 = ...

*/

PresetStore::PresetStore()
{
}

void PresetStore::storePreset(byte bank, byte preset, Preset &payload)
{
}

Preset PresetStore::retrievePreset(byte bank, byte preset)
{
	Preset p;

	EEPROM.get(eeAddress, f);

	return p;
}