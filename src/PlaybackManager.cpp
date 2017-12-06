#include "PlaybackManager.h"
#include <unistd.h>

PlaybackManager::PlaybackManager() {
}

PlaybackManager::~PlaybackManager() {
	for(std::vector<PlaybackChannel*>::iterator it = channels.begin(); it!=channels.end(); ++it) {
		delete *it;
	}
}

void PlaybackManager::addRecordingDevice(RecordingDevice* device) {
	PlaybackChannel* channel = new PlaybackChannel(device);
	channels.push_back(channel);
}

void PlaybackManager::startPlayback() {
	for(std::vector<PlaybackChannel*>::iterator it = channels.begin(); it!=channels.end(); ++it) {
		(*it)->playSound();
	}
}

void PlaybackManager::update() {
	for(std::vector<PlaybackChannel*>::iterator it = channels.begin(); it!=channels.end(); ++it) {
		(*it)->update();
	}
}
