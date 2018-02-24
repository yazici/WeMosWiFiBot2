#ifndef COMMON_H
#define COMMON_H

#include "Arduino.h"

const uint8_t PIN_SCL = D1;
const uint8_t PIN_SDA = D2;

const uint16_t serialBaudRateLow = 9600;
const uint16_t serialBaudRate = 115200;

#define abstract
#define override virtual
#define pure  = 0

#endif