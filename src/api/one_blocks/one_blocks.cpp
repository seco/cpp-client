


#include "api/one_blocks/one_blocks.h"

/*************************************************
* /api/blocks/get?id=_blockID
*
* EXAMPLE:
* {
*   "success":true,
*   "block":
*   {
*     "id": char[],
*     "version": int,
*     "timestamp": char[],
*     "height": char[],
*     "previousBlock": char[],
*     "numberOfTransactions": char[],
*     "totalAmount": Balance,
*     "totalFee": Balance,
*     "reward": Balance,
*     "payloadLength": char[],
*     "payloadHash":  "Hash",
*     "generatorPublicKey": "Publickey",
*     "generatorId":  "Address",
*     "blockSignature": "Signature",
*     "confirmations":   char[],
*     "totalForged":" Balance"
*   }
* }
**************************************************/
std::string ARK::API::ONE_Blocks::block(
		const char *const blockId
) {
	char uri[80] = { '\0' };
		strcpy(uri, ARK::API::ONE_Paths::ONE_Blocks::get_s);
		strcat(uri, "?id=");
		strcat(uri, blockId);
	return netConnector.callback(uri);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks?orderBy=height:desc&limit=20
*
* @brief: `/api/blocks` is too large for MCU's, so lets limit to the last 20 recent blocks
*
* EXAMPLE:
* {
*   "success":true,
*   "blocks":
*	[
*		{
*			"id": char[],
*			"version": int,
*			"timestamp": char[],
*			"height": char[],
*			"previousBlock": char[],
*			"numberOfTransactions": char[],
*			"totalAmount": Balance,
*			"totalFee": Balance,
*			"reward": Balance,
*			"payloadLength": char[],
*			"payloadHash":  "Hash",
*			"generatorPublicKey": "Publickey",
*			"generatorId":  "Address",
*			"blockSignature": "Signature",
*			"confirmations":   char[],
*			"totalForged":" Balance"
*		},
*		...
*		{
*			"id": char[],
*			"version": int,
*			"timestamp": char[],
*			"height": char[],
*			"previousBlock": char[],
*			"numberOfTransactions": char[],
*			"totalAmount": Balance,
*			"totalFee": Balance,
*			"reward": Balance,
*			"payloadLength": char[],
*			"payloadHash":  "Hash",
*			"generatorPublicKey": "Publickey",
*			"generatorId":  "Address",
*			"blockSignature": "Signature",
*			"confirmations":   char[],
*			"totalForged":" Balance"
*		}
*	],
*	"count": 3639000
* }
**************************************************/
std::string ARK::API::ONE_Blocks::blocks()
{
	char uri[61 + 1] = { '\0' };
		strcpy(uri, ARK::API::ONE_Paths::ONE_Blocks::blocks_s);
	return netConnector.callback(uri);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getEpoch
*
* EXAMPLE:
* {
*   "success":true,
*   "epoch":  "String"
* }
**************************************************/
std::string ARK::API::ONE_Blocks::blockEpoch()
{
	return netConnector.callback(ARK::API::ONE_Paths::ONE_Blocks::getEpoch_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getFee
*
* EXAMPLE:
* {
*   "success":true,
*   "fee":  Balance
* }
**************************************************/
std::string ARK::API::ONE_Blocks::blockFee()
{
	return netConnector.callback(ARK::API::ONE_Paths::ONE_Blocks::getFee_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getFees
*
* EXAMPLE:
*
* {
*   "success":true,
*   "fees":
*   {
*     "send": Balance,
*     "vote": Balance,
*     "secondsignature": Balance,
*     "delegate": Balance,
*     "multisignature": Balance
*   }
* }
**************************************************/
std::string ARK::API::ONE_Blocks::blockFees()
{
	return netConnector.callback(ARK::API::ONE_Paths::ONE_Blocks::getFees_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getHeight
*
* EXAMPLE:
* {
*   "success":true,
*   "height": String,
*   "id": "String"
* }
**************************************************/
std::string ARK::API::ONE_Blocks::blockHeight()
{
	return netConnector.callback(ARK::API::ONE_Paths::ONE_Blocks::getHeight_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getMilestone
*
* EXAMPLE:
* {
*   "success":true,
*   "milestone": String
* }
**************************************************/
std::string ARK::API::ONE_Blocks::blockMilestone()
{
	return netConnector.callback(ARK::API::ONE_Paths::ONE_Blocks::getMilestone_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getNethash
*
* EXAMPLE:
* {
*   "success":true,
*   "nethash":  "Hash"
* }
**************************************************/
std::string ARK::API::ONE_Blocks::blockNethash()
{
	return netConnector.callback(ARK::API::ONE_Paths::ONE_Blocks::getNethash_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getReward
*
* EXAMPLE:
* { 
*   "success":true,
*   "reward": Balance
* }
**************************************************/
std::string ARK::API::ONE_Blocks::blockReward()
{
	return netConnector.callback(ARK::API::ONE_Paths::ONE_Blocks::getReward_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getSupply
*
* EXAMPLE:
* {
*   "success":true,
*   "supply": Balance
* }
**************************************************/
std::string ARK::API::ONE_Blocks::blockSupply()
{
	return netConnector.callback(ARK::API::ONE_Paths::ONE_Blocks::getSupply_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getStatus
*
* EXAMPLE:
* {
*   "success":true,
*   "epoch":  "String",
*   "height": String,
*   "fee":  Balance,
*   "milestone":  String,
*   "nethash":" Hash",
*   "reward":_reward,
*   "supply":_supply
* }
**************************************************/
std::string ARK::API::ONE_Blocks::blockStatus()
{
	return netConnector.callback(ARK::API::ONE_Paths::ONE_Blocks::getStatus_s);
}
/*************************************************/
