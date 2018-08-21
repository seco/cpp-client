



#ifndef TWO_VOTES_H
#define TWO_VOTES_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/two/two_paths.h"

namespace ARK {
namespace API {
namespace TWO {

class Votes : virtual ARK::Utilities::Network::Connectable
{
    public:
        std::string vote(const char *const identifier);
        std::string votes(int limit, int page);
};

};
};
};

#endif
