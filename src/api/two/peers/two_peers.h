



#ifndef TWO_PEERS_H
#define TWO_PEERS_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/two/two_paths.h"

namespace ARK {
namespace API {
namespace TWO {

class Peers : virtual ARK::Utilities::Network::Connectable
{
    public:
        std::string peer(const char *const ip);
        std::string peers(int limit, int page);
};

};
};
};

#endif
