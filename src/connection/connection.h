

#ifndef CONNECTION_H
#define CONNECTION_H

#include "http/http.h"
#include <string>
#include <cstring>

namespace Ark {
namespace Utilities {
namespace Network {

/*************************************************
* Ark::Utilities::Network::Connection
* @brief: Forward Declaration.
**************************************************/
class Connection; 
/*************************************************/

/**************************************************************************************************/

/*************************************************
* Ark::Utilities::Network::AbstractConnection
**************************************************/
class AbstractConnection : virtual HTTP
{
    private:
        char host_[17];
        int port_;
        char fingerprint_[60] = { '\0' };
        bool hasSSL = false;

    public:
        AbstractConnection() : host_(), port_(), fingerprint_() {};
        AbstractConnection(const char *const newHost, const int newPort, const char *const newFingerprint = "");

        AbstractConnection& operator=(AbstractConnection&& other);

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
* Ark::Utilities::Network::Connection
**************************************************/
class Ark::Utilities::Network::Connection
{
    public:
        Ark::Utilities::Network::AbstractConnection connection;
};
/*************************************************/

#endif
