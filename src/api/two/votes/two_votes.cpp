

#include "api/two/votes/two_votes.h"

std::string Ark::API::TWO::Votes::vote(const char *const identifier)
{
    char uri[96] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Votes::base);
        strcat(uri, "/");
        strcat(uri, identifier);
    return connection.callback(uri);
}

/***/

std::string Ark::API::TWO::Votes::votes(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Votes::base);
        strcat(uri, "?limit=");
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}
