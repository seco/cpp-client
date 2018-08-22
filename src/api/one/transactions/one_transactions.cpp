

#include "api/one/transactions/one_transactions.h"

/*************************************************
 * /api/transactions/get?id=
 *************************************************/
std::string Ark::API::ONE::Transactions::transaction(const char *const id)
{
    char uri[114 + 1] = {'\0'};
    strcpy(uri, Ark::API::ONE::Paths::Transactions::getSingle_s);
    strcat(uri, "?id=");
    strcat(uri, id);
    return netConnector.callback(uri);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/transactions/?orderBy=timestamp:desc&limit=10"
 *************************************************/
std::string Ark::API::ONE::Transactions::transactions()
{
    return netConnector.callback(Ark::API::ONE::Paths::Transactions::transactions_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/transactions/unconfirmed/get?id=
 *************************************************/
std::string Ark::API::ONE::Transactions::transactionUnconfirmed(const char *const id)
{
    char uri[126 + 1] = {'\0'};
    strcpy(uri, Ark::API::ONE::Paths::Transactions::getSingleUnconfirmed_s);
    strcat(uri, "?id=");
    strcat(uri, id);
    return netConnector.callback(uri);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/transactions/unconfirmed
 *************************************************/
std::string Ark::API::ONE::Transactions::transactionsUnconfirmed()
{
    return netConnector.callback(Ark::API::ONE::Paths::Transactions::unconfirmed_s);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
 * /api/transactions/get?id=
 *************************************************/
std::string Ark::API::ONE::Transactions::getVendorField(const char *const txID)
{
    char uri[114 + 1] = {'\0'};
    strcpy(uri, Ark::API::ONE::Paths::Transactions::getSingle_s);
    strcat(uri, "?id=");
    strcat(uri, txID);
    return netConnector.callback(uri);
}
/*************************************************/
