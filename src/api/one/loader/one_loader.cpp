

#include "api/one/loader/one_loader.h"

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
std::string ARK::API::ONE::Loader::loaderAutoconfigure()
{
    return netConnector.callback(ARK::API::ONE::Paths::Loader::autoconfigure_s);
}
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
std::string ARK::API::ONE::Loader::loaderStatus()
{
    return netConnector.callback(ARK::API::ONE::Paths::Loader::status_s);
}
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
std::string ARK::API::ONE::Loader::loaderSync()
{
    return netConnector.callback(ARK::API::ONE::Paths::Loader::sync_s);
}
/*************************************************/
