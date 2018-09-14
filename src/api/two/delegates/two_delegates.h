



#ifndef TWO_DELEGATES_H
#define TWO_DELEGATES_H

#include "helpers/helpers.h"
#include "connection/connection.h"
#include "api/two/two_paths.h"

namespace Ark {
namespace API {
namespace TWO {

class Delegates : virtual Ark::Utilities::Network::Connection
{
    public:
        std::string delegate(const char *const identifier);
        std::string delegates(int limit = 5, int page = 1);
        std::string delegateBlocks(const char *const identifier, int limit = 5, int page = 1);
        std::string delegateVoters(const char *const identifier, int limit = 5, int page = 1);
};

};
};
};

#endif
