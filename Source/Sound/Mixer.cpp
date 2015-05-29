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

		// Prevent other threads to alter the soundList vector
		std::lock_guard<std::mutex> lock(mixerMutex);

		// Test if the sound has already been added to the mixer 
		std::vector<SoundPlay>::iterator iter =	std::find_if(soundList.begin(), soundList.end(),
				[id](const SoundPlay& sound) { return sound.id == id; });

		// Find sound's position in the vector
		size_t i = std::distance(soundList.begin(), iter);

		if(i != soundList.size())
		{
			// The sound is already in the sound list, so we need to rewind it
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

		// Prevent other threads to alter the soundList vector
		std::lock_guard<std::mutex> lock(mixerMutex);

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
