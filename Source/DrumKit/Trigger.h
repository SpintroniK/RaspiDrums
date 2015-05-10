/*
 * Conditioner.h
 *
 *  Created on: 4 May 2015
 *      Author: jeremy
 */

#ifndef SOURCE_DRUMKIT_TRIGGER_H_
#define SOURCE_DRUMKIT_TRIGGER_H_

#include "Kit.h"


namespace DrumKit
{

	class Trigger
	{

	public:

		Trigger(Drum& drumParams);
		virtual ~Trigger();

		void readData(int value);

	private:

		Drum& drum;

	};



}

#endif /* SOURCE_DRUMKIT_TRIGGER_H_ */
