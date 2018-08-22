

#include "api/one/accounts/one_accounts.h"

/*************************************************
 * /api/accounts/getBalance?address=arkAddress
 *************************************************/
std::string Ark::API::ONE::Accounts::accountBalance(
    const char *const arkAddress)
{
    char uri[68 + 1] = {'\0'};
    strcpy(uri, Ark::API::ONE::Paths::Accounts::getBalance_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress);
    return connection.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * api/accounts/getPublickey?address=arkAddress
 *************************************************/
std::string Ark::API::ONE::Accounts::accountPublickey(
    const char *const arkAddress)
{
    char uri[94 + 1] = {'\0'};
    strcpy(uri, Ark::API::ONE::Paths::Accounts::getPublickey_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress);
    return connection.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/accounts/delegates/fee?address=arkAddress
 *************************************************/
std::string Ark::API::ONE::Accounts::accountDelegatesFee(
    const char *const arkAddress)
{
    char uri[95 + 1] = {'\0'};
    strcpy(uri, Ark::API::ONE::Paths::Accounts::delegatesFee_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress);
    return connection.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/accounts/delegates?address=arkAddress
 *************************************************/
std::string Ark::API::ONE::Accounts::accountDelegates(
    const char *const arkAddress)
{
    char uri[91 + 1] = {'\0'};
    strcpy(uri, Ark::API::ONE::Paths::Accounts::delegates_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress);
    return connection.callback(uri);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/accounts?address=arkAddress
 *************************************************/
std::string Ark::API::ONE::Accounts::account(
    const char *const arkAddress)
{
    char uri[81 + 1] = {'\0'};
    strcpy(uri, Ark::API::ONE::Paths::Accounts::accounts_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress);
    return connection.callback(uri);
};
/*************************************************/
