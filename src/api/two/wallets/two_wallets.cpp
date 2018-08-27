

#include "api/two/wallets/two_wallets.h"

std::string Ark::API::TWO::Wallets::wallet(const char *const identifier)
{
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Wallets::wallets(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Wallets::wallets(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Wallets::base);
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Wallets::walletsTop(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Wallets::top);
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Wallets::walletsTransactions(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/transactions");
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Wallets::walletsTransactionsSent(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/transactions/sent");
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Wallets::walletsTransactionsReceived(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/transactions/received");
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Wallets::walletsVotes(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/votes");
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Wallets::walletsSearch(
        const char *const parameter,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, parameter);
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}
