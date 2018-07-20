

#include "api/two/delegates/two_delegates.h"

std::string ARK::API::TWO::Delegates::delegate(const char *const identifier)
{
    char uri[120 + 1] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Delegates::base);
        strcat(uri, "/");
        strcat(uri, identifier);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Delegates::delegates(
        unsigned int limit,
        unsigned int page
)
{
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[120 + 1] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Delegates::base);
        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Delegates::delegateBlocks(
        const char *const identifier,
        unsigned int limit,
        unsigned int page
) {
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[120 + 1] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Delegates::base);
        strcat(uri, identifier);
        strcat(uri, "/blocks");
        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Delegates::delegateVoters(
        const char *const identifier,
        const unsigned int limit,
        const unsigned int page
) {
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[120 + 1] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Delegates::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/voters");

        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}
