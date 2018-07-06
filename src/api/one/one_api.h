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

class ONE_API :
		public ARK::API::V1::Accounts,
		public ARK::API::V1::Blocks,
		public ARK::API::V1::Delegates,
		public ARK::API::V1::Loader,
		public ARK::API::V1::Peers,
		public ARK::API::V1::Signatures,
		public ARK::API::V1::Transactions,
		virtual ARK::Utilities::Network::Connectable {};

#endif
