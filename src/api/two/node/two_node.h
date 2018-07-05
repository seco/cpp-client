



#ifndef TWO_NODE_H
#define TWO_NODE_H

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
* PUBLIC: ARK::API::V2::Node
* virtual ARK::Utilities::Network::Connectable
*    
* API's Node Model
**************************************************/
class Node :
		virtual ARK::Utilities::Network::Connectable {};
/*************************************************/
};
};
};

#endif
