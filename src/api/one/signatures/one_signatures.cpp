
#include "api/one/signatures/one_signatures.h"

/*************************************************
 * /api/signatures/fee
 *************************************************/
std::string Ark::API::ONE::Signatures::signaturesFee()
{
    return netConnector.callback(Ark::API::ONE::Paths::Signatures::fee_s);
};
/*************************************************/
