/*
 * main.cpp
 *
 *  Created on: 11 Apr 2015
 *      Author: jeremy
 */


#include "DrumKit/Module.h"
#include "Sound/Alsa.h"
#include "Sound/Mixer.h"

#include <unistd.h>

int main(int argc, char* argv[])
{

	std::string workingDirectory("/home/jeremy/Desktop/Prog/SnareDrum/Data/");

	DrumKit::Kit kit;

	DrumKit::Module module(workingDirectory);
	module.LoadKit(workingDirectory + "Kits/default.xml", kit);


	std::string xmlFileLoc(workingDirectory + "alsaConfig.xml");

	Sound::AlsaParams aParams;
	Sound::Alsa::ReadXmlConfig(aParams, xmlFileLoc);


	Sound::Mixer mixer(module.soundParameters, aParams);
	Sound::Alsa  alsa(aParams, mixer);

	alsa.Start();

	sleep(5);

	alsa.Stop();


	return 0;
}

