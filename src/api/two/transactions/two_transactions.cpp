

#include "api/two/transactions/two_transactions.h"

std::string ARK::API::TWO::Transactions::transaction(const char *const identifier)
{
    char uri[80] = { '\0' };
	strcpy(uri, ARK::API::TWO::Paths::Transactions::base);
        strcat(uri, "/");
        strcat(uri, identifier);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Transactions::transactionUnconfirmed(const char *const identifier)
{
    char uri[80] = { '\0' };
	strcpy(uri, ARK::API::TWO::Paths::Transactions::unconfirmed);
        strcat(uri, "/");
        strcat(uri, identifier);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Transactions::transactions(
        unsigned int limit,
        unsigned int page
)
{
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[80] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Transactions::base);
        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Transactions::transactions(
        const char *const identifier,
        unsigned int limit,
        unsigned int page
)
{
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[80] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Transactions::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Transactions::transactionsUnconfirmed(
        unsigned int limit,
        unsigned int page
)
{
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[80] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Transactions::unconfirmed);
        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Transactions::transactionTypes(
        unsigned int limit,
        unsigned int page
)
{
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[80] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Transactions::types);
        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}
