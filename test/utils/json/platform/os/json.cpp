

#include "platform/platform.h"

#ifndef USE_IOT

#include "test/utils/json/json.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;
#include <cstring>

namespace ARK
{
namespace Test
{
namespace Utils
{
/**************************************************
*
**************************************************/
struct JSON : public JSONInterface
{
    private:
        json _json;

    public:
        /**************************************************
        * Constructor
        **************************************************/
        JSON(std::string _jsonStr)
            :	_json(json::parse(_jsonStr)) {}
        /*************************************************/

        /*************************************************/

        /**************************************************
        * valueFor(key)
        *
        * { "key1": value1, "key2": value2 }
        **************************************************/
        std::string valueFor(
                const char *const key
        ) override {
            const auto& forKey = _json[key];
            return getValue(forKey);
        };
        /*************************************************/

        /**************************************************
        * valueIn(key, subkey)
        *
        * { "key": { "subkey": subvalue } }
        **************************************************/
        std::string valueIn(
                const char *const key,
                const char *const subkey
        ) override {
            const auto& forKey = _json[key][subkey];
            return getValue(forKey);
        };
        /*************************************************/

        /**************************************************
        * subvalueFor(key, position)
        *
        * { "key": { subValue1, subvalue2 } }
        **************************************************/
        std::string subvalueFor(
                const char *const key,
                int pos
        ) override {
            const auto& forKey = _json[key][pos];
            return getValue(forKey);
        };
        /*************************************************/



        std::string subvalueNestedIn(
                const char *const key,
                const char *const subkey,
                const char *const nested
        ) override {
            const auto& forKey = _json[key][subkey][nested];
            return getValue(forKey);
        };



        /**************************************************
        * subarrayValueIn(key, position, subkey)
        *
        * { "key": [ { "subkey": subvalue } ] }
        **************************************************/
        std::string subarrayValueIn(
                const char *const key,
                int pos,
                const char *const subkey
        ) override {
            const auto& forKey = _json[key][pos][subkey];
            return getValue(forKey);
        };
        /*************************************************/


        std::string subarrayValueNestedIn(
                const char *const key,
                int pos,
                const char *const subkey,
                const char *const nested
        ) override {
            const auto& forKey = _json[key][pos][subkey][nested];
            return getValue(forKey);
        };


        private:
        /*************************************************/
        std::string getValue(
                const json& j
        ) const {
            if ( j.is_string() ) { return j.get<std::string>(); }
            std::ostringstream ss;
            ss << j;
            std::string jStr = ss.str();
            return jStr;
        }
        /*************************************************/	

};

/*************************************************/
std::unique_ptr<JSONInterface> makeJSONString(
		std::string json_str
) {
	return std::unique_ptr<JSONInterface>(new JSON(json_str));
}
/*************************************************/

};
};
};

#endif
