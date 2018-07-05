



#ifndef TWO_DELEGATES_H
#define TWO_DELEGATES_H

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
* PUBLIC: ARK::API::V2::Delegates
* virtual ARK::Utilities::Network::Connectable
*    
* API's Delegates Model
**************************************************/
class Delegates :
		virtual ARK::Utilities::Network::Connectable {};
/*************************************************/
};
};
};

#endif
