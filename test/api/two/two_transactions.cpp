

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

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

    DynamicJsonBuffer jsonBuffer(transaction.size());
    JsonObject& root = jsonBuffer.parseObject(transaction);

    JsonObject& data = root["data"];

    const char* id = data["id"];
    ASSERT_STREQ("b324cea5c5a6c15e6ced3ec9c3135a8022eeadb8169f7ba66c80ebc82b0ac850", id);

    const char* blockId = data["blockId"];
    ASSERT_STREQ("4375573732170746923", blockId);

    int type = data["type"];
    ASSERT_EQ(3, type);

    const auto amount = data["amount"].as<unsigned long>();
    ASSERT_STREQ("0", toString(amount).c_str());

    const auto fee = data["fee"].as<unsigned long>();
    ASSERT_STREQ("100000000", toString(fee).c_str());

    const char* sender = data["sender"];
    ASSERT_STREQ("DKcFDN6mhLAheRAfmN6LT1e4AeyF1Fd9bY", sender);

    const char* recipient = data["recipient"];
    ASSERT_STREQ("DKcFDN6mhLAheRAfmN6LT1e4AeyF1Fd9bY", recipient);

    const char* signature = data["signature"];
    ASSERT_STREQ("3045022100dc27398f4f3a24e55dc1ee87900de988254daa3fed71e82f4d6ef85ed4f9d9f8022025d71158cc15672863b2263622026ec19fa9cc9d2e8c78fa79eb2d8f4ef45fc7", signature);

    int confirmations = data["confirmations"];
    ASSERT_TRUE(confirmations > 0);


    JsonObject& timestamp = data["timestamp"];

    int epoch = timestamp["epoch"];
    ASSERT_EQ(45024866, epoch);

    int timestampUnix = timestamp["unix"];
    ASSERT_EQ(1535126066, timestampUnix);

    const char* human = timestamp["human"];
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

    DynamicJsonBuffer jsonBuffer(types.size());
    JsonObject& root = jsonBuffer.parseObject(types);

    JsonObject& data = root["data"];

    int TRANSFER = data["TRANSFER"];
    ASSERT_EQ(0, TRANSFER);

    int SECOND_SIGNATURE = data["SECOND_SIGNATURE"];
    ASSERT_EQ(1, SECOND_SIGNATURE);

    int DELEGATE_REGISTRATION = data["DELEGATE_REGISTRATION"];
    ASSERT_EQ(2, DELEGATE_REGISTRATION);

    int VOTE = data["VOTE"];
    ASSERT_EQ(3, VOTE);

    int MULTI_SIGNATURE = data["MULTI_SIGNATURE"];
    ASSERT_EQ(4, MULTI_SIGNATURE);

    int IPFS = data["IPFS"];
    ASSERT_EQ(5, IPFS);

    int TIMELOCK_TRANSFER = data["TIMELOCK_TRANSFER"];
    ASSERT_EQ(6, TIMELOCK_TRANSFER);

    int MULTI_PAYMENT = data["MULTI_PAYMENT"];
    ASSERT_EQ(7, MULTI_PAYMENT);

    int DELEGATE_RESIGNATION = data["DELEGATE_RESIGNATION"];
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

    DynamicJsonBuffer jsonBuffer(transactionUnconfirmed.size());
    JsonObject& root = jsonBuffer.parseObject(transactionUnconfirmed);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);
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

    DynamicJsonBuffer jsonBuffer(transactions.size());
    JsonObject& root = jsonBuffer.parseObject(transactions);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);


    JsonObject& dataZero = root["data"][0];

    int type = dataZero["type"];
    ASSERT_EQ(0, type);

    const auto fee = dataZero["fee"].as<unsigned long>();
    ASSERT_STRNE("", toString(fee).c_str());
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

    DynamicJsonBuffer jsonBuffer(transactionsUnconfirmed.size());
    JsonObject& root = jsonBuffer.parseObject(transactionsUnconfirmed);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_TRUE(count >= 0);

    int pageCount = meta["pageCount"];
    ASSERT_TRUE(pageCount >= 0);

    int totalCount = meta["totalCount"];
    ASSERT_TRUE(totalCount >= 0);
}

/* test_two_transactions_transactions_search
 * 
 * Expected Response:
 */
TEST(api, test_two_transactions_search)
{
    Ark::Client arkClient(DEVNET);

    const auto transactions = arkClient.transactions("4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48", 5, 1);

    // DynamicJsonBuffer jsonBuffer(transactions.size());
    // JsonObject& root = jsonBuffer.parseObject(transactions);
}

#endif
