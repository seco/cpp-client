

#include "api/one/peers/one_peers.h"

/*************************************************
* /api/peers/get?ip=167.114.29.55&port=4002
*
* EXAMPLE:
* { 
*	"success":true,
*	"peer":
*	{
*		"ip": "String",
*		"port": int,
*		"version":  "String",
*		"errors": int,
*		"os": "String",
*		"height": String,
*		"status": "String",
*		"delay":  int
*	}
* }
**************************************************/
std::string ARK::API::V1::Peers::peer(
		const char *const ip,
		const int port
) {
	char uri[68 + 1] = { '\0' };
		strcpy(uri, ARK::API::V1::Paths::Peers::get_s);
		strcat(uri, "?ip=");
		strcat(uri, ip);
		strcat(uri, "&port=");
	const auto len = strlen(uri);
		sprintf(uri + len, "%d", port);
	return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/peers?limit=20
*
* @brief: return list of Peers, limited to 20 to fit MCU's.
*
* EXAMPLE:
* {
*	"success":true,
*	"peers":
*	[
*		{
*			"ip": "string",
*			"port": int,
*			"version": "string",
*			"errors": int,
*			"os": "string",
*			"height": int,
*			"status": "string",
*			"delay": int
*		},
*		...
*		{
*			"ip": "string",
*			"port": int,
*			"version": "string",
*			"errors": int,
*			"os": "string",
*			"height": int,
*			"status": "string",
*			"delay": int
*		}
*	]
* }
**************************************************/
std::string ARK::API::V1::Peers::peers()
{
	char uri[39 + 1] = { '\0' };
		strcpy(uri, ARK::API::V1::Paths::Peers::peers_s);
	return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/peers/version
*
* EXAMPLE:
* {
*	"success":true,
*	"version": "String",
*	"build": "String"
* }
**************************************************/
std::string ARK::API::V1::Peers::peerVersion()
{
	return netConnector.callback(ARK::API::V1::Paths::Peers::version_s);
};
/*************************************************/
