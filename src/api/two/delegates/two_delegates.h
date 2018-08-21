



#ifndef TWO_DELEGATES_H
#define TWO_DELEGATES_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/two/two_paths.h"
#include <sstream>

namespace ARK {
namespace API {
namespace TWO {

class Delegates : virtual ARK::Utilities::Network::Connectable
{
    public:
        std::string delegate(const char *const identifier);
        std::string delegates(int limit, int page);
        std::string delegateBlocks(const char *const identifier, int limit, int page);
        std::string delegateVoters(const char *const identifier, int limit, int page);
};

};
};
};

#endif
