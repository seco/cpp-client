

#include "api/one/accounts/one_accounts.h"

/*************************************************
* /api/accounts/getBalance?address=arkAddress
*
* @param: const char *const arkAddress
* @return: std::string
*
* @brief: Uses Ark Address to get an Accounts Confirmed and Unconfirmed Balances JSON string from a Node via API.
*
* EXAMPLE:
* {
*	"success":true,
*	"balance":  "Balance",
*	"unconfirmedBalance": "Balance"
* }
**************************************************/
std::string ARK::API::ONE::Accounts::accountBalance(
		const char *const arkAddress
) {
	char uri[68 + 1] = { '\0' };
		strcpy(uri, ARK::API::ONE::Paths::Accounts::getBalance_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress);
	return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* api/accounts/getPublickey?address=arkAddress
*
* @param: const char *const arkAddress
* @return: std::string
*
* @brief: Uses Ark Address to get an Account Publickey JSON string from a Node via API.
*
* EXAMPLE:
* {
*	"success":true,
*	"publicKey":  "Publickey"
* }
**************************************************/
std::string ARK::API::ONE::Accounts::accountPublickey(
		const char *const arkAddress
) {
	char uri[94 + 1] = { '\0' };
		strcpy(uri, ARK::API::ONE::Paths::Accounts::getPublickey_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress);
	return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/accounts/delegates/fee?address=arkAddress
*
* @param: const char *const arkAddress
* @return: std::string
*
* @brief: Uses Ark Address to get Delegate Registration Fee JSON string from a Node via API.
*
* EXAMPLE:
* {
* 	"success":true,
* 	"fee":2500000000
* }
**************************************************/
std::string ARK::API::ONE::Accounts::accountDelegatesFee(
		const char *const arkAddress
) {
	char uri[95 + 1] = { '\0' };
		strcpy(uri, ARK::API::ONE::Paths::Accounts::delegatesFee_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress);
	return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/accounts/delegates?address=arkAddress
*
* @param: const char *const arkAddress
* @return: std::string
*
* @brief: Uses Ark Address to get Delegate JSON string from a Node via API.
*
* EXAMPLE:
* {
*	"success":true,
*	"delegates":
*	[
*		{
*			"username": "sleepdeficit",
*			"address":  "Address",
*			"publicKey":  "Publickey",
*			"vote": "Balance",
*			"producedblocks": const char*,
*			"missedblocks": String,
*			"rate": int,
*			"approval": double,
*			"productivity": double
*		}
*	]
* }
**************************************************/
std::string ARK::API::ONE::Accounts::accountDelegates(
		const char *const arkAddress
) {
	char uri[91 + 1] = { '\0' };
		strcpy(uri, ARK::API::ONE::Paths::Accounts::delegates_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress);
	return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/accounts?address=arkAddress
*
* @param: const char *const arkAddress
* @return: std::string
*
* @brief: Uses Ark Address to get Account JSON string from a Node via API.
*
* EXAMPLE:
* {
*	"success":true,
*	"account":
*	{
*		"address":  "Address",
*		"unconfirmedBalance": "Balance",
*		"balance":  "Balance",
*		"publicKey":  "Publickey",
*		"unconfirmedSignature": int,
*		"secondSignature":  int,
*		"secondPublicKey":  "Publickey",
*		"multisignatures":[],
*		"u_multisignatures":[]
*	}
* }
**************************************************/
std::string ARK::API::ONE::Accounts::account(
		const char *const arkAddress
) {
	char uri[81 + 1] = { '\0' };
		strcpy(uri, ARK::API::ONE::Paths::Accounts::accounts_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress);
	return netConnector.callback(uri);
};
/*************************************************/
