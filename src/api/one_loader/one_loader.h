

#ifndef ONE_LOADER_H
#define ONE_LOADER_H

#include "connection/connector.h"
#include "api/one_paths.h"

namespace ARK
{
namespace API
{
/*************************************************
* PUBLIC: ARK::API::ONE_Loader
* virtual ARK::Utilities::Network::Connectable
*    
* API's Network Loader Model
**************************************************/
class ONE_Loader :
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		* /api/loader/autoconfigure
		*
		* @return: std::string
		*
		* @brief: Returns an auto-configured network from a Networks NetHash from a Node via API. 
		*
		* EXAMPLE:
		* {
		*	"success":true,
		*	"network":
		*	{
		*		"nethash":  "Hash",
		*		"token":  "const char*",
		*		"symbol": "const char*,
		*		"explorer": "const char*",
		*		"version":  int
		*	}
		* }
		**************************************************/
		std::string loaderAutoconfigure();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/loader/status
		*
		* @return: std::string
		*
		* @brief: Gets Ark Network Status from a Node via API.
		*
		* EXAMPLE:
		* { 
		*	"success":true,
		*	"loaded": bool,
		*	"now":  int,
		*	"blocksCount":  const char*
		* }
		**************************************************/
		std::string loaderStatus();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/loader/status/sync
		*
		* @return: std::string
		*
		* @brief: Gets Ark Network Sync Status from a Node via API. 
		*
		* EXAMPLE:
		* { 
		*	"success": bool,
		*	"syncing":  bool,
		*	"blocks": int,
		*	"height": const char*,
		*	"id": "const char*"
		* }
		**************************************************/
		std::string loaderSync();
		/*************************************************/
		
};
/*************************************************/

};
};

#endif
