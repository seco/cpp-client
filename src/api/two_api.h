/***************************************
* Ark-Cpp-Client - for the Ark Ecosystem (ark.io)
* https://github.com/Ark-IoT/Ark-Cpp
*
* sleepdeficit(simon@ark.io)
* MIT | Copyright S. Downey 2017-2018
***************************************/

#ifndef TWO_API_H
#define TWO_API_H

#include "api/two_blocks/two_blocks.h"
#include "api/two_delegates/two_delegates.h"
#include "api/two_node/two_node.h"
#include "api/two_peers/two_peers.h"
#include "api/two_transactions/two_transactions.h"
#include "api/two_votes/two_votes.h"
#include "api/two_wallets/two_wallets.h"

class TWO_API :
		public ARK::API::TWO_Blocks,
		public ARK::API::TWO_Delegates,
		public ARK::API::TWO_Node,
		public ARK::API::TWO_Peers,
		public ARK::API::TWO_Transactions,
		public ARK::API::TWO_Votes,
        public ARK::API::TWO_Wallets,
		virtual ARK::Utilities::Network::Connectable {};

#endif
