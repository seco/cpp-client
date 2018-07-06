/***************************************
* Ark-Cpp-Client - for the Ark Ecosystem (ark.io)
* https://github.com/ArkEcosystem/Cpp-Client
*
* sleepdeficit(simon@ark.io)
* MIT | Copyright S. Downey 2017-2018
***************************************/

#ifndef TWO_API_H
#define TWO_API_H

#define HAS_TWO_API

#include "api/two/blocks/two_blocks.h"
#include "api/two/delegates/two_delegates.h"
#include "api/two/node/two_node.h"
#include "api/two/peers/two_peers.h"
#include "api/two/transactions/two_transactions.h"
#include "api/two/votes/two_votes.h"
#include "api/two/wallets/two_wallets.h"

class TWO_API :
		public ARK::API::V2::Blocks,
		public ARK::API::V2::Delegates,
		public ARK::API::V2::Node,
		public ARK::API::V2::Peers,
		public ARK::API::V2::Transactions,
		public ARK::API::V2::Votes,
        public ARK::API::V2::Wallets,
		virtual ARK::Utilities::Network::Connectable {};

#endif
