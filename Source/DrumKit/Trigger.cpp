/*
 * Conditioner.cpp
 *
 *  Created on: 4 May 2015
 *      Author: jeremy
 */

#include "Trigger.h"

namespace DrumKit
{


	Trigger::Trigger(Drum& drumParams)
	: drum(drumParams),
	  mean(2046),
	  trig(false),
	  out(false),
	  trigTime(0),
	  velocity(0),
	  maxVelocity(0)
	{

		return;
	}

	Trigger::~Trigger()
	{


		return;
	}


	void Trigger::Read(short value)
	{

		return;
	}

}

