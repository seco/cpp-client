

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_TWO_API

/* test_two_delegates_delegate
 * https://dexplorer.ark.io:8443/api/v2/delegates/boldninja
 * Expected Response:
    {
        "data": {
            "username": "string",
            "address": "string",
            "publicKey": "string",
            "votes": unsigned long,
            "rank": ing,
            "blocks": {
                "produced": int,
                "missed": int,
                "last": {
                    "id": "string",
                    "timestamp": {
                        "epoch": int,
                        "unix": int,
                        "human": "string"
                    }
                }
            },
            "production": {
                "approval": double,
                "productivity": double
            }
        }
    }
 */
TEST(api, test_two_delegate)
{
    Ark::Client arkClient(DEVNET);

    const auto delegateResponse = arkClient.delegate("boldninja");
    auto parser = Ark::Test::Utils::JSONParser(delegateResponse);

    const auto username = parser->getRoot()["data"]["username"].as<const char*>();
    ASSERT_STREQ("boldninja", username);

    const auto address = parser->getRoot()["data"]["address"].as<const char*>();
    ASSERT_STREQ("DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu", address);

    const auto publicKey = parser->getRoot()["data"]["publicKey"].as<const char*>();
    ASSERT_STREQ("023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359", publicKey);

    const auto votes = parser->getRoot()["data"]["votes"].as<unsigned long long>();
    ASSERT_STRNE("0", toString(votes).c_str());

    const auto rank = parser->getRoot()["data"]["rank"].as<int>();
    ASSERT_STRNE("0", toString(rank).c_str());

    const auto produced = parser->getRoot()["data"]["blocks"]["produced"].as<int>();
    ASSERT_STRNE("0", toString(produced).c_str());

    const auto missed = parser->getRoot()["data"]["blocks"]["missed"].as<int>();
    ASSERT_STRNE("", toString(missed).c_str());

    const auto approval = parser->getRoot()["data"]["production"]["approval"].as<double>();
    ASSERT_STRNE("100.00", toString(approval).c_str());

    const auto productivity = parser->getRoot()["data"]["production"]["productivity"].as<double>();
    ASSERT_STRNE("", toString(productivity).c_str());
}

/* test_two_delegates_delegate_blocks
 * https://dexplorer.ark.io:8443/api/v2/delegates/boldninja/blocks?limit=3&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/delegates/boldninja/blocks?limit=3&page=1",
        "first": "/api/v2/delegates/boldninja/blocks?limit=3&page=1",
        "last": "/api/v2/delegates/boldninja/blocks?limit=3&page=1"
    },
    "data": [
        {
        "id": "string",
        "version": int,
        "height": unsigned long,
        "previous": "string",
        "forged": {
            "reward": unsigned long,
            "fee": unsigned long,
            "total": unsigned long
        },
        "payload": {
            "hash": "string",
            "length": int
        },
        "generator": {
            "username": "string",
            "address": "string",
            "publicKey": "string"
        },
        "signature": "string",
        "transactions": int,
        "timestamp": {
            "epoch": int,
            "unix": int,
            "human": "string"
        }
        }
    ]
    }
 */
TEST(api, test_two_delegate_blocks)
{
    Ark::Client arkClient(DEVNET);

    const auto delegateBlocksResponse = arkClient.delegateBlocks("boldninja", 3, 1);

    auto parser = Ark::Test::Utils::JSONParser(delegateBlocksResponse);

    const auto id = parser->getRoot()["data"][0]["id"].as<const char*>();
    ASSERT_STRNE("", id);

    const auto version = parser->getRoot()["data"][0]["version"].as<int>();
    ASSERT_STRNE("", toString(version).c_str());

    const auto height = parser->getRoot()["data"][0]["height"].as<unsigned long long>();
    ASSERT_STRNE("0", toString(height).c_str());

    const auto previous = parser->getRoot()["data"][0]["previous"].as<const char*>();
    ASSERT_STRNE("0", previous);

    const auto username = parser->getRoot()["data"][0]["generator"]["username"].as<const char*>();
    ASSERT_STREQ("boldninja", username);

    const auto address = parser->getRoot()["data"][0]["generator"]["address"].as<const char*>();
    ASSERT_STREQ("DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu", address);

    const auto publicKey = parser->getRoot()["data"][0]["generator"]["publicKey"].as<const char*>();
    ASSERT_STREQ("023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359", publicKey);
}

/* test_two_delegates_delegate_voters
 * https://dexplorer.ark.io:8443/api/v2/delegates/boldninja/voters?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/delegates/boldninja/voters?limit=5&page=1",
        "first": "/api/v2/delegates/boldninja/voters?limit=5&page=1",
        "last": "/api/v2/delegates/boldninja/voters?limit=5&page=1"
    },
    "data": [
        {
        "address": "string",
        "publicKey": "string",
        "secondPublicKey": "string",
        "balance": unsigned long,
        "isDelegate": bool
        }
    ]
    }
 */
TEST(api, test_two_delegate_voters)
{
    Ark::Client arkClient(DEVNET);

    const auto delegateVotersResponse = arkClient.delegateVoters("boldninja", 5, 1);

    auto parser = Ark::Test::Utils::JSONParser(delegateVotersResponse);

    const auto address = parser->getRoot()["data"][0]["address"].as<const char*>();
    ASSERT_STREQ("DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu", address);

    const auto publicKey = parser->getRoot()["data"][0]["publicKey"].as<const char*>();
    ASSERT_STREQ("023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359", publicKey);

    const auto isDelegate = parser->getRoot()["data"][0]["isDelegate"].as<bool>();
    ASSERT_EQ(1, isDelegate);

}

/* test_two_delegates_delegates
 * https://dexplorer.ark.io:8443/api/v2/delegates?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "/api/v2/delegates?limit=5&page=2",
        "previous": null,
        "self": "/api/v2/delegates?limit=5&page=1",
        "first": "/api/v2/delegates?limit=5&page=1",
        "last": "/api/v2/delegates?limit=5&page=23"
    },
    "data": [
        {
        "username": "string",
        "address": "string",
        "publicKey": "string",
        "votes": unsigned long,
        "rank": int,
        "blocks": {
            "produced": int,
            "missed": int,
            "last": {
                "id": "string",
                "timestamp": {
                    "epoch": int,
                    "unix": int,
                    "human": "string"
                }
            }
        },
        "production": {
            "approval": double,
            "productivity": double
        }
        }
    ]
    }
 */
TEST(api, test_two_delegates)
{
    Ark::Client arkClient(DEVNET);

    const auto delegates = arkClient.delegates(5, 1);

    auto parser = Ark::Test::Utils::JSONParser(delegates);

    const auto votes = parser->getRoot()["data"][0]["votes"].as<unsigned long long>();
    ASSERT_STRNE("0", toString(votes).c_str());
}

#endif
