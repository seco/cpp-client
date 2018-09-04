



#ifndef TWO_VOTES_H
#define TWO_VOTES_H

#include "utils/helpers.h"
#include "connection/connection.h"
#include "api/two/two_paths.h"

namespace Ark {
namespace API {
namespace TWO {

class Votes : virtual Ark::Utilities::Network::Connection
{
    public:
        std::string vote(const char *const identifier);
        std::string votes(int limit = 5, int page = 1);
};

};
};
};

#endif
