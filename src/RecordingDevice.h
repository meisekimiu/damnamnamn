#ifndef RECORDING_DEVICE_H
#define RECORDING_DEVICE_H

#include "../inc/fmod/inc/fmod.hpp"
#include "../inc/fmod/inc/fmod_errors.h"

class RecordingDevice {
public:
	RecordingDevice(FMOD::System *system,int index);
	~RecordingDevice();
	char* getName();
	int getIndex();
	FMOD::Sound* getSound();
	FMOD_RESULT recordStart();
	FMOD_RESULT recordStop();
private:
	FMOD::System* system;
	FMOD::Sound* sound;
	char* name;
	int driver_index;
};

#endif
