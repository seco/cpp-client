/***************************************
* Ark-Cpp-Client - for the Ark Ecosystem (ark.io)
* https://github.com/ArkEcosystem/Cpp-Client
*
* sleepdeficit(simon@ark.io)
* MIT | Copyright S. Downey 2017-2018
***************************************/

#ifndef ARKCLIENT_H
#define ARKCLIENT_H

#define HAS_CLIENT

/***************************************
* Uncomment to use desired API Version
***************************************/
#define USE_ONE_API
// #define USE_TWO_API
/**************************************/

#define DEVNET_EXPLORER_URL "https://dexplorer.ark.io" // char[24+1]
#define MAINNET_EXPLORER_URL "https://explorer.ark.io" // char[23+1]
#define DEFAULT_EXPLORER_API_PORT 8443

#define DEVNET_SEED_URL "167.114.29.54" // char[13+1]
#define DEVNET_SEED_PORT 4002

#define MAINNET_SEED_URL "5.39.9.242" // char[13+1]
#define MAINNET_SEED_PORT 4001

enum NetworkType { DEVNET, MAINNET };

#ifdef USE_ONE_API
    #include "api/one/one_api.h"
    class VersionedAPI :
            public ONE_API,
            virtual ARK::Utilities::Network::Connectable {};
#elif defined(USE_TWO_API)
    #include "api/two/two_api.h"
    class VersionedAPI :
            public TWO_API,
            virtual ARK::Utilities::Network::Connectable {};
#endif

namespace ARK
{
/*************************************************
* ARK::Client
**************************************************/
class Client :
		public virtual VersionedAPI,
        virtual ARK::Utilities::Network::Connectable
{
	public:
		Client();
        explicit Client(
            const char *const customBaseURL,
            const unsigned int customBasePort
        );
        explicit Client(const NetworkType netType);
};
/*************************************************/

};

#endif
