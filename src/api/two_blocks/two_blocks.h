

#ifndef TWO_BLOCKS_H
#define TWO_BLOCKS_H

#include "platform/platform.h"
#include "utils/connector.h"
#include "api/two_paths.h"

namespace ARK
{
namespace API
{
/*************************************************
* PUBLIC: ARK::API::TWO_Blocks
* virtual ARK::Utilities::Network::Connectable
*    
* API's Blocks Model
**************************************************/
class TWO_Blocks :
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







		};
/*************************************************/
};
};

#endif
