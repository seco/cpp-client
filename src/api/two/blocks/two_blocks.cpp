

#include "api/two/blocks/two_blocks.h"

std::string ARK::API::TWO::Blocks::block(
        const char *const blockId
) {
    char uri[80] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Blocks::base);
        strcat(uri, "/");
        strcat(uri, blockId);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Blocks::blocks() {
    char uri[28] = { '\0' };
    #ifdef USE_IOT
        strcpy(uri, ARK::API::TWO::Paths::Blocks::base);
    #else
        strcpy(uri, ARK::API::TWO::Paths::Blocks::base);
        strcat(uri, "?limit=10&page=1");
    #endif
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Blocks::blocks(
        const int limit,
        const int page
) {
    char uri[256] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Blocks::base);
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

std::string ARK::API::TWO::Blocks::blockTransactions(
        const char *const blockId
) {
    char uri[256] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Blocks::base);
        strcat(uri, "/");
        strcat(uri, blockId);
        strcat(uri, "/transactions");
    return netConnector.callback(uri);
}
