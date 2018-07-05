

#include "api/one/signatures/one_signatures.h"

/*************************************************
* /api/signatures/fee
*
* EXAMPLE:
* {
*   "success":true,
*   "fee":  Balance
* }	
**************************************************/
std::string ARK::API::V1::Signatures::signaturesFee()
{
    return netConnector.callback(ARK::API::V1::Paths::Signatures::fee_s);
};
/*************************************************/
