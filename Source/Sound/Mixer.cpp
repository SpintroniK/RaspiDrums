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

	void Mixer::AddToMixer(int id, float volume)
	{

		// Prevent other threads to alter the soundList vector
		std::lock_guard<std::mutex> lock(mixerMutex);

		/*
		 * Not needed anymore, but left here as a reminder
		 *
		 * // Test if the sound has already been added to the mixer
		std::vector<SoundInfo>::iterator iter =	std::find_if(soundList.begin(), soundList.end(),
				[id](const SoundInfo& sound) { return sound.id == id; });

		// Find sound's position in the vector
		size_t i = std::distance(soundList.begin(), iter);

		if(i != soundList.size())
		{
			// The sound is already in the sound list, so we need to rewind it
			soundList[i].index = 0;
			// We also have to make sure to play the sound with the new volume
			soundList[i].volume = volume;

		}
		else*/
		{
			// The sound needs to be added to the sound list

			SoundInfo sound;

			sound.id = id;
			sound.index = 0;
			sound.volume = volume;

			soundList.push_back(sound);
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

			std::vector<size_t> soundsToDelete;

			// Browse sound list
			for(size_t id = 0; id < soundList.size(); id++)
			{

				int soundId = soundList[id].id;
				int soundIndex = soundList[id].index;

				// Mix sound
				for(int i = 0; i < alsaParams.periodSize; i++)
				{
					alsaParams.buffer[i] += soundList[id].volume * soundParameters[soundId].data[soundIndex + i];
				}

				// Update sound index
				soundList[id].index += alsaParams.periodSize;

				// Reached the end of the sound sample, so delete it from the vector
				if(soundList[id].index >= soundParameters[soundId].length)
				{
					soundsToDelete.push_back(id);
				}
			}

			if(!soundsToDelete.empty())
			{
				std::vector<SoundInfo> temp;
				temp.reserve(soundList.size() - soundsToDelete.size());

				std::sort(soundsToDelete.begin(), soundsToDelete.end());

				std::vector<SoundInfo>::iterator itBlockBegin = soundList.begin();

				for(std::vector<size_t>::iterator it = soundsToDelete.begin(); it != soundsToDelete.end(); ++it)
				{
					std::vector<SoundInfo>::iterator itBlockEnd = soundList.begin() + *it;
					if(itBlockBegin != itBlockEnd)
					{
						std::copy(itBlockBegin, itBlockEnd, std::back_inserter(temp));
					}
					itBlockBegin = itBlockEnd + 1;
				}

				// copy last block.
				if(itBlockBegin != soundList.end())
				{
					std::copy(itBlockBegin, soundList.end(), std::back_inserter(temp));
				}

				soundList.swap(temp);

			}

		}

		return;
	}




}
