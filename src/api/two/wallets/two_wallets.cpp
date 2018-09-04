

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
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
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
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
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
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
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
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
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
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
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
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
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
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Wallets::walletsSearch(
        std::pair<const char*, const char*> bodyParameters,
        int limit,
        int page
) {
    char uri[96] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Wallets::search);
        strcat(uri, "?limit=");
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());

    std::string parameterBuffer;
        parameterBuffer += bodyParameters.first;
        parameterBuffer += "=";
        parameterBuffer += bodyParameters.second;

    return connection.send(uri, parameterBuffer.c_str());
}
