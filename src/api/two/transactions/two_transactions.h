



#ifndef TWO_TRANSACTIONS_H
#define TWO_TRANSACTIONS_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/two/two_paths.h"
#include <sstream>

namespace ARK {
namespace API {
namespace TWO {

class Transactions : virtual ARK::Utilities::Network::Connectable
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
