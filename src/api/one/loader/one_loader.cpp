

#include "api/one/loader/one_loader.h"

/*************************************************
 * /api/loader/autoconfigure
 *************************************************/
std::string Ark::API::ONE::Loader::loaderAutoconfigure()
{
    return netConnector.callback(Ark::API::ONE::Paths::Loader::autoconfigure_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/loader/status
 *************************************************/
std::string Ark::API::ONE::Loader::loaderStatus()
{
    return netConnector.callback(Ark::API::ONE::Paths::Loader::status_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/loader/status/sync
 *************************************************/
std::string Ark::API::ONE::Loader::loaderSync()
{
    return netConnector.callback(Ark::API::ONE::Paths::Loader::sync_s);
}
/*************************************************/
