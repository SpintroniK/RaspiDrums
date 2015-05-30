/*
 * DrumKitTest.h
 *
 *  Created on: 30 May 2015
 *      Author: jeremy
 */

#ifndef RASPIDRUMS_SOURCE_TESTING_DRUMKITTEST_H_
#define RASPIDRUMS_SOURCE_TESTING_DRUMKITTEST_H_


#include "../IO/Sensor.h"
#include "../DrumKit/Module.h"
#include "../DrumKit/Trigger.h"
#include "../Sound/Alsa.h"
#include "../Sound/Mixer.h"

#include <string>
#include <chrono>

namespace Testing
{

	class DrumKitTest
	{

	public:

		static void RunTest();

	private:

		DrumKitTest() {};
		virtual ~DrumKitTest() {};

	};


}


#endif /* RASPIDRUMS_SOURCE_TESTING_DRUMKITTEST_H_ */
