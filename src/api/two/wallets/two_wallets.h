



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
        std::string wallets(const char *const identifier, int limit = 5, int page = 1);
        std::string wallets(int limit = 5, int page = 1);
        std::string walletsTop(int limit = 5, int page = 1);
        std::string walletsTransactions(const char *const identifier, int limit = 5, int page = 1);
        std::string walletsTransactionsReceived(const char *const identifier, int limit = 5, int page = 1);
        std::string walletsTransactionsSent(const char *const identifier, int limit = 5, int page = 1);
        std::string walletsVotes(const char *const identifier, int limit = 5, int page = 1);
        std::string walletsSearch(std::pair<const char*, const char*> bodyParameters, int limit = 5, int page = 1);
};

};
};
};

#endif
