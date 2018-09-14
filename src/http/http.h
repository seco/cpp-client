

#ifndef HTTP_H
#define HTTP_H

#include <memory>

namespace Ark {
namespace Utilities {
namespace Network {
/***
 * Ark::Utilities::Network::HTTP
 * @brief: Forward Delcaration
 **/
class HTTP;
/**/

/***/

/***
 * Ark::Utilities::Network::HTTP
 * Currently using ESP8266 libs
 *
 * The purpose of this class is to serve as an
 * entry point for integrating the HTTPClient
 * library for different boards/chipsets
 **/
class AbstractHTTP
{
    protected:
        AbstractHTTP() = default;

    public:
        virtual ~AbstractHTTP(){};

        virtual std::string get(
                const char *const peer,
                int port,
                const char *const endpoint,
                const char *const fingerprint = nullptr
        ) = 0;

        virtual std::string post(
                const char *const peer,
                int port,
                const char *const endpoint,
                const char *bodyParameters,
                const char *const fingerprint = nullptr
        ) = 0;
};
/**/

/***/

/***
 * HTTP object factory
 **/
std::unique_ptr<AbstractHTTP> makeHTTP();
/**/

};
};
};

/***
 * Ark::Utilities::Network::Connectable
 **/
class Ark::Utilities::Network::HTTP
{
    public:
        std::unique_ptr<Ark::Utilities::Network::AbstractHTTP> http;
        HTTP() : http(makeHTTP()) { }
};
/**/

#endif
