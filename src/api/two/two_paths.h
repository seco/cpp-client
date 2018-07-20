


#ifndef TWO_PATHS_H
#define TWO_PATHS_H

namespace ARK
{
namespace API
{
namespace TWO
{
namespace Paths
{

namespace Blocks
{
    const auto base = "/api/blocks";
    const auto search = "/api/blocks/search";
};

/**************************************************************************************************/

namespace Delegates
{
	const auto base = "/api/delegates/";
};

/**************************************************************************************************/

namespace Node
{
	const auto base = "/api/node";
	const auto configuration = "/api/node/configuration";
	const auto status = "/api/node/status";
	const auto syncing = "/api/node/syncing";
};

/**************************************************************************************************/

namespace Peers
{
	const auto base = "/api/peers";
};

/**************************************************************************************************/

namespace Transactions
{	
	const auto base = "/api/transactions";
	const auto search = "/api/transactions/search";
	const auto types = "/api/transactions/types";
	const auto unconfirmed = "/api/transactions/unconfirmed";
};

/**************************************************************************************************/

namespace Votes
{
	const auto base = "/api/votes";
};

/**************************************************************************************************/

namespace Wallets
{
	const auto base = "/api/wallets";
	const auto search = "/api/wallets/search";
	const auto top = "/api/wallets/top";
};

};
};
};
};

#endif
