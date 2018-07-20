

#include "api/two/wallets/two_wallets.h"


std::string ARK::API::TWO::Wallets::wallet(const char *const identifier)
{
    char uri[120] = { '\0' };
	    strcpy(uri, ARK::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Wallets::wallets(
        const char *const identifier,
        const unsigned int limit,
        const unsigned int page
) {
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[120] = { '\0' };
	    strcpy(uri, ARK::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Wallets::walletsTop(
        const unsigned int limit,
        const unsigned int page
) {
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[120] = { '\0' };
	    strcpy(uri, ARK::API::TWO::Paths::Wallets::top);
        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Wallets::walletsTransactions(
        const char *const identifier,
        const unsigned int limit,
        const unsigned int page
) {
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[120] = { '\0' };
	    strcpy(uri, ARK::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/transactions");
        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Wallets::walletsTransactionsSent(
        const char *const identifier,
        const unsigned int limit,
        const unsigned int page
) {
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[120] = { '\0' };
	    strcpy(uri, ARK::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/transactions/sent");
        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Wallets::walletsTransactionsReceived(
        const char *const identifier,
        const unsigned int limit,
        const unsigned int page
) {
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[120] = { '\0' };
	    strcpy(uri, ARK::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/transactions/received");
        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Wallets::walletsVotes(
        const char *const identifier,
        const unsigned int limit,
        const unsigned int page
) {
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[120] = { '\0' };
	    strcpy(uri, ARK::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/votes");
        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Wallets::walletsSearch(
        const unsigned int limit,
        const unsigned int page
) {
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[120] = { '\0' };
	    strcpy(uri, ARK::API::TWO::Paths::Wallets::search);
        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}