

#include "api/one/delegates/one_delegates.h"

/*************************************************
* /api/delegates/get?username="username"
* /api/delegates/get?publicKey=publicKey
*
* @param: const char *const parameter
* @return: std::string
*
* @brief: Returns Delegate by username or publickey from a Node via API.
*
* EXAMPLE:
* { 
*	"success":true,
*	"delegate":
* 	{
*		"username": "sleepdeficit",
*		"address":  "Address",
*		"publicKey":  "Publickey",
*		"vote": "Balance",
*		"producedblocks": const char*,
*		"missedblocks": const char*,
*		"rate": int,
*		"approval": double,
*		"productivity": double
*	}
* }
**************************************************/
std::string ARK::API::ONE::Delegates::delegate(
    const char *const parameter)
{
    char uri[120 + 1] = {'\0'}; //max size (pubkey param)
    strcpy(uri, ARK::API::ONE::Paths::Delegates::get_s);
    bool isUsername = (strlen(parameter) <= 20);
    auto key = (isUsername) ? ("?username=") : ("?publicKey=");
    strcat(uri, key);
    strcat(uri, parameter);
    return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/delegates?limit=20
*
* @return: std::string
*
* @brief: Returns Delegates list, limited to top 20 to fit MCU.
*
* EXAMPLE:
* { 
*	"success":true,
*	"delegates":
*	[
*		{
*			"username": "string",
*			"address":  "Address",
*			"publicKey":  "Publickey",
*			"vote": "Balance",
*			"producedblocks": const char*,
*			"missedblocks": const char*,
*			"rate": int,
*			"approval": double,
*			"productivity": double
* 		},
*		...
*		{
*			"username": "string",
*			"address":  "Address",
*			"publicKey":  "Publickey",
*			"vote": "Balance",
*			"producedblocks": const char*,
*			"missedblocks": const char*,
*			"rate": int,
*			"approval": double,
*			"productivity": double
* 		}
*	]
*	totalCount: 227
* }
**************************************************/
std::string ARK::API::ONE::Delegates::delegates()
{
    char uri[43] = {'\0'};
    strcpy(uri, ARK::API::ONE::Paths::Delegates::delegates_s);
    return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/delegates/count
*
* @return: std::string
*
* @brief: Gets current number of registered Delegates from a Node via API.
*
* EXAMPLE:
* { 
*	"success":true,
*	"count":166
* }
**************************************************/
std::string ARK::API::ONE::Delegates::delegatesCount()
{
    return netConnector.callback(ARK::API::ONE::Paths::Delegates::count_s);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/delegates/search?q=sleepdeficit 
*
* @param: const char* const username
* @return: std::string
*
* @brief: Searches for Delegate by username from a Node via API.
*
* EXAMPLE:
* { 
*	"success":true,
*	"delegates":
*	[
*		{ 
*			"username":"_username",
*			"address":"_arkAddress",
*			"publicKey":"_pubkey",
*			"vote":"0000000000000",
*			"producedblocks":0,
*			"missedblocks":0
*		}
*	]
* }
**************************************************/
std::string ARK::API::ONE::Delegates::delegateSearch(
    const char *const username)
{
    char uri[69 + 1] = {'\0'};
    strcpy(uri, ARK::API::ONE::Paths::Delegates::search_s);
    strcat(uri, "?q=");
    strcat(uri, username);
    return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/delegates/fee
*
* EXAMPLE:
* {
*	"success":true,
*	"fee":  Balance
* }
**************************************************/
std::string ARK::API::ONE::Delegates::delegateFee()
{
    return netConnector.callback(ARK::API::ONE::Paths::Delegates::fee_s);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey
*
* @param: const char *const generatorPublicKey
* @return: std::string
*
* @brief: Returns Totals of Amounts Forged by Delegate by Publickey from a Node via API.
*
* EXAMPLE:
* {
*	"success":true,
*	"fees": "Balance",
*	"rewards":  "Balance",
*	"forged": "Balance"
* }
**************************************************/
std::string ARK::API::ONE::Delegates::delegateForgedByAccount(
    const char *const generatorPublicKey)
{
    char uri[152 + 1];
    strcpy(uri, ARK::API::ONE::Paths::Delegates::getForgedByAccount_s);
    strcat(uri, "?generatorPublicKey=");
    strcat(uri, generatorPublicKey);
    return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/delegates/getNextForgers
*
* @return: std::string
*
* @brief: Returns next 10 Forging-Delegates from a Node via API.

*
* EXAMPLE:
* { 
*	"success":true,
*	"currentBlock":2307497,
*	"currentSlot":3189409,
*	"delegates":
*	[
*		"035ce69858a12a5ac31575c35c7c87a84a1b6a0455697d7015ea756a880aef05c0",
*		"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456",
*		"028f0a25321cd9d3bf051b34a835cd5eee0125120c17654bc95790f8f2d970dc46",
*		"027d607ba6226b302357aa9b4bb75d0e44761780492f0b38b267d2962d242e6a52",
*		"02b7b740973db16cd9c6f0f6f2bc160d27cd2a855e172d887833141bec234eb80c",
*		"0212ba6565ea6900ecf1fc5eee172f74aff8b22963be5d0d60e7f773db0055cbd2",
*		"02524ea2e2e9bad0ecbe521756388bf65e0b09dd2877d96495fe60200a97b35ddb",
*		"02dc13fcb190bcfbe9e7ecfc6269635ed2c497a75bab471f2b15c1a99897da97b3",
*		"022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d",
*		"031f3dffe4d10f78d85806d6b46f9c9a116e1aa56e8c538da2e02a416ff654b1db"
*	]
* }
**************************************************/
std::string ARK::API::ONE::Delegates::delegateNextForgers()
{
    return netConnector.callback(ARK::API::ONE::Paths::Delegates::getNextForgers_s);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/delegates/voters?publicKey=_pubKey
*
* @param: const char *const publicKey
* @return: std::string
*
* @brief: Returns Voters list for Delegate by Publickey from a Node via API.
*
* EXAMPLE:
* {
*	"success":true,
*	"accounts":
*	[
*		{ 
*			"username": "const char*",
*			"address":  "Balance",
*			"publicKey":  "Publickey",
*			"balance":  "Balance"
*		},
*		{
*			"username": "const char*",
*			"address":  "Address",
*			"publicKey":  "Publickey",
*			"balance":  "Balance"
*		}
*	]
* }
**************************************************/
std::string ARK::API::ONE::Delegates::delegateVoters(
    const char *const publicKey)
{
    char uri[123 + 1] = {'\0'};
    strcpy(uri, ARK::API::ONE::Paths::Delegates::voters_s);
    strcat(uri, "?publicKey=");
    strcat(uri, publicKey);
    return netConnector.callback(uri);
};
/*************************************************/
