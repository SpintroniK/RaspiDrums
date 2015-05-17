/*
 * main.cpp
 *
 *  Created on: 11 Apr 2015
 *      Author: jeremy
 */


#include "IO/HddSensor.h"
#include "DrumKit/Module.h"
#include "DrumKit/Trigger.h"
#include "Sound/Alsa.h"
#include "Sound/Mixer.h"

#include <string>
#include <chrono>

using namespace std::chrono;

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

	std::string sensorFile("/home/jeremy/Desktop/Prog/SnareDrum/out.raw");

	IO::HddSensor hddSensor(sensorFile);
	DrumKit::Trigger snareTrigger(kit.drum[0]);

	alsa.Start();

	int N = 800000;

	for(int i = 0; i < N; i++)
	{

		short value = hddSensor.GetOutput();
		snareTrigger.Trig(value);

	}

	alsa.Stop();


	return 0;
}

