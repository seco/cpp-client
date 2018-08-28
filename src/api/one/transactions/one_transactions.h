

#ifndef ONE_TRANSACTIONS_H
#define ONE_TRANSACTIONS_H

#include "connection/connection.h"
#include "api/one/one_paths.h"
#include <cstring>
#include <memory>

namespace Ark {
namespace API {
namespace ONE {

class Transactions : virtual Ark::Utilities::Network::Connection
{
    public:
        std::string transaction(const char *const id);
        std::string transactions();
        std::string transactionUnconfirmed(const char *const id);
        std::string transactionsUnconfirmed();
        std::string getVendorField(const char *const txID);
};

};
};
};

#endif
