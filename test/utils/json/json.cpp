

#include "json.h"

/**************************************************
 * @brief creates a JSON object.
 * Instantiate with a std::string;
 * get the root to extract values (eg root["meta", "count"].as<int>())
 * 
 * @param std::string jsonString
 **************************************************/
Ark::Test::Utils::JSON::JSON(std::string jsonString) { jsonStr_ = jsonString; }
/*************************************************/

/**************************************************
 * @brief get the root of the JSON object
 **************************************************/
JsonObject& Ark::Test::Utils::JSON::getRoot()
{
    DynamicJsonBuffer jsonBuffer(this->jsonStr_.size());
    JsonObject &root = jsonBuffer.parseObject(this->jsonStr_.c_str());
    return root;
}
/*************************************************/

/**************************************************
 * JSONParser
 **************************************************/
std::unique_ptr<Ark::Test::Utils::JSON> Ark::Test::Utils::JSONParser(
        std::string json_str
) {
    return std::unique_ptr<JSON>(new Ark::Test::Utils::JSON(json_str));
}
/*************************************************/
