/*
 * DrumKitTest.cpp
 *
 *  Created on: 30 May 2015
 *      Author: jeremy
 */

#include "DrumKitTest.h"

using namespace std::chrono;

namespace Testing
{

	void DrumKitTest::RunTest()
	{


		std::string workingDirectory("/home/jeremy/Desktop/Prog/SnareDrum/Data/");
		std::string kitLocation(workingDirectory + "Kits/default.xml");


		DrumKit::Kit kit;

		DrumKit::Module module(workingDirectory);
		module.LoadKit(kitLocation, kit);


		std::string xmlFileLoc(workingDirectory + "alsaConfig.xml");

		Sound::AlsaParams aParams;
		Sound::Alsa::ReadXmlConfig(aParams, xmlFileLoc);


		Sound::Mixer mixer(module.soundParameters, aParams);
		Sound::Alsa  alsa(aParams, mixer);

		std::string sensorFile(workingDirectory + "../out.raw");

		int channel = 0;
		IO::Sensor sensor(channel);

		DrumKit::Trigger snareTrigger(kit.drum[0], mixer);

		alsa.Start();

		high_resolution_clock::time_point tStart = high_resolution_clock::now();
		unsigned long long dt = 0;

		do
		{
			high_resolution_clock::time_point t = high_resolution_clock::now();
			dt = (unsigned long long) duration<double, std::milli>(t - tStart).count();


			short value = sensor.GetOutput();
			snareTrigger.Trig(value);

		}
		while(dt < 10*1000);


		alsa.Stop();


		return;
	}


}


