

#ifndef ONE_ACCOUNTS_H
#define ONE_ACCOUNTS_H

#include "connection/connector.h"
#include "api/one/one_paths.h"

namespace Ark {
namespace API {
namespace ONE {

class Accounts : virtual Ark::Utilities::Network::Connectable
{
    public:
        std::string accountBalance(const char *const arkAddress);
        std::string accountPublickey(const char *const arkAddress);
        std::string accountDelegatesFee(const char *const arkAddress);
        std::string accountDelegates(const char *const arkAddress);
        std::string account(const char *const arkAddress);
};

};
};
};

#endif
