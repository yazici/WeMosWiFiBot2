#ifndef I2C_H
#define I2C_H

#include "Object.h"

namespace Pamux
{
	class I2C : public Object
	{
	public:
		static I2C instance;

		static void Setup()
		{
			instance.setup();
		}

	public:
		override void setupImpl();
		// override void loopImpl();

	public:
		void scan();

	public:
		void transmit(uint8_t i2cAddress, uint32_t value);
		void transmit(uint8_t i2cAddress, uint16_t itemCount, uint8_t* items);
	};
}


#endif