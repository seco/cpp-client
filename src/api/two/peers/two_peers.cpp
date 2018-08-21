

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
        std::strcat(uri, convert_to_string(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, convert_to_string(page).c_str());
    return netConnector.callback(uri);
}