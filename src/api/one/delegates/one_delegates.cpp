

#include "api/one/delegates/one_delegates.h"

/*************************************************
 * /api/delegates/get?username="username"
 * /api/delegates/get?publicKey=publicKey
 *************************************************/
std::string Ark::API::ONE::Delegates::delegate(
    const char *const parameter)
{
    char uri[120 + 1] = {'\0'}; //max size (pubkey param)
    strcpy(uri, Ark::API::ONE::Paths::Delegates::get_s);
    bool isUsername = (strlen(parameter) <= 20);
    auto key = (isUsername) ? ("?username=") : ("?publicKey=");
    strcat(uri, key);
    strcat(uri, parameter);
    return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/delegates?limit=20
 *************************************************/
std::string Ark::API::ONE::Delegates::delegates()
{
    char uri[43] = {'\0'};
    strcpy(uri, Ark::API::ONE::Paths::Delegates::delegates_s);
    return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/delegates/count
 *************************************************/
std::string Ark::API::ONE::Delegates::delegatesCount()
{
    return netConnector.callback(Ark::API::ONE::Paths::Delegates::count_s);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/delegates/search?q=sleepdeficit 
 *************************************************/
std::string Ark::API::ONE::Delegates::delegateSearch(
    const char *const username)
{
    char uri[69 + 1] = {'\0'};
    strcpy(uri, Ark::API::ONE::Paths::Delegates::search_s);
    strcat(uri, "?q=");
    strcat(uri, username);
    return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/delegates/fee
 *************************************************/
std::string Ark::API::ONE::Delegates::delegateFee()
{
    return netConnector.callback(Ark::API::ONE::Paths::Delegates::fee_s);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey
 *************************************************/
std::string Ark::API::ONE::Delegates::delegateForgedByAccount(
    const char *const generatorPublicKey)
{
    char uri[152 + 1];
    strcpy(uri, Ark::API::ONE::Paths::Delegates::getForgedByAccount_s);
    strcat(uri, "?generatorPublicKey=");
    strcat(uri, generatorPublicKey);
    return netConnector.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/delegates/getNextForgers
 *************************************************/
std::string Ark::API::ONE::Delegates::delegateNextForgers()
{
    return netConnector.callback(Ark::API::ONE::Paths::Delegates::getNextForgers_s);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/delegates/voters?publicKey=_pubKey
 *************************************************/
std::string Ark::API::ONE::Delegates::delegateVoters(
    const char *const publicKey)
{
    char uri[123 + 1] = {'\0'};
    strcpy(uri, Ark::API::ONE::Paths::Delegates::voters_s);
    strcat(uri, "?publicKey=");
    strcat(uri, publicKey);
    return netConnector.callback(uri);
};
/*************************************************/
