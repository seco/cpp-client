

#ifndef ONE_DELEGATES_H
#define ONE_DELEGATES_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/one/one_paths.h"

namespace ARK
{
namespace API
{
namespace V1
{
/*************************************************
* PUBLIC: ARK::API::V1::Delegates
* virtual ARK::Utilities::Network::Connectable
*    
* API's Delegate Model
**************************************************/
class Delegates :
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		* /api/delegates/get?username="username"
		* /api/delegates/get?publicKey=publicKey
		*
		* @param: const char *const parameter
		* @return: std::string
		*
		* @brief: Returns Delegate by username from a Node via API.
		**************************************************/
		std::string delegate(const char *const parameter);
		/*************************************************/

		/**************************************************************************************************/
		
		/*************************************************
		* /api/delegates?limit=20
		*
		* @return: std::string
		*
		* @brief: Returns Delegates list, limited to top 20 to fit MCU.
		**************************************************/
		std::string delegates();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/delegates/count
		*
		* @return: std::string
		*
		* @brief: Gets current number of registered Delegates from a Node via API.
		**************************************************/
		std::string delegatesCount();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/delegates/search?q=sleepdeficit 
		*
		* @param: const char* const username
		* @return: std::string
		*
		* @brief: Searches for Delegate by username from a Node via API.
		**************************************************/
		std::string delegateSearch(const char *const username);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/delegates/fee
		*
		* @return: std::string
		*
		* @brief: Returns Delegate Registration Fee from a Node via API.
		**************************************************/
		std::string delegateFee();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey
		*
		* @param: const char *const generatorPublicKey
		* @return: std::string
		*
		* @brief: Returns Totals of Amounts Forged by Delegate by Publickey from a Node via API.
		**************************************************/
		std::string delegateForgedByAccount(const char *const generatorPublicKey);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/delegates/getNextForgers
		*
		* @return: std::string
		*
		* @brief: Returns next 10 Forging-Delegates from a Node via API.
		**************************************************/
		std::string delegateNextForgers();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/delegates/voters?publicKey=_pubKey
		*
		* @param: const char *const publicKey
		* @return: std::string
		*
		* @brief: Returns Voters list for Delegate by Publickey from a Node via API.
		**************************************************/
		std::string delegateVoters(const char *const publicKey);
		/*************************************************/
	};
	/*************************************************/

};
};
};

#endif



