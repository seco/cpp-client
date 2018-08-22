



#ifndef TWO_NODE_H
#define TWO_NODE_H

#include "utils/helpers.h"
#include "connection/connection.h"
#include "api/two/two_paths.h"

namespace Ark {
namespace API {
namespace TWO {

class Node : virtual Ark::Utilities::Network::Connection
{
    public:
        std::string nodeConfiguration();
        std::string nodeStatus();
        std::string nodeSycing();
};

};
};
};

#endif
