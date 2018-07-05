

#ifndef ONE_BLOCKS_H
#define ONE_BLOCKS_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/one/one_paths.h"

#include <memory>
#include <vector>

namespace ARK
{
namespace API
{
namespace V1
{
/*************************************************
* PUBLIC: ARK::API::V1::Blocks
* virtual ARK::Utilities::Network::Connectable
*    
* API's Block Model
**************************************************/
class Blocks :
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		* /api/blocks/get?id=_blockID
		*
		* @param: const char *const blockId
		* @return: std::string
		*
		* @brief: Uses Block ID to get that Blocks information from a Node via API.
		**************************************************/
		std::string block(const char *const blockId);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks?orderBy=height:desc&limit=20
		*
		* @return: std::string
		*
		* @brief: `/api/blocks` is too large for MCU's, so lets limit to the last 20
		**************************************************/
		std::string blocks();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getEpoch
		*
		* @return: std::string
		*
		* @brief: Gets the Block Epoch from a Node via API.
		**************************************************/
		std::string blockEpoch();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getFee
		*
		* @return: std::string
		*
		* EXAMPLE:
		* {
		*   "success":true,
		*   "fee": Balance
		* }
		**************************************************/
		std::string blockFee();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getFees
		*
		* @return: std::string
		*
		* @brief: Gets Ark Network Fees from a Node via API.
		**************************************************/
		std::string blockFees();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getHeight
		*
		* @return: std::string
		*
		* @brief: Gets the Block-Height from a Node via API.
		**************************************************/
		std::string blockHeight();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getMilestone
		*
		* @return: std::string
		*
		* @brief: Gets the Block Milestone from a Node via API.
		**************************************************/
		std::string blockMilestone();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getNethash
		*
		* @return: std::string
		*
		* @brief: Gets the Networks Hash from a Node via API.
		**************************************************/
		std::string blockNethash();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getReward
		*
		* @return: std::string
		*
		* @brief: Gets the Block Reward from a Node via API.
		**************************************************/
		std::string blockReward();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getSupply
		*
		* @return: std::string
		*
		* @brief: Gets the current Ark Supply from a Node via API.
		**************************************************/
		std::string blockSupply();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getStatus
		*
		* @return: std::string
		*
		* @brief: Gets the Ark Networks Status from a Node via API.
		**************************************************/
		std::string blockStatus();
		/*************************************************/

};
/*************************************************/

};
};
};

#endif
