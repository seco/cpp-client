



#ifndef TWO_VOTES_H
#define TWO_VOTES_H

#include "utils/helpers.h"
#include "connection/connector.h"
#include "api/two/two_paths.h"

namespace Ark {
namespace API {
namespace TWO {

class Votes : virtual Ark::Utilities::Network::Connectable
{
    public:
        std::string vote(const char *const identifier);
        std::string votes(int limit, int page);
};

};
};
};

#endif
