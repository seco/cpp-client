/***************************************
* Ark-Cpp-Client - for the Ark Ecosystem (ark.io)
* https://github.com/ArkEcosystem/Cpp-Client
*
* sleepdeficit(simon@ark.io)
* MIT | Copyright S. Downey 2017-2018
***************************************/

#ifndef ARKCLIENT_H
#define ARKCLIENT_H

/*************************************************/
#define HAS_CLIENT
/*************************************************/
// #define HAS_ONE_API
#define HAS_TWO_API
/*************************************************/
#define DEVNET_EXPLORER_URL "dexplorer.ark.io" // char[16+1]
#define MAINNET_EXPLORER_URL "explorer.ark.io" // char[15+1]

#define DEFAULT_EXPLORER_API_PORT 8443
#define DEFAULT_EXPLORER_SSL_FINGERPRINT "94 44 0B 97 29 13 21 1A CF A5 D1 15 BE C3 10 F1 AB 12 B5 F5" // char[59+1]
/*************************************************/
enum NetworkType { DEVNET, MAINNET };
/*************************************************/

/*************************************************
* Ark::V1::Client
**************************************************/
#ifdef HAS_ONE_API
#include "api/one/one_api.h"
namespace Ark {
namespace V1 {
class Client : public ONE_API, virtual Ark::Utilities::Network::Connectable
{
    public:
        Client();
        explicit Client(const char *const customBaseURL, const int customBasePort);
        explicit Client(const NetworkType netType);
};
};
};
#endif
/*************************************************/

/*************************************************
* Ark::V2::Client
**************************************************/
#ifdef HAS_TWO_API
#include "api/two/two_api.h"
namespace Ark {
namespace V2 {
class Client : public TWO_API, virtual Ark::Utilities::Network::Connectable
{
    public:
        Client();
        explicit Client(const char *const customBaseURL, const int customBasePort);
        explicit Client(const NetworkType netType);
};
};
};
#endif
/*************************************************/

#endif
