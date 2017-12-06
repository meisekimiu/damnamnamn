#include "RecordingDevice.h"
#include "RecordingInfo.h"
#include <cstring>
#include <stdio.h>

RecordingDevice::RecordingDevice(int index) {
	// this->system = system;
	FMOD_RESULT result = FMOD::System_Create(&system);
	result = system->init(32, FMOD_INIT_NORMAL,0);
	driver_index = index;
	char temp[256];
	system->getRecordDriverInfo(index, temp, 256, 0);
	size_t name_size = strlen(temp)+1;
	name = new char[name_size];
	std::memcpy(name,temp,name_size);
	FMOD_CREATESOUNDEXINFO soundInfo = getSoundInfo();
	system->createSound(0, FMOD_SOFTWARE | FMOD_LOOP_NORMAL | FMOD_OPENUSER, &soundInfo, &sound);
}

RecordingDevice::~RecordingDevice() {
	delete name;
	sound->release();
	system->release();
}

char* RecordingDevice::getName() {
	return name;
}

int RecordingDevice::getIndex() {
	return driver_index;
}

FMOD::System* RecordingDevice::getSystem() {
	return system;
}

FMOD::Sound* RecordingDevice::getSound() {
	return sound;
}

FMOD_RESULT RecordingDevice::recordStart() {
	printf("Starting record on Device %d (%s)\n",driver_index,name);
	return system->recordStart(driver_index,sound,true);
}

FMOD_RESULT RecordingDevice::recordStop() {
	printf("Stopping record on Device %d (%s)\n",driver_index,name);
	return system->recordStop(driver_index);
}
