/*
 * Conditioner.h
 *
 *  Created on: 4 May 2015
 *      Author: jeremy
 */

#ifndef SOURCE_DRUMKIT_TRIGGER_H_
#define SOURCE_DRUMKIT_TRIGGER_H_

#include "Kit.h"

#include <chrono>
#include <iostream>

#include <math.h>

using namespace std::chrono;

namespace DrumKit
{

	class Trigger
	{

	public:

		Trigger(Drum& drumParams);
		virtual ~Trigger();

		void Read(short value);
		bool GetState() const { return trig; }

	private:

		Drum& drum;

		high_resolution_clock::time_point t0;

		short mean;

		bool trig;
		bool out;

		long long trigTime;

		short velocity;
		short maxVelocity;

	};



}

#endif /* SOURCE_DRUMKIT_TRIGGER_H_ */
