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

		file = new std::ifstream(filePath, std::ios::in|std::ifstream::binary);

		if(!file->good())
			throw - 1;

		short val;

		while(file->read((char*)&val, sizeof(short)))
			value.push_back(val);

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


