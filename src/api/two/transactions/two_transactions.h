



#ifndef TWO_TRANSACTIONS_H
#define TWO_TRANSACTIONS_H

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
* PUBLIC: ARK::API::V2::Transactions
* virtual ARK::Utilities::Network::Connectable
*    
* API's Delegates Model
**************************************************/
class Transactions :
		virtual ARK::Utilities::Network::Connectable {};
/*************************************************/
};
};
};

#endif
