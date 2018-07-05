

#include "api/one/accounts/one_accounts.h"

/*************************************************
* /api/accounts/getBalance?address=arkAddress
*
* EXAMPLE:
* {
*	"success":true,
*	"balance":  "Balance",
*	"unconfirmedBalance": "Balance"
* }
**************************************************/
std::string ARK::API::V1::Accounts::accountBalance(
		const char *const arkAddress
) {
	char uri[68 + 1] = { '\0' };
		strcpy(uri, ARK::API::V1::Paths::Accounts::getBalance_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress);
	return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* api/accounts/getPublickey?address=arkAddress
*
* EXAMPLE:
* {
*	"success":true,
*	"publicKey":  "Publickey"
* }
**************************************************/
std::string ARK::API::V1::Accounts::accountPublickey(
		const char *const arkAddress
) {
	char uri[94 + 1] = { '\0' };
		strcpy(uri, ARK::API::V1::Paths::Accounts::getPublickey_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress);
	return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/accounts/delegates/fee?address=arkAddress
*
* EXAMPLE:
* {
* 	"success":true,
* 	"fee":2500000000
* }
**************************************************/
std::string ARK::API::V1::Accounts::accountDelegatesFee(
		const char *const arkAddress
) {
	char uri[95 + 1] = { '\0' };
		strcpy(uri, ARK::API::V1::Paths::Accounts::delegatesFee_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress);
	return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/accounts/delegates?address=arkAddress
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
std::string ARK::API::V1::Accounts::accountDelegates(
		const char *const arkAddress
) {
	char uri[91 + 1] = { '\0' };
		strcpy(uri, ARK::API::V1::Paths::Accounts::delegates_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress);
	return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/accounts?address=arkAddress
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
std::string ARK::API::V1::Accounts::account(
		const char *const arkAddress
) {
	char uri[81 + 1] = { '\0' };
		strcpy(uri, ARK::API::V1::Paths::Accounts::accounts_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress);
	return netConnector.callback(uri);
};
/*************************************************/
