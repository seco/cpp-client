

#include "api/signaturable/signaturable.h"

/*************************************************
* /api/signatures/fee
*
* EXAMPLE:
* {
*   "success":true,
*   "fee":  Balance
* }	
**************************************************/
std::string ARK::API::Signaturable::signaturesFee()
{
    return netConnector.callback(ARK::API::Paths::Signatures::fee_s);
};
/*************************************************/
