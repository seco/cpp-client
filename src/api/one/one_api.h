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

class ONE_API : public Ark::API::ONE::Accounts,
                public Ark::API::ONE::Blocks,
                public Ark::API::ONE::Delegates,
                public Ark::API::ONE::Loader,
                public Ark::API::ONE::Peers,
                public Ark::API::ONE::Signatures,
                public Ark::API::ONE::Transactions,
                virtual Ark::Utilities::Network::Connectable {};

#endif
