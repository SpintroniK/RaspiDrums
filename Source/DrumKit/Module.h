/*
 * Drum.h
 *
 *  Created on: 6 May 2015
 *      Author: jeremy
 */

#ifndef SOURCE_DRUMKIT_MODULE_H_
#define SOURCE_DRUMKIT_MODULE_H_

#include "Kit.h"

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlmemory.h>

#include <fstream>
#include <vector>
#include <string>


namespace DrumKit
{

	class Module
	{

	public:

		Module();
		Module(std::string dir);
		virtual ~Module();

		void LoadKit(std::string fileLoc, Kit& kit);

		const std::vector<SoundParams>& soundParameters;

	private:

		bool GetDrumParams(xmlNode* drumName, std::vector<Drum>& drum, int drumId);
		void AddSound(std::string fileLocation, int soundId);

		std::string directory;
		std::vector<SoundParams> sndParams;


	};

}

#endif /* SOURCE_DRUMKIT_MODULE_H_ */
