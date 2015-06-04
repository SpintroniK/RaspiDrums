/*
 * main.cpp
 *
 *  Created on: 11 Apr 2015
 *      Author: jeremy
 */

#include "Testing/DrumKitTest.h"
#include "Testing/DrumKit_HddTest.h"
#include "Testing/HddSensorTest.h"
#include "Testing/SensorTest.h"

int main(int argc, char* argv[])
{

	/* TODO: 	* 	Max velocity != 2048
	 *
	 */

	//Testing::DrumKitTest::RunTest();
	Testing::DrumKit_HddTest::RunTest();
	//Testing::HddSensorTest::RunTest();
	//Testing::SensorTest::RunTest();

	return 0;
}

