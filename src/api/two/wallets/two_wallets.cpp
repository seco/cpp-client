

#include "api/two/wallets/two_wallets.h"

std::string ARK::API::TWO::Wallets::wallet(const char *const identifier)
{
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Wallets::wallets(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "?limit=");
        std::stringstream limitStream;
        limitStream << limit;
        strcat(uri, limitStream.str().c_str());
        strcat(uri, "&page=");
        std::stringstream pageStream;
        pageStream << page;
        strcat(uri, pageStream.str().c_str());
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Wallets::walletsTop(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Wallets::top);
        strcat(uri, "?limit=");
        std::stringstream limitStream;
        limitStream << limit;
        strcat(uri, limitStream.str().c_str());
        strcat(uri, "&page=");
        std::stringstream pageStream;
        pageStream << page;
        strcat(uri, pageStream.str().c_str());
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Wallets::walletsTransactions(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/transactions");
        strcat(uri, "?limit=");
        std::stringstream limitStream;
        limitStream << limit;
        strcat(uri, limitStream.str().c_str());
        strcat(uri, "&page=");
        std::stringstream pageStream;
        pageStream << page;
        strcat(uri, pageStream.str().c_str());
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Wallets::walletsTransactionsSent(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/transactions/sent");
        strcat(uri, "?limit=");
        std::stringstream limitStream;
        limitStream << limit;
        strcat(uri, limitStream.str().c_str());
        strcat(uri, "&page=");
        std::stringstream pageStream;
        pageStream << page;
        strcat(uri, pageStream.str().c_str());
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Wallets::walletsTransactionsReceived(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/transactions/received");
        strcat(uri, "?limit=");
        std::stringstream limitStream;
        limitStream << limit;
        strcat(uri, limitStream.str().c_str());
        strcat(uri, "&page=");
        std::stringstream pageStream;
        pageStream << page;
        strcat(uri, pageStream.str().c_str());
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Wallets::walletsVotes(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/votes");
        strcat(uri, "?limit=");
        std::stringstream limitStream;
        limitStream << limit;
        strcat(uri, limitStream.str().c_str());
        strcat(uri, "&page=");
        std::stringstream pageStream;
        pageStream << page;
        strcat(uri, pageStream.str().c_str());
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Wallets::walletsSearch(
        const char *const parameter,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, parameter);
        std::stringstream pageStream;
        pageStream << page;
        strcat(uri, pageStream.str().c_str());
    return netConnector.callback(uri);
}