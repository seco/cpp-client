

#ifndef CONNECTOR_H
#define CONNECTOR_H


#include "http/http.h"
#include <string>
#include <cstring>

namespace Ark {
namespace Utilities {
namespace Network {

/*************************************************
* Ark::Utilities::Network::Connectable
* @brief: Forward Declaration.
**************************************************/
class Connectable; 
/*************************************************/

/**************************************************************************************************/

/*************************************************
* Ark::Utilities::Network::Connector
**************************************************/
class Connector : virtual HTTPConnectable
{
    private:
        char host_[17];
        int port_;
        char fingerprint_[60] = { '\0' };
        bool hasSSL = false;

    public:
        Connector() : host_(), port_(), fingerprint_() {};
        Connector(const char *const newHost, const int newPort, const char *const newFingerprint = "");

        Connector& operator=(Connector&& other);

        void connect(const char *const newHost, const int newPort, const char *const newFingerprint); // Connect to the given connection.
        void disconnect(); // Disconnect from the given connection.
        
        std::string getConnection(); // Get a connection string (host:port).
        std::string getFingerprint();  // Get an SSL connections' fingerprint.

        std::string callback(const char* const request);
};
/*************************************************/

};
};
};

/**************************************************
* Ark::Utilities::Network::Connectable
* Inheritable Connector object
**************************************************/
class Ark::Utilities::Network::Connectable
{
    public:
        Ark::Utilities::Network::Connector netConnector;
};
/*************************************************/

#endif
