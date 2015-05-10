/*
 * Sensor.h
 *
 *  Created on: 7 May 2015
 *      Author: jeremy
 */

#ifndef SOURCE_IO_HDDSENSOR_H_
#define SOURCE_IO_HDDSENSOR_H_


#include <fstream>
#include <string>


namespace IO
{

	class HddSensor
	{

	public:

		HddSensor(std::string filePath);
		~HddSensor();

		int GetOutput();

	private:

		std::ifstream* file;

	};

}

#endif /* SOURCE_IO_HDDSENSOR_H_ */
