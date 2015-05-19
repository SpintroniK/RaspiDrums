/*
 * Mixer.cpp
 *
 *  Created on: 11 Apr 2015
 *      Author: jeremy
 */

#include "Mixer.h"

namespace Sound
{

	Mixer::Mixer(const std::vector<DrumKit::SoundParams>& soundParams, const AlsaParams& params)
	: soundParameters(soundParams),
	  alsaParams(params)
	{

		return;
	}

	Mixer::~Mixer()
	{


		return;
	}

	void Mixer::AddToMixer(int id)
	{

		SoundPlay soundToPlay;

		soundToPlay.id = id;
		soundToPlay.index = 0;

		soundList.push_back(soundToPlay);

		return;
	}


	void Mixer::Mix()
	{


		if(soundList.size() == 0)
		{
			// No sound to mix, fill with zeros
			for(int i = 0; i < alsaParams.periodSize; i++)
			{
				alsaParams.buffer[i] = 0;
			}

		}
		else
		{




		}



		return;
	}




}
