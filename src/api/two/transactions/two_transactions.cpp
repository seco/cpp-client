

#include "api/two/transactions/two_transactions.h"

std::string Ark::API::TWO::Transactions::transaction(const char *const identifier)
{
    char uri[96] = { '\0' };
    strcpy(uri, Ark::API::TWO::Paths::Transactions::base);
        strcat(uri, "/");
        strcat(uri, identifier);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Transactions::transactionUnconfirmed(const char *const identifier)
{
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Transactions::unconfirmed);
        strcat(uri, "?id=");
        strcat(uri, identifier);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Transactions::transactions(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Transactions::base);
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Transactions::transactions(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Transactions::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Transactions::transactionsUnconfirmed(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Transactions::unconfirmed);
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Transactions::transactionTypes(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Transactions::types);
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return netConnector.callback(uri);
}
