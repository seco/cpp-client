



#ifndef TWO_PEERS_H
#define TWO_PEERS_H

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
* PUBLIC: ARK::API::V2::Peers
* virtual ARK::Utilities::Network::Connectable
*    
* API's Peers Model
**************************************************/
class Peers :
		virtual ARK::Utilities::Network::Connectable {};
/*************************************************/
};
};
};

#endif
