

#include "api/one/signatures/one_signatures.h"

/*************************************************
* /api/signatures/fee
*
* @return: std::string
*
* @brief: Gets cost of Signature from a Node via API.
*
* EXAMPLE:
* {
*   "success":true,
*   "fee":  Balance
* }	
**************************************************/
std::string ARK::API::ONE::Signatures::signaturesFee()
{
    return netConnector.callback(ARK::API::ONE::Paths::Signatures::fee_s);
};
/*************************************************/
