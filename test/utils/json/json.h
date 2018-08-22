
#ifndef JSON_H
#define JSON_H

#include "utils/helpers.h"
#include <cstring>
#include <memory>

namespace Ark
{
namespace Test
{
namespace Utils
{
/**************************************************
* Ark::Utilities::JSONInterface 
*
* The purpose of this class is to serve as an
* entry point for integrating and simplifying
* integration of a JSON library
**************************************************/
class JSONInterface
{
    protected:
        JSONInterface() { }
    public:
        virtual ~JSONInterface() { }
        virtual std::string valueFor(const char *const key) = 0;
        virtual std::string valueIn(const char *const key, const char *const subkey) = 0;
        virtual std::string subvalueFor(const char *const key, int pos) = 0;
        virtual std::string subvalueNestedIn(const char *const key, const char *const subkey, const char *const nested) = 0;
        virtual std::string subarrayValueIn(const char *const key, int pos, const char *const subkey) = 0;
        virtual std::string subarrayValueNestedIn(const char *const key, int pos, const char *const subkey, const char *const nested) = 0;
};
/*************************************************/

/**************************************************************************************************/

/**************************************************
*	JSON object factory
**************************************************/
std::unique_ptr<JSONInterface> makeJSONString(std::string str);
/*************************************************/

};
};
};

#endif
