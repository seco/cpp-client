

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
        std::strcat(uri, convert_to_string(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, convert_to_string(page).c_str());
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
        std::strcat(uri, convert_to_string(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, convert_to_string(page).c_str());
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
        std::strcat(uri, convert_to_string(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, convert_to_string(page).c_str());
    return netConnector.callback(uri);
}
