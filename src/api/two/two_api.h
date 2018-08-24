

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
        public Ark::API::TWO::Blocks,
        public Ark::API::TWO::Delegates,
        public Ark::API::TWO::Node,
        public Ark::API::TWO::Peers,
        public Ark::API::TWO::Transactions,
        public Ark::API::TWO::Votes,
        public Ark::API::TWO::Wallets,
        virtual Ark::Utilities::Network::Connection {};

#endif
