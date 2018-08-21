/***************************************
* Ark-Cpp-Client - for the Ark Ecosystem (ark.io)
* https://github.com/ArkEcosystem/Cpp-Client
*
* sleepdeficit(simon@ark.io)
* MIT | Copyright S. Downey 2017-2018
***************************************/

#ifndef ONE_API_H
#define ONE_API_H

#define HAS_ONE_API

#include "api/one/accounts/one_accounts.h"
#include "api/one/blocks/one_blocks.h"
#include "api/one/delegates/one_delegates.h"
#include "api/one/loader/one_loader.h"
#include "api/one/peers/one_peers.h"
#include "api/one/signatures/one_signatures.h"
#include "api/one/transactions/one_transactions.h"

class ONE_API : public ARK::API::ONE::Accounts,
                public ARK::API::ONE::Blocks,
                public ARK::API::ONE::Delegates,
                public ARK::API::ONE::Loader,
                public ARK::API::ONE::Peers,
                public ARK::API::ONE::Signatures,
                public ARK::API::ONE::Transactions,
                virtual ARK::Utilities::Network::Connectable
{
};

#endif
