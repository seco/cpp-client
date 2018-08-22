

#ifndef ONE_DELEGATES_H
#define ONE_DELEGATES_H

#include "connection/connection.h"
#include "api/one/one_paths.h"

namespace Ark
{
namespace API
{
namespace ONE
{

class Delegates : virtual Ark::Utilities::Network::Connection
{
    public:
        std::string delegate(const char *const parameter);
        std::string delegates();
        std::string delegatesCount();
        std::string delegateSearch(const char *const username);
        std::string delegateFee();
        std::string delegateForgedByAccount(const char *const generatorPublicKey);
        std::string delegateNextForgers();
        std::string delegateVoters(const char *const publicKey);
};

};
};
};

#endif
