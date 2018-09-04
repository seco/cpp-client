

#include "api/two/blocks/two_blocks.h"

std::string Ark::API::TWO::Blocks::block(
        const char *const blockId
) {
    char uri[80] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Blocks::base);
        strcat(uri, "/");
        strcat(uri, blockId);
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Blocks::blocks(
        int limit,
        const int page
) {
    char uri[256] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Blocks::base);
        strcat(uri, "?limit=");
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Blocks::blockTransactions(
        const char *const blockId,
        int limit,
        int page
) {
    char uri[256] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Blocks::base);
        strcat(uri, "/");
        strcat(uri, blockId);
        strcat(uri, "/transactions");
        strcat(uri, "?limit=");
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Blocks::blocksSearch(
        std::pair<const char*, const char*> bodyParameters,
        int limit,
        int page
) {
    char uri[96] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Blocks::search);
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
