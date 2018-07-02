

#ifndef ONE_ACCOUNTS_H
#define ONE_ACCOUNTS_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/one_paths.h"

namespace ARK
{
namespace API
{
/*************************************************
* PUBLIC: ARK::API::ONE_Accounts
* virtual ARK::Utilities::Network::Connectable
*    
* API's Account Model
**************************************************/
class ONE_Accounts :
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		* /api/accounts/getBalance?address=arkAddress
		*
		* @param: const char *const arkAddress
		* @return: std::string
		*
		* @brief: Uses Ark Address to get an Accounts Confirmed and Unconfirmed Balances JSON string from a Node via API.
		**************************************************/
		std::string accountBalance(const char *const arkAddress);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* api/accounts/getPublickey?address=arkAddress
		*
		* @param: const char *const arkAddress
		* @return: std::string
		*
		* @brief: Uses Ark Address to get an Account Publickey JSON string from a Node via API.
		**************************************************/
		std::string accountPublickey(const char *const arkAddress);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/accounts/delegates/fee?address=arkAddress
		*
		* @param: const char *const arkAddress
		* @return: std::string
		*
		* @brief: Uses Ark Address to get Delegate Registration Fee JSON string from a Node via API.
		**************************************************/
		std::string accountDelegatesFee(const char *const arkAddress);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/accounts/delegates?address=arkAddress
		*
		* @param: const char *const arkAddress
		* @return: std::string
		*
		* @brief: Uses Ark Address to get Delegate JSON string from a Node via API.
		**************************************************/
		std::string accountDelegates(const char *const arkAddress);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/accounts?address=arkAddress
		*
		* @param: const char *const arkAddress
		* @return: std::string
		*
		* @brief: Uses Ark Address to get Account JSON string from a Node via API.
		**************************************************/
		std::string account(const char *const arkAddress);
		/*************************************************/

};
/*************************************************/

};
};

#endif
