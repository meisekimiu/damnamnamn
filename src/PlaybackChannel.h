#ifndef PLAYBACK_CHANNEL_H
#define PLAYBACK_CHANNEL_H

#include "../inc/fmod/inc/fmod.hpp"
#include "../inc/fmod/inc/fmod_errors.h"
#include "RecordingDevice.h"

class PlaybackChannel {
public:
	PlaybackChannel(RecordingDevice* d);
	~PlaybackChannel();
	FMOD::Channel* getChannel();
	void playSound();
	void update();
private:
	FMOD::System* system;
	FMOD::Channel* channel;
	RecordingDevice* device;
};

#endif
