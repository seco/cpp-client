



#ifndef TWO_NODE_H
#define TWO_NODE_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/two/two_paths.h"

namespace ARK
{
namespace API
{
namespace TWO
{

class Node : virtual ARK::Utilities::Network::Connectable
{
	public:
		std::string nodeConfiguration();
		std::string nodeStatus();
		std::string nodeSycing();
};

};
};
};

#endif
