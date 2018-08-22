

#ifndef HTTP_H
#define HTTP_H

#include <memory>

namespace Ark {
namespace Utilities {
namespace Network {
/**************************************************
 * Ark::Utilities::Network::Connectable 
 * @brief: Forward Delcaration
 **************************************************/
class HTTPConnectable;
/*************************************************/

/**************************************************************************************************/

/**************************************************
 * Ark::Utilities::Network::HTTP 
 * Currently using ESP8266 libs
 *
 * The purpose of this class is to serve as an
 * entry point for integrating the HTTPClient
 * library for different boards/chipsets
 **************************************************/
class HTTPInterface
{
    protected: 
        HTTPInterface() = default;

    public:
        virtual ~HTTPInterface() { }

        virtual std::string get(
                const char *const peer,
                int port,
                const char *const request
        ) = 0;

        virtual std::string getHTTPS(
                const char *const peer,
                int port,
                const char *const fingerprint,
                const char *const request
        ) = 0;
};
/*************************************************/

/**************************************************************************************************/

/**************************************************
 *	HTTP object factory
 **************************************************/
std::unique_ptr<HTTPInterface> makeHTTP();
/*************************************************/

};
};
};

/**************************************************
 * Ark::Utilities::Network::Connectable 
 *	Inheritable HTTPConnectable object
 **************************************************/
class Ark::Utilities::Network::HTTPConnectable
{
    public:
        std::unique_ptr<Ark::Utilities::Network::HTTPInterface> http;
        HTTPConnectable() : http(makeHTTP()) { }
};
/*************************************************/

#endif
