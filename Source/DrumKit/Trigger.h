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

#include <math.h>

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

		short mean;

		bool trig;
		bool out;

		long long trigTime;

		short velocity;
		short maxVelocity;

	};



}

#endif /* SOURCE_DRUMKIT_TRIGGER_H_ */
