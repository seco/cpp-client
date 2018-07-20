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
		public ARK::API::TWO::Blocks,
		public ARK::API::TWO::Delegates,
		public ARK::API::TWO::Node,
		public ARK::API::TWO::Peers,
		public ARK::API::TWO::Transactions,
		public ARK::API::TWO::Votes,
        public ARK::API::TWO::Wallets,
		virtual ARK::Utilities::Network::Connectable {};

#endif
