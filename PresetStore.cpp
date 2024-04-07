#include "PresetStore.h"

#include <EEPROM.h>

#define NUM_PRESETS_PER_BANK 4
#define NUM_BYTES_PER_PRESET 12

#define CUT_ADDRESS 0
#define BASS_ADDRESS 1
#define MIDDLE_ADDRESS 2
#define TREBLE_ADDRESS 3
#define BOOST_ADDRESS 4
#define AMPSWITCH_ADDRESS 5

/*

EEPROM address format
----------------------
0 = cut, preset 0, bank 0
1 = bass
2 = mid
3 = treble
4 = boost
5 = ampswitch
6 reserved
7 reserved
8 reserved
9 reserved
10 = cut, preset 1, bank 0
11 = ...

*/

PresetStore::PresetStore()
{
}

void PresetStore::storePreset(byte bank, byte preset, Preset &payload)
{
	int startingAddress = getStartingAddress(bank, preset);

	EEPROM.update(startingAddress + CUT_ADDRESS, payload.Cut);
	EEPROM.update(startingAddress + BASS_ADDRESS, payload.Bass);
	EEPROM.update(startingAddress + MIDDLE_ADDRESS, payload.Middle);
	EEPROM.update(startingAddress + TREBLE_ADDRESS, payload.Treble);
	EEPROM.update(startingAddress + BOOST_ADDRESS, payload.Boost);
	EEPROM.update(startingAddress + AMPSWITCH_ADDRESS, payload.AmpSwitch);
}

Preset PresetStore::retrievePreset(byte bank, byte preset)
{
	Preset p;

	int startingAddress = getStartingAddress(bank, preset);
	EEPROM.get(startingAddress + CUT_ADDRESS, p.Cut);
	EEPROM.get(startingAddress + BASS_ADDRESS, p.Bass);
	EEPROM.get(startingAddress + MIDDLE_ADDRESS, p.Middle);
	EEPROM.get(startingAddress + TREBLE_ADDRESS, p.Treble);
	EEPROM.get(startingAddress + BOOST_ADDRESS, p.Boost);
	EEPROM.get(startingAddress + AMPSWITCH_ADDRESS, p.AmpSwitch);

	return p;
}

int PresetStore::getStartingAddress(byte bank, byte preset)
{
	int startingAddress = (bank * NUM_PRESETS_PER_BANK + preset) * NUM_BYTES_PER_PRESET;
	return startingAddress;
}