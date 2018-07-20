

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
        unsigned int limit,
        unsigned int page
)
{
    char parameters[2][1];
        sprintf(parameters[0], "%d", limit);
        sprintf(parameters[1], "%d", page);
    char uri[120 + 1] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Peers::base);
        strcat(uri, "?limit=");
        strcat(uri, parameters[0]);
        strcat(uri, "&page=");
        strcat(uri, parameters[1]);
    return netConnector.callback(uri);
}