

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_TWO_API

/* test_two_blocks_block
 * https://dexplorer.ark.io:8443/api/v2/blocks/13114381566690093367
 * Expected Response:
    {
        "data": {
            "id": "string",
            "version": ing,
            "height": unsigned long,
            "previous": "string",
            "forged": {
                "reward": int,
                "fee": int,
                "total": int
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
    }
 */
TEST(api, test_two_block)
{
    Ark::Client arkClient(DEVNET);

    const auto blockResponse = arkClient.block("13114381566690093367");
    auto parser = Ark::Test::Utils::JSONParser(blockResponse);

    const auto id = parser->getRoot()["data"]["id"].as<const char*>();
    ASSERT_STREQ("13114381566690093367", id);

    const auto version = parser->getRoot()["data"]["version"].as<int>();
    ASSERT_STREQ("0", toString(version).c_str());

    const auto height = parser->getRoot()["data"]["height"].as<unsigned long long>();
    ASSERT_STREQ("1", toString(height).c_str());

    const auto reward = parser->getRoot()["data"]["forged"]["reward"].as<unsigned long long>();
    ASSERT_STREQ("0", toString(reward).c_str());

    const auto fee = parser->getRoot()["data"]["forged"]["fee"].as<unsigned long long>();
    ASSERT_STREQ("0", toString(fee).c_str());

    const auto total = parser->getRoot()["data"]["forged"]["total"].as<unsigned long long>();
    ASSERT_STREQ("0", toString(total).c_str());

    const auto hash = parser->getRoot()["data"]["payload"]["hash"].as<const char*>();
    ASSERT_STREQ("2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867", hash);

    const auto length = parser->getRoot()["data"]["payload"]["length"].as<int>();
    ASSERT_STREQ("11395", toString(length).c_str());

    const auto address = parser->getRoot()["data"]["generator"]["address"].as<const char*>();
    ASSERT_STREQ("D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax", address);

    const auto publicKey = parser->getRoot()["data"]["generator"]["publicKey"].as<const char*>();
    ASSERT_STREQ("03d3fdad9c5b25bf8880e6b519eb3611a5c0b31adebc8455f0e096175b28321aff", publicKey);

    const auto signature = parser->getRoot()["data"]["signature"].as<const char*>();
    ASSERT_STREQ("3044022035694a9b99a9236655c658eb07fc3b02ce5edcc24b76424a7287c54ed3822b0602203621e92defb360490610f763d85e94c2db2807a4bd7756cc8a6a585463ef7bae", signature);

    const auto transactions = parser->getRoot()["data"]["transactions"].as<int>();
    ASSERT_STREQ("52", toString(transactions).c_str());

    const auto epoch = parser->getRoot()["data"]["timestamp"]["epoch"].as<int>();
    ASSERT_STREQ("0", toString(epoch).c_str());

    const auto timestampUnix = parser->getRoot()["data"]["timestamp"]["unix"].as<int>();
    ASSERT_STREQ("1490101200", toString(timestampUnix).c_str());

    const auto human = parser->getRoot()["data"]["timestamp"]["human"].as<const char*>();
    ASSERT_STREQ("2017-03-21T13:00:00Z", human);
}

/* test_two_blocks_block_transactions
 * https://dexplorer.ark.io:8443/api/v2/blocks/10241408650344629183/transactions
 * Espected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/blocks\/13114381566690093367\/transactions?page=1&limit=100",
        "first": "\/api\/v2\/blocks\/13114381566690093367\/transactions?page=1&limit=100",
        "last": "\/api\/v2\/blocks\/13114381566690093367\/transactions?page=1&limit=100"
    },
    "data": [
        {
        "id": "string",
        "blockId": "string",
        "type": unsigned long,
        "amount": unsigned long,
        "fee": unsigned long,
        "sender": "string",
        "recipient": "string",
        "signature": "string",
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
TEST(api, test_two_block_transactions)
{
    Ark::Client arkClient(DEVNET);

    const auto blockTransactionsResponse = arkClient.blockTransactions("10241408650344629183");
    auto parser = Ark::Test::Utils::JSONParser(blockTransactionsResponse);

    const auto id = parser->getRoot()["data"][0]["id"].as<int>();
    ASSERT_STRNE("", toString(id).c_str());

    const auto blockId = parser->getRoot()["data"][0]["blockId"].as<const char*>();
    ASSERT_STRNE("", blockId);

    const auto type = parser->getRoot()["data"][0]["type"].as<int>();
    ASSERT_STRNE("", toString(type).c_str());

    const auto amount = parser->getRoot()["data"][0]["amount"].as<unsigned long long>();
    ASSERT_STRNE("", toString(amount).c_str());

    const auto fee = parser->getRoot()["data"][0]["fee"].as<unsigned long long>();
    ASSERT_STRNE("", toString(fee).c_str());

    const auto sender = parser->getRoot()["data"][0]["sender"].as<const char*>();
    ASSERT_STRNE("", sender);

    const auto signature = parser->getRoot()["data"][0]["signature"].as<const char*>();
    ASSERT_STRNE("", signature);

    const auto confirmations = parser->getRoot()["data"][0]["confirmations"].as<int>();
    ASSERT_STRNE("", toString(confirmations).c_str());

    const auto epoch = parser->getRoot()["data"][0]["timestamp"]["epoch"].as<int>();
    ASSERT_STRNE("", toString(epoch).c_str());

    const auto timestampUnix = parser->getRoot()["data"][0]["timestamp"]["unix"].as<int>();
    ASSERT_STRNE("", toString(timestampUnix).c_str());

    const auto human = parser->getRoot()["data"][0]["timestamp"]["human"].as<const char*>();
    ASSERT_STRNE("", human);
}

/* test_two_blocks_blocks
 * https://dexplorer.ark.io:8443/api/v2/blocks
 * Expected Response:
    {
        "meta": {
            "count": int,
            "pageCount": int,
            "totalCount": int,
            "next": "string",
            "previous": "string",
            "self": "/api/v2/blocks?limit=10&page=1",
            "first": "/api/v2/blocks?limit=10&page=1",
            "last": "/api/v2/blocks?limit=10&page=1"
        },
        "data": [
        {
            "id": "string",
            "version": int,
            "height": int,
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
TEST(api, test_two_blocks)
{
    Ark::Client arkClient(DEVNET);

    const auto blocksResponse = arkClient.blocks();

    auto parser = Ark::Test::Utils::JSONParser(blocksResponse);

    const auto version = parser->getRoot()["data"][0]["version"].as<int>();
    ASSERT_STRNE("", toString(version).c_str());
}

/* test_two_blocks_blocks_limit_page
 * https://dexplorer.ark.io:8443/api/v2/blocks?limit=10&page=1
 * Expected Response:
    {
        "meta": {
            "count": int,
            "pageCount": int,
            "totalCount": int,
            "next": null,
            "previous": null,
            "self": "\api/v2/blocks?limit=10&page=1",
            "first": "/api/v2/blocks?limit=10&page=1",
            "last": "/api/v2/blocks?limit=10&page=1"
        },
        "data":
        [
            {
                "id": "string",
                "version": int,
                "height": int,
                "previous": "string",
                "forged": {
                    "reward": unsigned long,
                    "fee": unsigned long,
                    "total": unsigned long
                },
                "payload": {
                    "hash": "string",
                    "length": ing
                },
                "generator": {
                    "username": "string",
                    "address": "string",
                    "publicKey": "string"
                },
                "signature": "string",
                "transactions": ing,
                "timestamp": {
                    "epoch": int,
                    "unix": int,
                    "human": "string"
                }
            }
        ]
    }
 */
TEST(api, test_two_blocks_limit_page)
{
    Ark::Client arkClient(DEVNET);

    const auto blocksResponse = arkClient.blocks(5, 1);

    auto parser = Ark::Test::Utils::JSONParser(blocksResponse);

    const auto version = parser->getRoot()["data"][0]["version"].as<int>();
    ASSERT_STRNE("", toString(version).c_str());
}

#endif
