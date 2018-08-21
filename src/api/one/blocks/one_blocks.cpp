

#include "api/one/blocks/one_blocks.h"

/*************************************************
* /api/blocks/get?id=_blockID
*
* @param: const char *const blockId
* @return: std::string
*
* @brief: Uses Block ID to get that Blocks information from a Node via API.
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
std::string ARK::API::ONE::Blocks::block(
    const char *const blockId)
{
    char uri[80] = {'\0'};
    strcpy(uri, ARK::API::ONE::Paths::Blocks::get_s);
    strcat(uri, "?id=");
    strcat(uri, blockId);
    return netConnector.callback(uri);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks?orderBy=height:desc&limit=10
*
* @return: std::string
*
* @brief: `/api/blocks` is too large for MCU's, so lets limit to the last 10 recent blocks
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
std::string ARK::API::ONE::Blocks::blocks()
{
    auto blocks = netConnector.callback(ARK::API::ONE::Paths::Blocks::blocks_s);
    return blocks;
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getEpoch
*
* @return: std::string
*
* @brief: Gets the Block Epoch from a Node via API.
*
* EXAMPLE:
* {
*   "success":true,
*   "epoch":  "String"
* }
**************************************************/
std::string ARK::API::ONE::Blocks::blockEpoch()
{
    return netConnector.callback(ARK::API::ONE::Paths::Blocks::getEpoch_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getFee
*
* @return: std::string
*
* @brief: Gets the current Block Fee from a Node via API.
*
* EXAMPLE:
* {
*   "success":true,
*   "fee":  Balance
* }
**************************************************/
std::string ARK::API::ONE::Blocks::blockFee()
{
    return netConnector.callback(ARK::API::ONE::Paths::Blocks::getFee_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getFees
*
* @return: std::string
*
* @brief: Gets the current Block Fees from a Node via API.
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
std::string ARK::API::ONE::Blocks::blockFees()
{
    return netConnector.callback(ARK::API::ONE::Paths::Blocks::getFees_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getHeight
*
* @return: std::string
*
* @brief: Gets the Block-Height from a Node via API.
*
* EXAMPLE:
* {
*   "success":true,
*   "height": String,
*   "id": "String"
* }
**************************************************/
std::string ARK::API::ONE::Blocks::blockHeight()
{
    return netConnector.callback(ARK::API::ONE::Paths::Blocks::getHeight_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getMilestone
*
* @return: std::string
*
* @brief: Gets the Block Milestone from a Node via API.
*
* EXAMPLE:
* {
*   "success":true,
*   "milestone": String
* }
**************************************************/
std::string ARK::API::ONE::Blocks::blockMilestone()
{
    return netConnector.callback(ARK::API::ONE::Paths::Blocks::getMilestone_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getNethash
*
* @return: std::string
*
* @brief: Gets the Networks Hash from a Node via API.

* EXAMPLE:
* {
*   "success":true,
*   "nethash":  "Hash"
* }
**************************************************/
std::string ARK::API::ONE::Blocks::blockNethash()
{
    return netConnector.callback(ARK::API::ONE::Paths::Blocks::getNethash_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getReward
*
* @return: std::string
*
* @brief: Gets the current Block Reward from a Node via API.
*
* EXAMPLE:
* { 
*   "success":true,
*   "reward": Balance
* }
**************************************************/
std::string ARK::API::ONE::Blocks::blockReward()
{
    return netConnector.callback(ARK::API::ONE::Paths::Blocks::getReward_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getSupply
*
* @return: std::string
*
* @brief: Gets the current Ark Supply from a Node via API.
*
* EXAMPLE:
* {
*   "success":true,
*   "supply": Balance
* }
**************************************************/
std::string ARK::API::ONE::Blocks::blockSupply()
{
    return netConnector.callback(ARK::API::ONE::Paths::Blocks::getSupply_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getStatus
*
* @return: std::string
*
* @brief: Gets the Ark Networks Status from a Node via API.
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
std::string ARK::API::ONE::Blocks::blockStatus()
{
    return netConnector.callback(ARK::API::ONE::Paths::Blocks::getStatus_s);
}
/*************************************************/
