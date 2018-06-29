

#include "api/one_transactions/one_transactions.h"

/*************************************************
* /api/transactions/get?id=
*
* EXAMPLE:
* {
*  "success": true,
*  "transaction": {
*    "id": "4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e",
*	 "blockid": "14671461178414977683",
*    "height": 1696504,
*    "type": 0,
*    "timestamp": 19637685,
*    "amount": 149,
*    "fee": 10000000,
*    "vendorField": "1ARK-GOLang is saying whoop whooop",
*    "senderId": "DPJBH7wfE1msZMVDQLeJUPi31fJZodJCkU",
*    "recipientId": "DFTzLwEHKKn3VGce6vZSueEmoPWpEZswhB",
*    "senderPublicKey": "03a151b47a5779949a47dd9c17e05c832304721a242b535f36528cd7e547dac439",
*    "signature": "3045022100dc9590c6c6fce66a523481f13237d95518056387076de9a9534cb4a039fbede90220322e7f17b227f8fe9401460980b7b3c1baacf076b9020620ec5c4388673e7e12",
*    "confirmations": "1868079"
*  }
* }
**************************************************/
std::string ARK::API::ONE_Transactions::transaction(const char *const id)
{
	char uri[114 + 1] = { '\0' };
		strcpy(uri, ARK::API::ONE_Paths::ONE_Transactions::getSingle_s);
		strcat(uri, "?id=");
		strcat(uri, id);
	return netConnector.callback(uri);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/transactions/get?id=
*
* EXAMPLE:
* {
*  "success": true,
*  "transactions":
*	[
*		{
*			"id": "string",
*			"blockid": "string",
*			"height": int,
*			"type": ing,
*			"timestamp": ing,
*			"amount": Balance,
*			"fee": Balance,
*			"vendorField": "string",
*			"senderId": "Address",
*			"recipientId": "Address",
*			"senderPublicKey": "Publickey",
*			"signature": "Signature",
*			"confirmations": "string"
*		},
*		...
*		{
*			"id": "string",
*			"blockid": "string",
*			"height": int,
*			"type": ing,
*			"timestamp": ing,
*			"amount": Balance,
*			"fee": Balance,
*			"vendorField": "string",
*			"senderId": "Address",
*			"recipientId": "Address",
*			"senderPublicKey": "Publickey",
*			"signature": "Signature",
*			"confirmations": "string"
*		}
*	]
*	"count": "int"
* }
**************************************************/
std::string ARK::API::ONE_Transactions::transactions()
{
	char uri[69] = { '\0' };
		strcpy(uri, ARK::API::ONE_Paths::ONE_Transactions::transactions_s);
	return netConnector.callback(uri);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/transactions/unconfirmed/get?id=
*
* EXAMPLE:
* { 
*	"success":true,
*	"transaction":
*	{
*		"id": Hash,
*		"blockid":"_blockID",
*		"height":_height,
*		"type":_type,
*		"timestamp":_timestamp,
*		"amount":_amount,
*		"fee":_fee,
*		"vendorField":_vendorField,
*		"senderId":"_senderId",
*		"recipientId":"_recipientId",
*		"senderPublicKey":_senderPubkey,
*		"signature":"_txSig",
*		"confirmations":_confirmations
*	}
* }
*	| or |
* {
*	"success":false,
*	"error":"Transaction not found"
* }
**************************************************/
std::string ARK::API::ONE_Transactions::transactionUnconfirmed(const char *const id)
{
	char uri[126 + 1] = { '\0' };
		strcpy(uri, ARK::API::ONE_Paths::ONE_Transactions::getSingleUnconfirmed_s);
		strcat(uri, "?id=");
		strcat(uri, id);
	return netConnector.callback(uri);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/transactions/unconfirmed
*
* EXAMPLE:
* {
*	"success":true,
*	"transactions":[]
* }
**************************************************/
std::string ARK::API::ONE_Transactions::transactionsUnconfirmed()
{
	return netConnector.callback(ARK::API::ONE_Paths::ONE_Transactions::unconfirmed_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/transactions/get?id=
*
* @brief: Gets vendorField for a given Transaction by  txID from a Node via API.
**************************************************/
std::string ARK::API::ONE_Transactions::getVendorField(const char *const txID)
{
	char uri[114 + 1] = { '\0' };
		strcpy(uri, ARK::API::ONE_Paths::ONE_Transactions::getSingle_s);
		strcat(uri, "?id=");
		strcat(uri, txID);
	return netConnector.callback(uri);
}
/*************************************************/
