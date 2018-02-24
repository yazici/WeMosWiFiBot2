#ifndef OBJECT_H
#define OBJECT_H

#include "Common.h"

namespace Pamux
{
	abstract class Object
	{
	protected:
		bool isSetup;
		
	public:
		Object();
		virtual ~Object();

	public:
		void setup()
		{
			if (!isSetup)
			{
				isSetup = true;
				setupImpl();
			}
		}

		void loop()
		{
			loopImpl();
		}

		virtual void setupImpl()
		{
		}

		virtual void loopImpl()
		{
		}
	};
}

#endif