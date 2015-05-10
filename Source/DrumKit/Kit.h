/*
 * Kit.h
 *
 *  Created on: 6 May 2015
 *      Author: jeremy
 */

#ifndef SOURCE_DRUMKIT_KIT_H_
#define SOURCE_DRUMKIT_KIT_H_

#include <string>
#include <vector>

namespace DrumKit
{

	struct Drum
	{
		std::string drumName;
		std::string soundFile;

		int scanTime;

	};

	struct SoundParams
	{
		short*			data;
		int 			id;
		unsigned int	length;

	};

	struct Kit
	{

		std::string kitName;
		std::string kitFolder;

		std::vector<Drum> drum;

	};

}

#endif /* SOURCE_DRUMKIT_KIT_H_ */
