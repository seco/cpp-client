



#ifndef TWO_WALLETS_H
#define TWO_WALLETS_H

#include "platform/platform.h"
#include "utils/connector.h"
#include "api/two_paths.h"

namespace ARK
{
namespace API
{
/*************************************************
* PUBLIC: ARK::API::TWO_Wallets
* virtual ARK::Utilities::Network::Connectable
*    
* API's Wallets Model
**************************************************/
class TWO_Wallets :
		virtual ARK::Utilities::Network::Connectable {};
/*************************************************/
};
};

#endif
