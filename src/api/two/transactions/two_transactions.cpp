

#include "api/two/transactions/two_transactions.h"

std::string ARK::API::TWO::Transactions::transaction(const char *const identifier)
{
    char uri[96] = { '\0' };
    strcpy(uri, ARK::API::TWO::Paths::Transactions::base);
        strcat(uri, "/");
        strcat(uri, identifier);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Transactions::transactionUnconfirmed(const char *const identifier)
{
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Transactions::unconfirmed);
        strcat(uri, "?id=");
        strcat(uri, identifier);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Transactions::transactions(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Transactions::base);
        strcat(uri, "?limit=");
        char limitBuffer[1];
        sprintf(limitBuffer, "%d", limit); 
        std::strcat(uri, limitBuffer);
        strcat(uri, "&page=");
        char pageBuffer[1];
        sprintf(pageBuffer, "%d", page); 
        std::strcat(uri, pageBuffer);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Transactions::transactions(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Transactions::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "?limit=");
        char limitBuffer[1];
        sprintf(limitBuffer, "%d", limit); 
        std::strcat(uri, limitBuffer);
        strcat(uri, "&page=");
        char pageBuffer[1];
        sprintf(pageBuffer, "%d", page); 
        std::strcat(uri, pageBuffer);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Transactions::transactionsUnconfirmed(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Transactions::unconfirmed);
        strcat(uri, "?limit=");
        char limitBuffer[1];
        sprintf(limitBuffer, "%d", limit); 
        std::strcat(uri, limitBuffer);
        strcat(uri, "&page=");
        char pageBuffer[1];
        sprintf(pageBuffer, "%d", page); 
        std::strcat(uri, pageBuffer);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Transactions::transactionTypes(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Transactions::types);
        strcat(uri, "?limit=");
        char limitBuffer[1];
        sprintf(limitBuffer, "%d", limit); 
        std::strcat(uri, limitBuffer);
        strcat(uri, "&page=");
        char pageBuffer[1];
        sprintf(pageBuffer, "%d", page); 
        std::strcat(uri, pageBuffer);
    return netConnector.callback(uri);
}
