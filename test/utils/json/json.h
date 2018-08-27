


#ifndef JSON_H
#define JSON_H

#define ARDUINOJSON_USE_LONG_LONG 1
#define ARDUINOJSON_USE_ARDUINO_STRING 0

#include <ArduinoJson.h>
#include "utils/helpers.h"
#include <cstring>
#include <memory>
#include <string>

namespace Ark
{
namespace Test
{
namespace Utils
{
/**************************************************
*
**************************************************/
struct JSON
{
    private:
        std::string jsonStr_;

    protected:
        JSON() { }

    public:
        JSON(std::string jsonString);
        ~JSON(){}

        JsonObject& getRoot();
};
/*************************************************/

/**************************************************
*	JSON object factory
**************************************************/
std::unique_ptr<JSON> JSONParser(std::string newJsonStr);
/*************************************************/

};
};
};

#endif
