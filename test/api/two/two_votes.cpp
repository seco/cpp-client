

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

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

    auto parser = Ark::Test::Utils::JSONParser(vote);

    const auto id = parser->getRoot()["data"]["id"].as<const char*>();
    ASSERT_STREQ("d202acbfa947acac53ada2ac8a0eb662c9f75421ede3b10a42759352968b4ed2", id);

    const auto blockId = parser->getRoot()["data"]["blockId"].as<const char*>();
    ASSERT_STREQ("8320994199422256846", blockId);

    const auto type = parser->getRoot()["data"]["type"].as<int>();
    ASSERT_EQ(3, type);

    const auto amount = parser->getRoot()["data"]["amount"].as<unsigned long long>();
    ASSERT_STREQ("0", toString(amount).c_str());

    const auto fee = parser->getRoot()["data"]["fee"].as<unsigned long long>();
    ASSERT_STREQ("100000000", toString(fee).c_str());

    const auto sender = parser->getRoot()["data"]["sender"].as<const char*>();
    ASSERT_STREQ("DP8CKM9bSb2crRZyaxLxjaK1mdrtuDuGJr", sender);

    const auto recipient = parser->getRoot()["data"]["recipient"].as<const char*>();
    ASSERT_STREQ("DP8CKM9bSb2crRZyaxLxjaK1mdrtuDuGJr", recipient);

    const auto signature = parser->getRoot()["data"]["signature"].as<const char*>();
    ASSERT_STREQ("304402202fda01999d02d2d099a5e5e199cc6a24ca32b1e644ec855d1b9004b5068b45450220653c65a9bf48742104671e69a597b86517160f6ff87a92b89b62c290b312493c", signature);

    const auto confirmations = parser->getRoot()["data"]["confirmations"].as<int>();
    ASSERT_NE(0, confirmations);

    const auto epoch = parser->getRoot()["data"]["timestamp"]["epoch"].as<int>();
    ASSERT_EQ(45024867, epoch);

    const auto timestampUnix = parser->getRoot()["data"]["timestamp"]["unix"].as<int>();
    ASSERT_EQ(1535126067, timestampUnix);

    const auto human = parser->getRoot()["data"]["timestamp"]["human"].as<const char*>();
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

    auto parser = Ark::Test::Utils::JSONParser(transactionUnconfirmed);

    const auto count = parser->getRoot()["meta"]["count"].as<int>();
    ASSERT_EQ(5, count);

    const auto pageCount = parser->getRoot()["meta"]["pageCount"].as<int>();
    ASSERT_EQ(1, pageCount);

    const auto totalCount = parser->getRoot()["meta"]["totalCount"].as<int>();
    ASSERT_EQ(5, totalCount);

    const auto type = parser->getRoot()["data"][0]["type"].as<int>();
    ASSERT_EQ(3, type);

    const auto fee = parser->getRoot()["data"][0]["fee"].as<unsigned long long>();
    ASSERT_STREQ("100000000", toString(fee).c_str());

    const auto confirmations = parser->getRoot()["data"][0]["confirmations"].as<int>();
    ASSERT_NE(0, confirmations);
}

#endif
