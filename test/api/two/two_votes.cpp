

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

#ifdef HAS_TWO_API

/* test_two_vote
 * https://dexplorer.ark.io:8443/api/v2/votes/d202acbfa947acac53ada2ac8a0eb662c9f75421ede3b10a42759352968b4ed2
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
TEST(api, test_two_vote)
{
    Ark::Client arkClient(DEVNET);

    const auto vote = arkClient.vote("d202acbfa947acac53ada2ac8a0eb662c9f75421ede3b10a42759352968b4ed2");

    DynamicJsonBuffer jsonBuffer(vote.size());
    JsonObject& root = jsonBuffer.parseObject(vote);

    JsonObject& data = root["data"];

    const char* id = data["id"];
    ASSERT_STREQ("d202acbfa947acac53ada2ac8a0eb662c9f75421ede3b10a42759352968b4ed2", id);

    const char* blockId = data["blockId"];
    ASSERT_STREQ("8320994199422256846", blockId);

    int type = data["type"];
    ASSERT_EQ(3, type);

    const auto amount = data["amount"].as<unsigned long>();
    ASSERT_STREQ("0", toString(amount).c_str());

    const auto fee = data["fee"].as<unsigned long>();
    ASSERT_STREQ("100000000", toString(fee).c_str());

    const char* sender = data["sender"];
    ASSERT_STREQ("DP8CKM9bSb2crRZyaxLxjaK1mdrtuDuGJr", sender);

    const char* recipient = data["recipient"];
    ASSERT_STREQ("DP8CKM9bSb2crRZyaxLxjaK1mdrtuDuGJr", recipient);

    const char* signature = data["signature"];
    ASSERT_STREQ("304402202fda01999d02d2d099a5e5e199cc6a24ca32b1e644ec855d1b9004b5068b45450220653c65a9bf48742104671e69a597b86517160f6ff87a92b89b62c290b312493c", signature);


    int confirmations = data["confirmations"];
    ASSERT_TRUE(confirmations > 0);

    JsonObject& timestamp = data["timestamp"];

    int epoch = timestamp["epoch"];
    ASSERT_EQ(45024867, epoch);

    int timestampUnix = timestamp["unix"];
    ASSERT_EQ(1535126067, timestampUnix);

    const char* human = timestamp["human"];
    ASSERT_STREQ("2018-08-24T15:54:27Z", human);
}

/* test_two_votes
 * https://dexplorer.ark.io:8443/api/v2/votes?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/votes?limit=5&page=1",
        "first": "/api/v2/votes?limit=5&page=1",
        "last": "/api/v2/votes?limit=5&page=1"
    },
    "data": [
        {
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
            "+string"
            ]
        },
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
TEST(api, test_two_votes)
{
    Ark::Client arkClient(DEVNET);

    const auto transactionUnconfirmed = arkClient.votes(5, 1);

    DynamicJsonBuffer jsonBuffer(transactionUnconfirmed.size());
    JsonObject& root = jsonBuffer.parseObject(transactionUnconfirmed);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);


    JsonObject& dataZero = root["data"][0];

    int type = dataZero["type"];
    ASSERT_EQ(3, type);

    const auto fee = dataZero["fee"].as<unsigned long>();
    ASSERT_STREQ("100000000", toString(fee).c_str());

    int confirmations = dataZero["confirmations"];
    ASSERT_NE(0, confirmations);
}

#endif
