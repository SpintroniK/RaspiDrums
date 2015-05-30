/*
 * SensorTest.h
 *
 *  Created on: 25 May 2015
 *      Author: jeremy
 */

#ifndef RASPIDRUMS_SOURCE_TESTING_SENSORTEST_H_
#define RASPIDRUMS_SOURCE_TESTING_SENSORTEST_H_

#include "../IO/Sensor.h"

#include <chrono>
#include <iostream>

namespace Testing
{

	class SensorTest
	{

	public:

		static void RunTest();

	private:

		SensorTest() {};
		virtual ~SensorTest() {};

	};


}

#endif /* RASPIDRUMS_SOURCE_TESTING_SENSORTEST_H_ */
