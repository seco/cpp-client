

#include "api/two/peers/two_peers.h"

std::string ARK::API::TWO::Peers::peer(const char *const ip)
{
    char uri[80] = { '\0' };
	    strcpy(uri, ARK::API::TWO::Paths::Peers::base);
        strcat(uri, "/");
        strcat(uri, ip);
    return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Peers::peers(
        int limit,
        int page
) {
    char uri[120 + 1] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Peers::base);
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