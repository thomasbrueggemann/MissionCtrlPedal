#ifndef PRESETSTORE_H
#define PRESETSTORE_H

#include "Preset.h"

class PresetStore
{
public:
	PresetStore();

	void writePreset(byte bank, byte preset, Preset &payload);
	Preset readPreset(byte bank, byte preset);

private:
	int getStartingAddress(byte bank, byte preset)
};

#endif // PRESETSTORE_H