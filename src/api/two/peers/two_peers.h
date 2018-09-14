



#ifndef TWO_PEERS_H
#define TWO_PEERS_H

#include "helpers/helpers.h"
#include "connection/connection.h"
#include "api/two/two_paths.h"

namespace Ark {
namespace API {
namespace TWO {

class Peers : virtual Ark::Utilities::Network::Connection
{
    public:
        std::string peer(const char *const ip);
        std::string peers(int limit = 5, int page = 1);
};

};
};
};

#endif
