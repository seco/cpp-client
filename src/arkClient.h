/***************************************
* Ark-Cpp - for the Ark Ecosystem (ark.io)
* https://github.com/Ark-IoT/Ark-Cpp
*
* sleepdeficit(simon@ark.io)
* MIT | Copyright S. Downey 2017-2018
***************************************/

#ifndef ARKCLIENT_H
#define ARKCLIENT_H

#define HAS_CLIENT

#include "api/api.h"

#define DEVNET_EXPLORER_URL "dexplorer.ark.io" // char[24+1]
#define MAINNET_EXPLORER_URL "explorer.ark.io" // char[23+1]
#define DEFAULT_EXPLORER_API_PORT 8443u

enum  NetworkType : int { DEVNET , MAINNET };

namespace ARK
{
/*************************************************
* ARK::Client
**************************************************/
class Client :
		public ARK::API::Accountable,
		public ARK::API::Blockable,
		public ARK::API::Delegatable,
		public ARK::API::Loadable,
		public ARK::API::MultiSignaturable,
		public ARK::API::Peerable,
		public ARK::API::Signaturable,
		public ARK::API::Transactionable,
        virtual ARK::Utilities::Network::Connectable
{
	public:
		Client();
        explicit Client(
            const char *const customBaseURL,
            const int customBasePort
        );
        explicit Client(const NetworkType netType);
};
/*************************************************/

};

#endif
