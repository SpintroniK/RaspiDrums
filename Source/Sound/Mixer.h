/*
 * Mixer.h
 *
 *  Created on: 11 Apr 2015
 *      Author: jeremy
 */

#ifndef MIXER_H_
#define MIXER_H_

#include "AlsaParams.h"
#include "../DrumKit/Module.h"

#include <thread>
#include <chrono>

namespace Sound
{

	class Mixer
	{

	public:

		Mixer(const std::vector<DrumKit::SoundParams>& soundParams, AlsaParams& params);
		virtual ~Mixer();

		void Mix();

	private:

		const std::vector<DrumKit::SoundParams>& soundParameters;

		AlsaParams& 	alsaParams;

		unsigned int index;


	};

}

#endif /* MIXER_H_ */
