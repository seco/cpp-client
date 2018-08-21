

#include "api/two/votes/two_votes.h"

std::string ARK::API::TWO::Votes::vote(const char *const identifier)
{
    char uri[96] = { '\0' };
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
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Votes::base);
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
