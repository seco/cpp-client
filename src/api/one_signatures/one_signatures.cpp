

#include "api/one_signatures/one_signatures.h"

/*************************************************
* /api/signatures/fee
*
* EXAMPLE:
* {
*   "success":true,
*   "fee":  Balance
* }	
**************************************************/
std::string ARK::API::ONE_Signatures::signaturesFee()
{
    return netConnector.callback(ARK::API::ONE_Paths::ONE_Signatures::fee_s);
};
/*************************************************/
