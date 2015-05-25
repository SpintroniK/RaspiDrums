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

		// Test if sound is already in the mixer (need to include <algorithm>)
		std::vector<SoundPlay>::iterator iter =	std::find_if(soundList.begin(), soundList.end(),
				[id](const SoundPlay& sound) { return sound.id == id; });

		// If the sound exists in the list, find its index
		size_t i = std::distance(soundList.begin(), iter);

		if(i != soundList.size())
		{
			// The sound is already in the sound list, so we set its playing index to zero to restart it
			soundList[i].index = 0;

		}
		else
		{
			// The sound needs to be added to the sound list

			SoundPlay soundToPlay;

			soundToPlay.id = id;
			soundToPlay.index = 0;

			soundList.push_back(soundToPlay);
		}

		return;
	}


	void Mixer::Mix()
	{


		// Fill buffer with zeros
		std::fill(alsaParams.buffer, alsaParams.buffer + alsaParams.periodSize, 0);

		// If there are sounds to mix
		if(soundList.size() > 0)
		{
			// Browse sound list
			for(size_t id = 0; id < soundList.size(); id++)
			{
				// Mix sound
				for(int i = 0; i < alsaParams.periodSize; i++)
				{
					alsaParams.buffer[i] += soundParameters[id].data[soundList[id].index + i];
				}

				// Update sound index
				soundList[id].index += alsaParams.periodSize;

				// Reached the end of the sound sample, so delete it from the vector
				if(soundList[id].index >= soundParameters[id].length)
				{
					soundList.erase(soundList.begin() + id);
				}
			}
		}



		return;
	}




}
