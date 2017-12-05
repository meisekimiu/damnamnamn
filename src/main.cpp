#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "../inc/fmod/inc/fmod.hpp"
#include "../inc/fmod/inc/fmod_errors.h"

#define ARG_EQUAL(val) strcmp(argv[i],val)==0
#define VERSION_NUMBER "2017-12-05--wip"

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
			printf("Karaoke @ DAMN! Signal Processor. Version %s. Konomi is best idol.\n",VERSION_NUMBER);
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
		char name[256];
		system->getRecordDriverInfo(i, name, 256, 0);
		printf("%d. %s\n",i,name);
	}
	printf("Drivers: %d\n",recordingSources);
}

int main(int argc, char** argv)
{
	parseArgs(argc,argv);
	soundTest(soundInit(32));
}
