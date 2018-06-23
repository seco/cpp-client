

#ifndef MULTISIGNATURABLE_H
#define MULTISIGNATURABLE_H

#include "platform/platform.h"
#include "utils/connector.h"
#include "api/paths.h"

#include <cstring>

namespace ARK
{
namespace API
{
/*************************************************
* PUBLIC: ARK::API::MultiSignaturable
* virtual ARK::Utilities::Network::Connectable
*    
* API's Multisignature Loader Model
**************************************************/
class MultiSignaturable :
		virtual ARK::Utilities::Network::Connectable
{
public:
	/*************************************************
	* /api/multisignatures/pending?publicKey=
	*
	* @param: const char *const publicKey
	* @returnType: std::string
	*
	* @brief: Gets Pending Multisignatures of	Account by Publickey from a Node via API.
	**************************************************/
	std::string multisignaturesPending(const char *const publicKey);
	/*************************************************/

};

};
};

#endif


	/**************************************************************************************************/
	/**************************************************************************************************/
	/*************************************************/
	/*************************************************/
	// /*  Only on Mainnet?  */
	//     /*  /api/multisignatures/accounts?publicKey=  */
	//     String multisignaturesAccounts(String _publicKey)
	//     { return ARK::API::MultiSignature::Gettable::accounts(this->netConnector, _publicKey); };
	/*************************************************/
	/*************************************************/
/*  ARK::API::MultiSignature::Gettable::accounts  */
// /*  /api/multisignatures/accounts?publicKey=  */
// String ARK::API::MultiSignatureGettable::accounts(ARK::Utilities::Network::Connector _netConnector, String _publicKey) {
//   String uri = ARK::API::Paths::MultiSignatures::accounts_s;
//     uri += "?publicKey=";
//     uri += _publicKey;
//   String callback = _netConnector.cb(uri);
//   return ARK::API::MultiSignature::Gettable::accountsfromJSON(callback);
// };

/*  Only on Mainnet?  */
// String ARK::API::MultiSignature::Gettable::accountsfromJSON(String _jsonStr) {
//   ARK::Utilities::JSONString jString(_jsonStr);
//   return jString.valueFor("??");
// };
	/**************************************************************************************************/
	/**************************************************************************************************/
	