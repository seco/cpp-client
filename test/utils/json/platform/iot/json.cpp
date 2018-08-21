

#include "utils/json/json.h"
#include "ArduinoJson.h"
#include <cstring>
#include <memory>

namespace ARK
{
namespace Test
{
namespace Utils
{
/**************************************************
*
**************************************************/
struct JSON :
    public JSONInterface
{
    private:
        static const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;

        std::string jsonStr;

    public:
        /**************************************************
        *
        **************************************************/
        JSON(std::string _jsonStr) { jsonStr = _jsonStr; }
        /*************************************************/


        std::string value(
                std::vector<const char*> keys
        ) override {
            DynamicJsonBuffer jsonBuffer(capacity);
            JsonObject &root = jsonBuffer.parseObject(this->jsonStr.c_str());
            std::string value;
            switch (keys.size()) { // 
                case 1: value = std::string(root[key[0]].as<const char*>()) break;
                case 2: value = std::string(root[key[0]][key[1]].as<const char*>()) break;
                case 3: value = std::string(root[key[0]][key[1]][key[2]].as<const char*>()) break;
                case 4: value = std::string(root[key[0]][key[1]][key[2]][key[3]].as<const char*>()) break;
                case 5: value = std::string(root[key[0]][key[1]][key[2]][key[3]][key[4]].as<const char*>()) break;
                case 6: value = std::string(root[key[0]][key[1]][key[2]][key[3]][key[4]][key[5]].as<const char*>()) break;
                default: value = "";
            }
            return value;
        };

        /**************************************************
        * valueFor(key)
        *
        * { "key1": value1, "key2": value2 }
        **************************************************/
        std::string valueFor(
                const char *const key
        ) override {
            DynamicJsonBuffer jsonBuffer(capacity);
            JsonObject &root = jsonBuffer.parseObject(this->jsonStr.c_str());
            return std::string(root[key].as<const char*>());
        }
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
            DynamicJsonBuffer jsonBuffer(capacity);
            JsonObject &root = jsonBuffer.parseObject(this->jsonStr.c_str());
            return std::string(root[key][subkey].as<const char*>());
        }
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
            DynamicJsonBuffer jsonBuffer(capacity);
            JsonObject &root = jsonBuffer.parseObject(this->jsonStr.c_str());
            return std::string(root[key][pos].as<const char*>());
        }
        /*************************************************/


        std::string subvalueNestedIn(
                const char *const key,
                const char *const subkey,
                const char *const nested
        ) override {
            DynamicJsonBuffer jsonBuffer(capacity);
            JsonObject &root = jsonBuffer.parseObject(this->jsonStr.c_str());
            return std::string(root[key][subkey][nested].as<const char*>());
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
            DynamicJsonBuffer jsonBuffer(capacity);
            JsonObject &root = jsonBuffer.parseObject(this->jsonStr.c_str());
            return std::string(root[key][pos][subkey].as<const char*>());
        }
        /*************************************************/


        std::string subarrayValueNestedIn(
                const char *const key,
                int pos,
                const char *const subkey,
                const char *const nested
        ) override {
            DynamicJsonBuffer jsonBuffer(capacity);
            JsonObject &root = jsonBuffer.parseObject(this->jsonStr.c_str());
            return std::string(root[key][pos][subkey][nested].as<const char*>());
        };

};


/**************************************************
* makeJSONString
**************************************************/
std::unique_ptr<JSONInterface> makeJSONString(
		std::string json_str
) {
	return std::unique_ptr<JSONInterface>(new JSON(json_str));
}
/*************************************************/

};
};
};
