


#ifndef TWO_PATHS_H
#define TWO_PATHS_H

namespace Ark {
namespace API {
namespace TWO {
namespace Paths {

namespace Blocks
{
    const auto base = "/api/v2/blocks";
    const auto search = "/api/v2/blocks/search";
};
/**************************************************************************************************/
namespace Delegates
{
    const auto base = "/api/v2/delegates";
};
/**************************************************************************************************/
namespace Node
{
    const auto base = "/api/v2/node";
    const auto configuration = "/api/v2/node/configuration";
    const auto status = "/api/v2/node/status";
    const auto syncing = "/api/v2/node/syncing";
};
/**************************************************************************************************/
namespace Peers
{
    const auto base = "/api/v2/peers";
};
/**************************************************************************************************/
namespace Transactions
{	
    const auto base = "/api/v2/transactions";
    const auto types = "/api/v2/transactions/types";
    const auto unconfirmed = "/api/v2/transactions/unconfirmed";
};
/**************************************************************************************************/
namespace Votes
{
    const auto base = "/api/v2/votes";
};

/**************************************************************************************************/
namespace Wallets
{
    const auto base = "/api/v2/wallets";
    const auto search = "/api/v2/wallets/search";
    const auto top = "/api/v2/wallets/top";
};

};
};
};
};

#endif
