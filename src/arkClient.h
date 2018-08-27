/***************************************
 * Ark-Cpp-Client - for the Ark Ecosystem (ark.io)
 * https://github.com/ArkEcosystem/Cpp-Client
 *
 * sleepdeficit(simon@ark.io)
 * MIT | Copyright S. Downey 2017-2018
 ***************************************/

/**************************************************************************************************/
/**************************************************************************************************/

#ifndef ARKCLIENT_H
#define ARKCLIENT_H

/*************************************************/

#define HAS_CLIENT

/*************************************************/

// #define USE_ONE_API
#define USE_TWO_API

/*************************************************/

#define DEVNET_EXPLORER_URL "dexplorer.ark.io"
#define MAINNET_EXPLORER_URL "explorer.ark.io"

#define DEFAULT_EXPLORER_API_PORT 8443
#define DEFAULT_EXPLORER_SSL_FINGERPRINT "BB A9 38 44 EB DD B6 9B D6 1C A2 1A 69 B3 A7 3E C1 B1 E2 B8"

/**************************************************************************************************/
/**************************************************************************************************/

#include "api/api.h"
#include "connection/connection.h"

enum NetworkType { DEVNET, MAINNET };

/*************************************************
* Ark:Client
**************************************************/
namespace Ark {
class Client : public VersionedAPI, virtual Ark::Utilities::Network::Connection
{
    public:
        Client();
        explicit Client(const char *const customBaseURL, const int customBasePort);
        explicit Client(const NetworkType netType);
};
};
/*************************************************/

/**************************************************************************************************/
/**************************************************************************************************/

#endif
