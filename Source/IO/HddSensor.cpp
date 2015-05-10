/*
 * Sensor.cpp
 *
 *  Created on: 7 May 2015
 *      Author: jeremy
 */

#include "HddSensor.h"

namespace IO
{

	HddSensor::HddSensor(std::string filePath)
	{

		file = new std::ifstream(filePath, std::ios::in);

		if(!file->good())
			throw - 1;

		return;
	}

	HddSensor::~HddSensor()
	{

		file->close();
		delete file;

		return;
	}


	/// PRIVATE

	int HddSensor::GetOutput()
	{


		return 0;
	}

}


