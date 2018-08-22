

#ifndef ONE_SIGNATURES_H
#define ONE_SIGNATURES_H

#include "connection/connection.h"
#include "api/one/one_paths.h"

namespace Ark {
namespace API {
namespace ONE {

class Signatures : virtual Ark::Utilities::Network::Connection
{
public:
    std::string signaturesFee();
};

};
};
};

#endif
