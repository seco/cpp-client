

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
        int limit,
        int page
) {
    char uri[120] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Votes::base);
        strcat(uri, "?limit=");
        std::stringstream limitStream;
        limitStream << limit;
        strcat(uri, limitStream.str().c_str());
        strcat(uri, "&page=");
        std::stringstream pageStream;
        pageStream << page;
        strcat(uri, pageStream.str().c_str());
    return netConnector.callback(uri);
}
