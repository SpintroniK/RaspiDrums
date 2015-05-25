/*
 * HddSensorTest.h
 *
 *  Created on: 25 May 2015
 *      Author: jeremy
 */

#ifndef SOURCE_TESTING_HDDSENSORTEST_H_
#define SOURCE_TESTING_HDDSENSORTEST_H_

#include "../IO/HddSensor.h"

#include <string>
#include <iostream>

namespace Testing
{

	class HddSensorTest
	{

	public:

		static void RunTest();

	private:

		HddSensorTest() {};
		virtual ~HddSensorTest() {};

	};


}


#endif /* SOURCE_TESTING_HDDSENSORTEST_H_ */
