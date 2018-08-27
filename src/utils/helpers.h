

#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <cstring>

#if (defined ARDUINO || defined ESP8266 || defined ESP32)

#define USE_IOT

// undef the C macros to allow the C++ STL to take over
// This is to have compatibility with various board implementations of the STL
#undef min
#undef max

#include <Arduino.h>
#include <pgmspace.h>

    const static inline std::string toString(int integer)
    {
        return String(integer).c_str();
    }

#else

<<<<<<< HEAD
#include <sstream>

    template <typename T>
    std::string toString(T val) {
        std::stringstream stream;
        stream << val;
        return stream.str();
=======
    static std::string toString(int integer)
    {
        return std::to_string(integer);
>>>>>>> parent of 878b983... rewrite json dependency
    }

#endif

#endif
