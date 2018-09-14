

#include "api/one/peers/one_peers.h"

/**
 * /api/peers/get?ip=167.114.29.55&port=4002
 **/
std::string Ark::API::ONE::Peers::peer(
    const char *const ip,
    const int port)
{
    char uri[68 + 1] = {'\0'};
    strcpy(uri, Ark::API::ONE::Paths::Peers::get_s);
    strcat(uri, "?ip=");
    strcat(uri, ip);
    strcat(uri, "&port=");
    strcat(uri, toString(port).c_str());
    return connection.callback(uri);
};
/**/

/***/

/**
 * /api/peers?limit=20
 **/
std::string Ark::API::ONE::Peers::peers()
{
    char uri[39 + 1] = {'\0'};
    strcpy(uri, Ark::API::ONE::Paths::Peers::peers_s);
    return connection.callback(uri);
};
/**/

/***/

/**
 * /api/peers/version
 **/
std::string Ark::API::ONE::Peers::peerVersion()
{
    return connection.callback(Ark::API::ONE::Paths::Peers::version_s);
};
/**/
