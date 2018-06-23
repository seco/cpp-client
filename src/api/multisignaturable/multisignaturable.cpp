

#include "api/multisignaturable/multisignaturable.h"

/*************************************************
* /api/multisignatures/pending?publicKey=
*
* EXAMPLE:
* {
*   "success":true,
*   "transactions":[]
* }
**************************************************/
std::string ARK::API::MultiSignaturable::multisignaturesPending(
        const char *const publicKey
) {
    char uri[130 + 1] = { '\0' };
        strcpy(uri, ARK::API::Paths::MultiSignatures::pending_s);
        strcat(uri, "?publicKey=");
        strcat(uri, publicKey);
    return netConnector.callback(uri);
};
/*************************************************/
