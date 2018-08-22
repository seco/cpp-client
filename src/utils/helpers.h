

#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <cstring>

#if (defined ARDUINO || defined ESP8266 || defined ESP32)

#define USE_IOT

#include <Arduino.h>
#include <pgmspace.h>

	const static inline std::string toString(int integer)
	{
		return String(integer).c_str();
	}

#else

	static std::string toString(int integer)
	{
		return std::to_string(integer);
	}

#endif

#endif
