#include "ArduinoApp.h"
#include "Logger.h"
#include "I2C.h"

#include <Wire.h>

namespace Pamux
{
	I2C I2C::instance;

	void I2C::setupImpl()
	{
		Wire.begin(PIN_SDA, PIN_SCL);		
	}


	void I2C::transmit(uint8_t i2cAddress, uint32_t value)
	{
		byte data[4] = {
			((byte)(value >> 16)) & (byte)0x0f,
			(byte)(value >> 16),
			(byte)(value >> 8),
			(byte)value
		};

		transmit(i2cAddress, 4, data);
	}

	void I2C::transmit(uint8_t i2cAddress, uint16_t itemCount, uint8_t* items)
	{
		Wire.beginTransmission(i2cAddress);

		for (auto i = 0; i < itemCount; ++i)
		{
			Wire.write(items[i]);
		}

		Wire.endTransmission();
	}
	/*
	
	0:success 
1:data too long to fit in transmit buffer 
2:received NACK on transmit of address 
3:received NACK on transmit of data 
4:other error 

*/
	void I2C::scan()
	{		
		Logger::PrintLn("I2C scan");

		uint8_t error, address;
		int nDevices;

		
		nDevices = 0;
		for (address = 1; address < 127; address++)
		{
			

			// The i2c scanner uses the return value of
			// the Write.endTransmission to see if
			// a device did acknowledge to the address.
			Wire.beginTransmission(address);
			error = Wire.endTransmission();
			
			/*Logger::PrintHex(error);
			Logger::Print(" - ");
			Logger::PrintHexLn(address);*/

			if (error == 0)
			{
				Logger::Print("I2C device found at address 0x");
				if (address < 16) {
					Logger::Print("0");
				}
				Logger::PrintHex(address);
				Logger::PrintLn(" !");

				nDevices++;
			}
			else if (error == 4)
			{
				Logger::Print("Unknown error at address 0x");
				if (address < 16) {
					Logger::Print("0");
				}
				Logger::PrintHexLn(address);
			}
		}
		if (nDevices == 0) {
			Logger::PrintLn("No I2C devices found\n");
		}
		else {
			Logger::PrintLn("Done.\n");
		}

	}

}