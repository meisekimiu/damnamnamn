#ifndef PLAYBACK_MANAGER_H
#define PLAYBACK_MANAGER_H

#include "../inc/fmod/inc/fmod.hpp"
#include "../inc/fmod/inc/fmod_errors.h"
#include "PlaybackChannel.h"
#include <vector>

class PlaybackManager {
public:
	PlaybackManager();
	~PlaybackManager();
	void addRecordingDevice(RecordingDevice* device);
	void startPlayback();
	void update();
private:
	std::vector<PlaybackChannel*> channels;
};

#endif
