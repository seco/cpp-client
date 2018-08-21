

#include "api/two/delegates/two_delegates.h"

std::string ARK::API::TWO::Delegates::delegate(const char *const identifier)
{
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Delegates::base);
        strcat(uri, "/");
        strcat(uri, identifier);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Delegates::delegates(
        int limit,
        int page
)
{
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Delegates::base);
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

std::string ARK::API::TWO::Delegates::delegateBlocks(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Delegates::base);
        strcat(uri, identifier);
        strcat(uri, "/blocks");
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

std::string ARK::API::TWO::Delegates::delegateVoters(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Delegates::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/voters");
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
