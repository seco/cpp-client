



#ifndef TWO_TRANSACTIONS_H
#define TWO_TRANSACTIONS_H

#include "utils/helpers.h"
#include "connection/connection.h"
#include "api/two/two_paths.h"

namespace Ark {
namespace API {
namespace TWO {

class Transactions : virtual Ark::Utilities::Network::Connection
{
    public:
        std::string transaction(const char *const identifier);
        std::string transactionUnconfirmed(const char *const identifier);
        std::string transactions(const char *const identifier, int limit = 5, int page = 1);
        std::string transactions(int limit = 5, int page = 1);
        std::string transactionsUnconfirmed(int limit = 5, int page = 1);
        std::string transactionTypes(int limit = 5, int page = 1);
};

};
};
};

#endif
