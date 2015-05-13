/*
 * Conditioner.cpp
 *
 *  Created on: 4 May 2015
 *      Author: jeremy
 */

#include "Trigger.h"

using namespace std::chrono;

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

		t0 = high_resolution_clock::now();

		return;
	}

	Trigger::~Trigger()
	{


		return;
	}


	void Trigger::Read(short value)
	{

		// Data normalisation
		short v = abs(value - mean);

		velocity = v;

		if(velocity > drum.threshold)
		{

			if(!trig)
			{

				 high_resolution_clock::time_point t = high_resolution_clock::now();
				 unsigned long long dt = (unsigned long long) duration<double, std::micro>(t - t0).count();


			}

		}


		return;
	}

}

