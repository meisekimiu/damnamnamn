#include "PlaybackChannel.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

PlaybackChannel::PlaybackChannel(RecordingDevice* d) {
	device = d;
	this->system = d->getSystem();
	FMOD::DSP *dspecho = 0;
	system->createDSPByType(FMOD_DSP_TYPE_ITECHO, &dspecho);
	dspecho->setParameter(FMOD_DSP_ITECHO_WETDRYMIX, 12.5f);
	dspecho->setParameter(FMOD_DSP_ITECHO_LEFTDELAY, 125);
	dspecho->setParameter(FMOD_DSP_ITECHO_RIGHTDELAY, 125);
	dspecho->setParameter(FMOD_DSP_ITECHO_FEEDBACK, 55.0f);
	system->addDSP(dspecho,0);
}

PlaybackChannel::~PlaybackChannel() {
	device->recordStop();
	delete device;
}

FMOD::Channel* PlaybackChannel::getChannel() {
	return channel;
}

void PlaybackChannel::playSound() {
	FMOD_RESULT result = device->recordStart();
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
		exit(-1);
	}
	sleep(1);
	system->playSound(FMOD_CHANNEL_FREE,device->getSound(),false,&channel);
	printf("Starting playback on device %s\n",device->getName());
}

void PlaybackChannel::update() {
	system->update();
}
