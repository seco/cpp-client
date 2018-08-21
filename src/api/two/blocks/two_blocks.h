

#ifndef TWO_BLOCKS_H
#define TWO_BLOCKS_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/two/two_paths.h"
#include <sstream>

namespace ARK {
namespace API {
namespace TWO {

class Blocks : virtual ARK::Utilities::Network::Connectable
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
