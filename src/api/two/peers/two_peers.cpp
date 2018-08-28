

#include "api/two/peers/two_peers.h"

std::string Ark::API::TWO::Peers::peer(const char *const ip)
{
    char uri[96] = { '\0' };
	    strcpy(uri, Ark::API::TWO::Paths::Peers::base);
        strcat(uri, "/");
        strcat(uri, ip);
    return connection.callback(uri);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Peers::peers(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::API::TWO::Paths::Peers::base);
        strcat(uri, "?limit=");
        std::strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        std::strcat(uri, toString(page).c_str());
    return connection.callback(uri);
}
