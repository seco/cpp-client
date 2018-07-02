

#ifndef ONE_SIGNATURES_H
#define ONE_SIGNATURES_H

#include "connection/connector.h"
#include "api/one_paths.h"

namespace ARK
{
namespace API
{
/*************************************************
* PUBLIC: ARK::API::ONE_Signatures
* virtual ARK::Utilities::Network::Connectable
*    
* API's Signature Loader Model
**************************************************/
class ONE_Signatures :
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
