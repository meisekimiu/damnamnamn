#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <unistd.h>
#include "../inc/fmod/inc/fmod.hpp"
#include "../inc/fmod/inc/fmod_errors.h"
#include "RecordingDevice.h"
#include "PlaybackManager.h"

#define ARG_EQUAL(val) strcmp(argv[i],val)==0
#define VERSION_LABEL "wip"
#define STRING(s) #s
#define MAKE_STRING(s) STRING(s)

void parseArgs(int argc, char** argv) {
	for(int i = 1; i < argc; i++) {
		if(ARG_EQUAL("-h")||ARG_EQUAL("--help")) {
			printf("Karaoke @ DAMN! Signal Processor\n");
			printf("Usage:\n");
			printf(" %s [options]",argv[0]);
			printf("\n");
			printf("Options:\n");
			printf(" -h,--help\tDisplays this help message\n");
			printf(" -v,--version\tDisplays version information\n");
			exit(EXIT_SUCCESS);
		}
		if(ARG_EQUAL("-v")||ARG_EQUAL("--version")) {
			printf("Karaoke @ DAMN! Signal Processor.\nVersion %s-%s-%s.\n\nKonomi is best idol.\n",MAKE_STRING(GIT_COMMIT_HASH),VERSION_LABEL,MAKE_STRING(GIT_BRANCH));
			exit(EXIT_SUCCESS);
		}
	}
}

void errCheck(FMOD_RESULT result)
{
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
		exit(-1);
	}
	return;
}

FMOD::System* soundInit(int channels)
{
	FMOD::System *system;
	FMOD_RESULT result = FMOD::System_Create(&system);
	errCheck(result);
	result = system->init(channels, FMOD_INIT_NORMAL,0);
	errCheck(result);
	return system;
}

void soundTest(FMOD::System *system) {
	int recordingSources = 0;
	FMOD_RESULT result = system->getRecordNumDrivers(&recordingSources);
	errCheck(result);
	for(int i = 0; i < recordingSources; i++) {
		RecordingDevice* d = new RecordingDevice(i);
		printf("%d. %s\n",d->getIndex(),d->getName());
		delete d;
	}
	printf("Drivers: %d\n",recordingSources);
	RecordingDevice* device = new RecordingDevice(4);
	RecordingDevice* device_b = new RecordingDevice(2);
	PlaybackManager* karaoke = new PlaybackManager();
	karaoke->addRecordingDevice(device_b);
	karaoke->addRecordingDevice(device);
	karaoke->startPlayback();
	while(true) {
		karaoke->update();
	}
	delete karaoke;

}

int main(int argc, char** argv)
{
	parseArgs(argc,argv);
	soundTest(soundInit(32));
}
