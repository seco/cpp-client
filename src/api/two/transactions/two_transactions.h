



#ifndef TWO_TRANSACTIONS_H
#define TWO_TRANSACTIONS_H

#include "utils/helpers.h"
#include "connection/connector.h"
#include "api/two/two_paths.h"

namespace Ark {
namespace API {
namespace TWO {

class Transactions : virtual Ark::Utilities::Network::Connectable
{
    public:
        std::string transaction(const char *const identifier);
        std::string transactionUnconfirmed(const char *const identifier);
        std::string transactions(int limit, int page);
        std::string transactions(const char *const identifier, int limit, int page);
        std::string transactionsUnconfirmed(int limit, int page);
        std::string transactionTypes(int limit = 10, int page = 1);
};

};
};
};

#endif
