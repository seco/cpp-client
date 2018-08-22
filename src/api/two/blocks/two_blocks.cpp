

#include "api/two/blocks/two_blocks.h"

std::string Ark::API::TWO::Blocks::block(
        const char *const blockId
) {
    char uri[80] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Blocks::base);
        strcat(uri, "/");
        strcat(uri, blockId);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Blocks::blocks() {
    char uri[28] = { '\0' };
    #ifdef USE_IOT
        strcpy(uri, Ark::API::TWO::Paths::Blocks::base);
    #else
        strcpy(uri, Ark::API::TWO::Paths::Blocks::base);
        strcat(uri, "?limit=10&page=1");
    #endif
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Blocks::blocks(
        int limit,
        const int page
) {
    char uri[256] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Blocks::base);
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Blocks::blockTransactions(
        const char *const blockId
) {
    char uri[256] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Blocks::base);
        strcat(uri, "/");
        strcat(uri, blockId);
        strcat(uri, "/transactions");
    return netConnector.callback(uri);
}
