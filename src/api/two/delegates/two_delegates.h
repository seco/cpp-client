



#ifndef TWO_DELEGATES_H
#define TWO_DELEGATES_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/two/two_paths.h"

namespace ARK
{
namespace API
{
namespace TWO
{

class Delegates : virtual ARK::Utilities::Network::Connectable
{
	public:
		std::string delegate(const char *const identifier);
		std::string delegates(unsigned int limit, unsigned int page);
		std::string delegateBlocks(const char *const identifier, unsigned int limit, unsigned int page);
		std::string delegateVoters(const char *const identifier, const unsigned int limit, const unsigned int page);
};

};
};
};

#endif
