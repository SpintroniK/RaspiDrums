/*
 * Mixer.cpp
 *
 *  Created on: 11 Apr 2015
 *      Author: jeremy
 */

#include "Mixer.h"

namespace Sound
{

	Mixer::Mixer(const std::vector<DrumKit::SoundParams>& soundParams, AlsaParams& params)
	: soundParameters(soundParams),
	  alsaParams(params),
	  index(0)
	{

		return;
	}

	Mixer::~Mixer()
	{


		return;
	}


	void Mixer::Mix()
	{

		for(int i = 0; i < alsaParams.periodSize; i++)
		{
			alsaParams.buffer[i] = //soundParameters[1].data[alsaParams.bufferSize + i + index]/2
								 soundParameters[0].data[alsaParams.periodSize + i + index]*10;
		}

		index += alsaParams.periodSize;
		if(index >= soundParameters[0].length) index = 0;

		return;
	}



}
