



#ifndef TWO_WALLETS_H
#define TWO_WALLETS_H

#include "utils/helpers.h"
#include "connection/connection.h"
#include "api/two/two_paths.h"

namespace Ark {
namespace API {
namespace TWO {

class Wallets : virtual Ark::Utilities::Network::Connection
{
    public:
        std::string wallet(const char *const identifier);
        std::string wallets(int limit, int page);
        std::string walletsTop(int limit, int page);
        std::string walletsTransactions(const char *const identifier, int limit, int page);
        std::string walletsTransactionsReceived(const char *const identifier, int limit, int page);
        std::string walletsTransactionsSent(const char *const identifier, int limit, int page);
        std::string walletsVotes(const char *const identifier, int limit, int page);
        std::string walletsSearch(const char *const parameter, int limit, int page);
};

};
};
};

#endif
