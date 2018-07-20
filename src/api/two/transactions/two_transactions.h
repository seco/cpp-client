



#ifndef TWO_TRANSACTIONS_H
#define TWO_TRANSACTIONS_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/two/two_paths.h"

namespace ARK
{
namespace API
{
namespace TWO
{

class Transactions : virtual ARK::Utilities::Network::Connectable
{
	public:
		std::string transaction(const char *const identifier);
		std::string transactionUnconfirmed(const char *const identifier);
		std::string transactions(unsigned int limit, unsigned int page);
		std::string transactions(const char *const identifier, unsigned int limit, unsigned int page);
		std::string transactionsUnconfirmed(unsigned int limit, unsigned int page);
		std::string transactionTypes(unsigned int limit, unsigned int page);
};

};
};
};

#endif
