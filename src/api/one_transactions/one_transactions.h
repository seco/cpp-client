

#ifndef ONE_TRANSACTIONS_H
#define ONE_TRANSACTIONS_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/one_paths.h"

#include <cstring>
#include <memory>

namespace ARK
{
namespace API
{
/*************************************************
* PUBLIC: ARK::API::Transactions
* virtual ARK::Utilities::Network::Connectable
*    
* API's Peer Model
**************************************************/
class ONE_Transactions :
		virtual ARK::Utilities::Network::Connectable
{
public:
	/*************************************************
	* /api/transactions/get?id=
	*
	* @return: std::string
	* @param: const char *const id
	*
	* @brief: Gets Transaction by Hash ID from a Node via API.
	**************************************************/
	std::string transaction(const char *const id);
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	* /api/transactions?limit=20
	*
	* @brief: Gets Transactions list, limited to last 20.
	**************************************************/
	std::string transactions();
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	* /api/transactions/unconfirmed/get?id=
	*
	* @param: const char *const id
	* @return: std::string
	*
	* @brief: Gets Unconfirmed Transaction by Hash ID from a Node via API.
	**************************************************/
	std::string transactionUnconfirmed(const char *const id);
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	* /api/transactions/unconfirmed
	*
	* @return: std::string
	*
	* @brief: Gets Unconfirmed Transactions from a Node via API.
	**************************************************/
	std::string transactionsUnconfirmed();
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	* /api/transactions/get?id=
	*
	* @param: const char *const txID
	* @return: std::string
	*
	* @brief: Gets vendorField for a given Transaction by  txID from a Node via API.
	**************************************************/
	std::string getVendorField(const char *const txID);
	/*************************************************/

};
/*************************************************/

};
};

#endif
