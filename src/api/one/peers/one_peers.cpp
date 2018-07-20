

#include "api/one/peers/one_peers.h"

/*************************************************
* /api/peers/get?ip=167.114.29.55&port=4002
*
* @param:	const char *const ip
* @param:	const int port
* @return: std::string
*
* @brief:	Gets Ark Network Peer from a Node via API.
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
std::string ARK::API::ONE::Peers::peer(
		const char *const ip,
		const int port
) {
	char uri[68 + 1] = { '\0' };
		strcpy(uri, ARK::API::ONE::Paths::Peers::get_s);
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
* @return: std::string
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
std::string ARK::API::ONE::Peers::peers()
{
	char uri[39 + 1] = { '\0' };
		strcpy(uri, ARK::API::ONE::Paths::Peers::peers_s);
	return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/peers/version
*
* @return: std::string
*
* @brief: Gets Ark Network Peer Version from a Node via API.	
*
* EXAMPLE:
* {
*	"success":true,
*	"version": "String",
*	"build": "String"
* }
**************************************************/
std::string ARK::API::ONE::Peers::peerVersion()
{
	return netConnector.callback(ARK::API::ONE::Paths::Peers::version_s);
};
/*************************************************/
