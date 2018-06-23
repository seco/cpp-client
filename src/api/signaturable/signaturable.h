

#ifndef SIGNATURABLE_H
#define SIGNATURABLE_H

#include "utils/connector.h"
#include "api/paths.h"

namespace ARK
{
namespace API
{
/*************************************************
* PUBLIC: ARK::API::Signaturable
* public Signature::Gettable
* virtual ARK::Utilities::Network::Connectable
*    
* API's Signature Loader Model
**************************************************/
class Signaturable :
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		* /api/signatures/fee
		*
		* @method: signaturesFee()
		* @return: Balance
		*
		* @brief: Gets cost of Signature from a Node via API.
		**************************************************/
		std::string signaturesFee();
		/*************************************************/
};
/*************************************************/

};
};

#endif
