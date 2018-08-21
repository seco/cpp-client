

#ifndef ONE_PEERS_H
#define ONE_PEERS_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/one/one_paths.h"

#include <cstring>
#include <cstdio>

namespace ARK
{
namespace API
{
namespace ONE
{

class Peers : virtual ARK::Utilities::Network::Connectable
{
    public:
        std::string peer(const char *const ip, const int port);
        std::string peers();
        std::string peerVersion();
};

}; // namespace ONE
}; // namespace API
}; // namespace ARK

#endif
