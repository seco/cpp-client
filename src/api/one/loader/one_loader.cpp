

#include "api/one/loader/one_loader.h"

/*************************************************
* /api/loader/autoconfigure 
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
std::string ARK::API::V1::Loader::loaderAutoconfigure()
{
	return netConnector.callback(ARK::API::V1::Paths::Loader::autoconfigure_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/loader/status
*
* EXAMPLE:
* { 
*	"success":true,
*	"loaded": bool,
*	"now":  int,
*	"blocksCount":  const char*
* }
**************************************************/
std::string ARK::API::V1::Loader::loaderStatus()
{
	return netConnector.callback(ARK::API::V1::Paths::Loader::status_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/loader/status/sync
*
* EXAMPLE:
* { 
*	"success":true,
*	"syncing":  bool,
*	"blocks": int,
*	"height": const char*,
*	"id": "const char*"
* }
**************************************************/
std::string ARK::API::V1::Loader::loaderSync()
{
	return netConnector.callback(ARK::API::V1::Paths::Loader::sync_s);
}
/*************************************************/
