

#ifndef TWO_BLOCKS_H
#define TWO_BLOCKS_H

#include "utils/helpers.h"
#include "connection/connection.h"
#include "api/two/two_paths.h"

namespace Ark {
namespace API {
namespace TWO {

class Blocks : virtual Ark::Utilities::Network::Connection
{
    public:
        std::string block(const char *const blockId);
        std::string blocks();
        std::string blocks(int limit, int page);
        std::string blockTransactions(const char *const blockId);
};

};
};
};

#endif
