

#include "api/two/votes/two_votes.h"

std::string ARK::API::TWO::Votes::vote(const char *const identifier)
{
    char uri[80] = { '\0' };
	    strcpy(uri, ARK::API::TWO::Paths::Votes::base);
        strcat(uri, "/");
        strcat(uri, identifier);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Votes::votes(
        const unsigned int limit,
        const unsigned int page
) {
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[120] = { '\0' };
	    strcpy(uri, ARK::API::TWO::Paths::Votes::base);
        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}
