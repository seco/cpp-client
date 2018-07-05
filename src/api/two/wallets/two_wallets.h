



#ifndef TWO_WALLETS_H
#define TWO_WALLETS_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/two/two_paths.h"

namespace ARK
{
namespace API
{
namespace V2
{
/*************************************************
* PUBLIC: ARK::API::V2::Wallets
* virtual ARK::Utilities::Network::Connectable
*    
* API's Wallets Model
**************************************************/
class Wallets :
		virtual ARK::Utilities::Network::Connectable {};
/*************************************************/
};
};
};

#endif
