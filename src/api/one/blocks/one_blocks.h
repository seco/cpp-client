

#ifndef ONE_BLOCKS_H
#define ONE_BLOCKS_H

#include "connection/connection.h"
#include "api/one/one_paths.h"

#include <memory>
#include <vector>

namespace Ark {
namespace API {
namespace ONE {

class Blocks : virtual Ark::Utilities::Network::Connection
{
    public:
        std::string block(const char *const blockId);
        std::string blocks();
        std::string blockEpoch();
        std::string blockFee();
        std::string blockFees();
        std::string blockHeight();
        std::string blockMilestone();
        std::string blockNethash();
        std::string blockReward();
        std::string blockSupply();
        std::string blockStatus();
};

};
};
};

#endif
