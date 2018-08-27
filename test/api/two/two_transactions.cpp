

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_TWO_API

/* test_two_transactions_transaction
 * https://dexplorer.ark.io:8443/api/v2/transactions/b324cea5c5a6c15e6ced3ec9c3135a8022eeadb8169f7ba66c80ebc82b0ac850
 * Expected Response:
    {
    "data": {
        "id": "string",
        "blockId": "string",
        "type": int,
        "amount": unsigned long,
        "fee": unsigned long,
        "sender": "string",
        "recipient": "string",
        "signature": "string",
        "asset": {
            "votes": [
                "string"
            ]
        },
        "confirmations": int,
        "timestamp": {
            "epoch": int,
            "unix": int,
            "human": "string"
        }
    }
    }
 */
TEST(api, test_two_transaction)
{
    Ark::Client arkClient(DEVNET);

    const auto transaction = arkClient.transaction("b324cea5c5a6c15e6ced3ec9c3135a8022eeadb8169f7ba66c80ebc82b0ac850");

    auto parser = Ark::Test::Utils::JSONParser(transaction);

    const auto id = parser->getRoot()["data"]["id"].as<const char*>();
    ASSERT_STREQ("b324cea5c5a6c15e6ced3ec9c3135a8022eeadb8169f7ba66c80ebc82b0ac850", id);

    const auto blockId = parser->getRoot()["data"]["blockId"].as<const char*>();
    ASSERT_STREQ("4375573732170746923", blockId);

    const auto type = parser->getRoot()["data"]["type"].as<int>();
    ASSERT_EQ(3, type);

    const auto amount = parser->getRoot()["data"]["amount"].as<unsigned long long>();
    ASSERT_STREQ("0", toString(amount).c_str());

    const auto fee = parser->getRoot()["data"]["fee"].as<unsigned long long>();
    ASSERT_STREQ("100000000", toString(fee).c_str());

    const auto sender = parser->getRoot()["data"]["sender"].as<const char*>();
    ASSERT_STREQ("DKcFDN6mhLAheRAfmN6LT1e4AeyF1Fd9bY", sender);

    const auto recipient = parser->getRoot()["data"]["recipient"].as<const char*>();
    ASSERT_STREQ("DKcFDN6mhLAheRAfmN6LT1e4AeyF1Fd9bY", recipient);

    const auto signature = parser->getRoot()["data"]["signature"].as<const char*>();
    ASSERT_STREQ("3045022100dc27398f4f3a24e55dc1ee87900de988254daa3fed71e82f4d6ef85ed4f9d9f8022025d71158cc15672863b2263622026ec19fa9cc9d2e8c78fa79eb2d8f4ef45fc7", signature);

    const auto confirmations = parser->getRoot()["data"]["confirmations"].as<int>();
    ASSERT_NE(0, confirmations);

    const auto epoch = parser->getRoot()["data"]["timestamp"]["epoch"].as<int>();
    ASSERT_EQ(45024866, epoch);

    const auto timestampUnix = parser->getRoot()["data"]["timestamp"]["unix"].as<int>();
    ASSERT_EQ(1535126066, timestampUnix);

    const auto human = parser->getRoot()["data"]["timestamp"]["human"].as<const char*>();
    ASSERT_STREQ("2018-08-24T15:54:26Z", human);
}

/* test_two_transactions_transaction_types
 * https://dexplorer.ark.io:8443/api/v2/transactions/types
 * Expected Response:
    {
        "data": {
            "TRANSFER": 0,
            "SECOND_SIGNATURE": 1,
            "DELEGATE_REGISTRATION": 2,
            "VOTE": 3,
            "MULTI_SIGNATURE": 4,
            "IPFS": 5,
            "TIMELOCK_TRANSFER": 6,
            "MULTI_PAYMENT": 7,
            "DELEGATE_RESIGNATION": 8
        }
    }
 */
TEST(api, test_two_transaction_types)
{
    Ark::Client arkClient(DEVNET);

    const auto types = arkClient.transactionTypes();
    auto parser = Ark::Test::Utils::JSONParser(types);

    const auto TRANSFER = parser->getRoot()["data"]["TRANSFER"].as<int>();
    ASSERT_EQ(0, TRANSFER);

    const auto SECOND_SIGNATURE = parser->getRoot()["data"]["SECOND_SIGNATURE"].as<int>();
    ASSERT_EQ(1, SECOND_SIGNATURE);

    const auto DELEGATE_REGISTRATION = parser->getRoot()["data"]["DELEGATE_REGISTRATION"].as<int>();
    ASSERT_EQ(2, DELEGATE_REGISTRATION);

    const auto VOTE = parser->getRoot()["data"]["VOTE"].as<int>();
    ASSERT_EQ(3, VOTE);

    const auto MULTI_SIGNATURE = parser->getRoot()["data"]["MULTI_SIGNATURE"].as<int>();
    ASSERT_EQ(4, MULTI_SIGNATURE);

    const auto IPFS = parser->getRoot()["data"]["IPFS"].as<int>();
    ASSERT_EQ(5, IPFS);

    const auto TIMELOCK_TRANSFER = parser->getRoot()["data"]["TIMELOCK_TRANSFER"].as<int>();
    ASSERT_EQ(6, TIMELOCK_TRANSFER);

    const auto MULTI_PAYMENT = parser->getRoot()["data"]["MULTI_PAYMENT"].as<int>();
    ASSERT_EQ(7, MULTI_PAYMENT);

    const auto DELEGATE_RESIGNATION = parser->getRoot()["data"]["DELEGATE_RESIGNATION"].as<int>();
    ASSERT_EQ(8, DELEGATE_RESIGNATION);
}

/* test_two_transactions_transaction_unconfirmed
 * https://dexplorer.ark.io:8443/api/v2/transactions/unconfirmed?id=4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48
 * Expected Response (if unconfirmed tx is not found):
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/transactions/unconfirmed?id=4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48&page=1&limit=100",
        "first": "/api/v2/transactions/unconfirmed?id=4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48&page=1&limit=100",
        "last": null
    },
    "data": [
        
    ]
    }
 */
TEST(api, test_two_transaction_unconfirmed)
{
    Ark::Client arkClient(DEVNET);

    const auto transactionUnconfirmed = arkClient.transactionUnconfirmed("4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48");

    auto parser = Ark::Test::Utils::JSONParser(transactionUnconfirmed);

    const auto count = parser->getRoot()["meta"]["count"].as<int>();
    ASSERT_EQ(0, count);

    const auto pageCount = parser->getRoot()["meta"]["pageCount"].as<int>();
    ASSERT_EQ(0, pageCount);

    const auto totalCount = parser->getRoot()["meta"]["totalCount"].as<int>();
    ASSERT_EQ(0, totalCount);
}

/* test_two_transactions_transactions
 * https://dexplorer.ark.io:8443/api/v2/transactions?limit=2&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/transactions?limit=2&page=1",
        "first": "/api/v2/transactions?limit=2&page=1",
        "last": "/api/v2/transactions?limit=2&page=1"
    },
    "data": [
        {
        "id": "string",
        "blockId": "string",
        "type": ing,
        "amount": unsigned long,
        "fee": unsigned long,
        "sender": "string",
        "recipient": "string",
        "signature": "string",
        "vendorField": "string",
        "confirmations": int,
        "timestamp": {
            "epoch": int,
            "unix": int,
            "human": "string"
        }
        }
    ]
    }
 */
TEST(api, test_two_transactions)
{
    Ark::Client arkClient(DEVNET);

    const auto transactions = arkClient.transactions(2, 1);

    auto parser = Ark::Test::Utils::JSONParser(transactions);

    const auto count = parser->getRoot()["meta"]["count"].as<int>();
    ASSERT_EQ(2, count);

    const auto pageCount = parser->getRoot()["meta"]["pageCount"].as<int>();
    ASSERT_EQ(1, pageCount);

    const auto totalCount = parser->getRoot()["meta"]["totalCount"].as<int>();
    ASSERT_EQ(2, totalCount);

    if (count > 0)
    {
        const auto type = parser->getRoot()["data"][0]["type"].as<int>();
        ASSERT_STRNE("", toString(type).c_str());

        const auto fee = parser->getRoot()["data"][0]["fee"].as<unsigned long long>();
        ASSERT_STRNE("", toString(fee).c_str());

        const auto confirmations = parser->getRoot()["data"][0]["confirmations"].as<int>();
        ASSERT_STRNE("", toString(confirmations).c_str());
    }

}

/* test_two_transactions_transactions_unconfirmed
 * https://dexplorer.ark.io:8443/api/v2/transactions/unconfirmed?limit=2&page=1
 * Expected Response (if unconfirmed tx is not found):
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/transactions/unconfirmed?limit=2&page=1",
        "first": "/api/v2/transactions/unconfirmed?limit=2&page=1",
        "last": "string"
    },
    "data": [
        
    ]
    }
 */
TEST(api, test_two_transactions_unconfirmed)
{
    Ark::Client arkClient(DEVNET);

    const auto transactionsUnconfirmed = arkClient.transactionsUnconfirmed(5, 1);
    auto parser = Ark::Test::Utils::JSONParser(transactionsUnconfirmed);

    const auto count = parser->getRoot()["meta"]["count"].as<int>();
    ASSERT_EQ(0, count);

    const auto pageCount = parser->getRoot()["meta"]["pageCount"].as<int>();
    ASSERT_EQ(0, pageCount);

    const auto totalCount = parser->getRoot()["meta"]["totalCount"].as<int>();
    ASSERT_EQ(0, totalCount);
}

/* test_two_transactions_transactions_search
 * 
 * Expected Response:
    ??????????
 */
TEST(api, test_two_transactions_search)
{
    Ark::Client arkClient(DEVNET);

    const auto transactions = arkClient.transactions("4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48", 5, 1);

    auto parser = Ark::Test::Utils::JSONParser(transactions);
}

#endif
