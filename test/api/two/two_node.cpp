

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_TWO_API

/* test_two_node_configuration
 * https://dexplorer.ark.io:8443/api/v2/node/configuration
 * Expected Response:
    {
    "data": {
        "nethash": "string",
        "token": "string",
        "symbol": "string",
        "explorer": "string",
        "version": int,
        "ports": {
            "@arkecosystem\/core-p2p": "int",
            "@arkecosystem\/core-api": "int"
        },
        "constants": {
            "height": unsigned long,
            "reward": unsigned long,
            "activeDelegates": int,
            "blocktime": 8,
            "block": {
                "version": int,
                "maxTransactions": int,
                "maxPayload": int
            },
            "epoch": "string",
            "fees": {
                "dynamic": bool,
                "transfer": unsigned long,
                "secondSignature": unsigned long,
                "delegateRegistration": unsigned long,
                "vote": unsigned long,
                "multiSignature": unsigned long,
                "ipfs": int,
                "timelockTransfer": int,
                "multiPayment": int,
                "delegateResignation": int
            },
            "dynamicOffsets": {
                "transfer": int,
                "secondSignature": int,
                "delegateRegistration": int,
                "vote": int,
                "multiSignature": int,
                "ipfs": int,
                "timelockTransfer": int,
                "multiPayment": int,
                "delegateResignation": int
            }
        },
        "feeStatistics": [
        {
            "type": 0,
            "fees": {
                "minFee": unsigned long,
                "maxFee": unsigned long,
                "avgFee": unsigned long
            }
        },
        {
            "type": 3,
            "fees": {
                "minFee": unsigned long,
                "maxFee": unsigned long,
                "avgFee": unsigned long
            }
        },
        {
            "type": 1,
            "fees": {
                "minFee": unsigned long,
                "maxFee": unsigned long,
                "avgFee": unsigned long
            }
        },
        {
            "type": 2,
            "fees": {
                "minFee": unsigned long,
                "maxFee": unsigned long,
                "avgFee": unsigned long
            }
        },
        {
            "type": 4,
            "fees": {
                "minFee": unsigned long,
                "maxFee": unsigned long,
                "avgFee": unsigned long
            }
        }
        ]
    }
    }
*/
TEST(api, test_two_node_configuration)
{
    Ark::Client arkClient(DEVNET);

    const auto nodeConfiguration = arkClient.nodeConfiguration();
    auto parser = Ark::Test::Utils::JSONParser(nodeConfiguration);

    const auto nethash = parser->getRoot()["data"]["nethash"].as<const char*>();
    ASSERT_STREQ("2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867", nethash);

    const auto token = parser->getRoot()["data"]["token"].as<const char*>();
    ASSERT_STREQ("DARK", token);

    const auto symbol = parser->getRoot()["data"]["symbol"].as<const char*>();
    ASSERT_STREQ("D\xD1\xA6", symbol);

    const auto explorer = parser->getRoot()["data"]["explorer"].as<const char*>();
    ASSERT_STREQ("https://dexplorer.ark.io", explorer);

    const auto version = parser->getRoot()["data"]["version"].as<int>();
    ASSERT_STREQ("30", toString(version).c_str());

    const auto core_p2p = parser->getRoot()["data"]["ports"]["@arkecosystem/core-p2p"].as<int>();
    ASSERT_STREQ("4002", toString(core_p2p).c_str());

    const auto core_api = parser->getRoot()["data"]["ports"]["@arkecosystem/core-api"].as<int>();
    ASSERT_STREQ("4003", toString(core_api).c_str());
}

/* test_two_node_status
 * https://dexplorer.ark.io:8443/api/v2/node/status
 * Expected Response:
    {
        "data": {
            "synced": bool,
            "now": int,
            "blocksCount": int
        }
    }
 */
TEST(api, test_two_node_status)
{
    Ark::Client arkClient(DEVNET);

    const auto nodeStatus = arkClient.nodeStatus();
    auto parser = Ark::Test::Utils::JSONParser(nodeStatus);

    const auto synced = parser->getRoot()["data"]["synced"].as<bool>();
    ASSERT_EQ(1, synced);

    const auto now = parser->getRoot()["data"]["now"].as<int>();
    ASSERT_STRNE("0", toString(now).c_str());

    const auto blocksCount = parser->getRoot()["data"]["blocksCount"].as<int>();
    ASSERT_STRNE("0", toString(blocksCount).c_str());
}

/* test_two_node_status
 * https://dexplorer.ark.io:8443/api/v2/node/syncing
 * Expected Response:
    {
    "data": {
        "syncing": bool,
        "blocks": int,
        "height": unsigned long,
        "id": "string"
    }
    }
 */
TEST(api, test_two_node_syncing)
{
    Ark::Client arkClient(DEVNET);

    const auto nodeSycing = arkClient.nodeSycing();
    auto parser = Ark::Test::Utils::JSONParser(nodeSycing);

    const auto syncing = parser->getRoot()["data"]["syncing"].as<bool>();
    ASSERT_EQ(0, syncing);

    const auto blocks = parser->getRoot()["data"]["blocks"].as<int>();
    ASSERT_STRNE("0", toString(blocks).c_str());

    const auto height = parser->getRoot()["data"]["height"].as<unsigned long long>();
    ASSERT_STRNE("0", toString(height).c_str());

    const auto id = parser->getRoot()["data"]["id"].as<const char*>();
    ASSERT_STRNE("", id);
}

#endif
