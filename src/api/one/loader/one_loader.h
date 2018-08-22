

#ifndef ONE_LOADER_H
#define ONE_LOADER_H

#include "connection/connection.h"
#include "api/one/one_paths.h"

namespace Ark {
namespace API {
namespace ONE {

class Loader : virtual Ark::Utilities::Network::Connection
{
    public:
        std::string loaderAutoconfigure();
        std::string loaderStatus();
        std::string loaderSync();
};

};
};
};

#endif
