

#include "api/two/delegates/two_delegates.h"

std::string Ark::API::TWO::Delegates::delegate(const char *const identifier)
{
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Delegates::base);
        strcat(uri, "/");
        strcat(uri, identifier);
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Delegates::delegates(
        int limit,
        int page
)
{
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Delegates::base);
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Delegates::delegateBlocks(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Delegates::base);
        strcat(uri, identifier);
        strcat(uri, "/blocks");
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Delegates::delegateVoters(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Delegates::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/voters");
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}
