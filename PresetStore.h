#ifndef PRESETSTORE_H
#define PRESETSTORE_H

#include "Preset.h"

class PresetStore
{
public:
	PresetStore();

	void storePreset(byte bank, byte preset, Preset &payload);
	Preset retrievePreset(byte bank, byte preset);

private:
	int getStartingAddress(byte bank, byte preset)
};

#endif // PRESETSTORE_H