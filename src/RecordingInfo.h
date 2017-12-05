#ifndef RECORDING_INFO_H
#define RECORDING_INFO_H
#include <cstring>
FMOD_CREATESOUNDEXINFO getSoundInfo() {
	int sampleRate = 44100;
	int channels = 2;
	FMOD_CREATESOUNDEXINFO soundInfo;
	memset(&soundInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	soundInfo.cbsize            = sizeof(FMOD_CREATESOUNDEXINFO);

	// The length of the entire sample in bytes, calculated as:
	// Sample rate * number of channels * bits per sample per channel * number of seconds
	soundInfo.length            = sampleRate * channels * sizeof(unsigned short) * 0.05;

	// Number of channels and sample rate
	soundInfo.numchannels       = channels;
	soundInfo.defaultfrequency  = sampleRate;

	// The sound format (here we use 16-bit signed PCM)
	soundInfo.format            = FMOD_SOUND_FORMAT_PCM16;
	return soundInfo;
}
#endif
