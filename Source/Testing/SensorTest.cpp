/*
 * SensorTest.cpp
 *
 *  Created on: 25 May 2015
 *      Author: jeremy
 */

#include "SensorTest.h"

using namespace std::chrono;

namespace Testing
{

	void SensorTest::RunTest()
	{

		int channel = 0;

		IO::Sensor sensor(channel);

		high_resolution_clock::time_point tStart = high_resolution_clock::now();
		unsigned long long dt = 0;

		do
		{
			high_resolution_clock::time_point t = high_resolution_clock::now();
			dt = (unsigned long long) duration<double, std::milli>(t - tStart).count();

			short value = sensor.GetOutput();

			std::cout << value << std::endl;

		}
		while(dt < 10*1000);

		return;
	}


}
