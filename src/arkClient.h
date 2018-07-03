/***************************************
* Ark-Cpp-Client - for the Ark Ecosystem (ark.io)
* https://github.com/Ark-IoT/Ark-Cpp
*
* sleepdeficit(simon@ark.io)
* MIT | Copyright S. Downey 2017-2018
***************************************/

#ifndef ARKCLIENT_H
#define ARKCLIENT_H

#define HAS_CLIENT


#include "api/one_api.h"
// #include "api/two_api.h"

#define DEVNET_EXPLORER_URL "https://dexplorer.ark.io" // char[24+1]
#define MAINNET_EXPLORER_URL "https://explorer.ark.io" // char[23+1]
#define DEFAULT_EXPLORER_API_PORT 8443

#define DEVNET_SEED_URL "167.114.29.55" // char[13+1]
#define DEVNET_SEED_PORT 4002

#define MAINNET_SEED_URL "5.39.9.242" // char[13+1]
#define MAINNET_SEED_PORT 4001

enum NetworkType { DEVNET, MAINNET };

namespace ARK
{
/*************************************************
* ARK::Client
**************************************************/
class Client :
		public ONE_API,
        // public TWO_API,
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
