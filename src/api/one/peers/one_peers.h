

#ifndef ONE_PEERS_H
#define ONE_PEERS_H

#include "helpers/helpers.h"
#include "connection/connection.h"
#include "api/one/one_paths.h"

#include <cstring>
#include <cstdio>

namespace Ark {
namespace API {
namespace ONE {

class Peers : virtual Ark::Utilities::Network::Connection
{
    public:
        std::string peer(const char *const ip, const int port);
        std::string peers();
        std::string peerVersion();
};

};
};
};

#endif
