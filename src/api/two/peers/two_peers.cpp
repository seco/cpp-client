

#include "api/two/peers/two_peers.h"

std::string ARK::API::TWO::Peers::peer(const char *const ip)
{
    char uri[96] = { '\0' };
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
    char uri[128] = { '\0' };
        strcpy(uri, ARK::API::TWO::Paths::Peers::base);
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