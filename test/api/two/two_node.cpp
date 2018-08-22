

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_TWO_API

/* test_two_node_configuration
 * https://dexplorer.ark.io:8443/api/v2/node/configuration
 * Expected Response:
    {
    "data": {
        "nethash": "2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867",
        "token": "DARK",
        "symbol": "D\u0466",
        "explorer": "https:\/\/dexplorer.ark.io",
        "version": 30,
        "ports": {
            "@arkecosystem\/core-p2p": "4002",
            "@arkecosystem\/core-api": "4003"
        },
        "constants": {
            "height": 10800,
            "reward": 200000000,
            "activeDelegates": 51,
            "blocktime": 8,
            "block": {
                "version": 0,
                "maxTransactions": 50,
                "maxPayload": 2097152
            },
            "epoch": "2017-03-21T13:00:00.000Z",
            "fees": {
                "dynamic": false,
                "transfer": 10000000,
                "secondSignature": 500000000,
                "delegateRegistration": 2500000000,
                "vote": 100000000,
                "multiSignature": 500000000,
                "ipfs": 0,
                "timelockTransfer": 0,
                "multiPayment": 0,
                "delegateResignation": 0
            },
            "dynamicOffsets": {
                "transfer": 100,
                "secondSignature": 250,
                "delegateRegistration": 500,
                "vote": 100,
                "multiSignature": 500,
                "ipfs": 250,
                "timelockTransfer": 500,
                "multiPayment": 500,
                "delegateResignation": 500
            }
        },
        "feeStatistics": [
        {
            "type": 0,
            "fees": {
                "minFee": 10000,
                "maxFee": 10000000,
                "avgFee": 9682191
            }
        },
        {
            "type": 3,
            "fees": {
                "minFee": 100000000,
                "maxFee": 100000000,
                "avgFee": 100000000
            }
        },
        {
            "type": 1,
            "fees": {
                "minFee": 500000000,
                "maxFee": 500000000,
                "avgFee": 500000000
            }
        },
        {
            "type": 2,
            "fees": {
                "minFee": 2500000000,
                "maxFee": 2500000000,
                "avgFee": 2500000000
            }
        },
        {
            "type": 4,
            "fees": {
                "minFee": 1500000000,
                "maxFee": 1500000000,
                "avgFee": 1500000000
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
    auto parser = Ark::Test::Utils::makeJSONString(nodeConfiguration);

    const auto nethash = parser->valueIn("data", "nethash");
    ASSERT_STREQ("2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867", nethash.c_str());

    const auto token = parser->valueIn("data", "token");
    ASSERT_STREQ("DARK", token.c_str());

    const auto symbol = parser->valueIn("data", "symbol");
    ASSERT_STREQ("D\xD1\xA6", symbol.c_str());

    const auto explorer = parser->valueIn("data", "explorer");
    ASSERT_STREQ("https://dexplorer.ark.io", explorer.c_str());

    const auto version = parser->valueIn("data", "version");
    ASSERT_STREQ("30", version.c_str());

    const auto core_p2p = parser->subvalueNestedIn("data", "ports", "@arkecosystem/core-p2p");
    ASSERT_STREQ("4002", core_p2p.c_str());

    const auto core_api = parser->subvalueNestedIn("data", "ports", "@arkecosystem/core-api");
    ASSERT_STREQ("4003", core_api.c_str());
}

/* test_two_node_status
 * https://dexplorer.ark.io:8443/api/v2/node/status
 * Expected Response:
    {
        "data": {
            "synced": true,
            "now": 174889,
            "blocksCount": -6299
        }
    }
 */
TEST(api, test_two_node_status)
{
    Ark::Client arkClient(DEVNET);

    const auto nodeStatus = arkClient.nodeStatus();
    auto parser = Ark::Test::Utils::makeJSONString(nodeStatus);

    const auto synced = parser->valueIn("data", "synced");
    ASSERT_STREQ("true", synced.c_str());

    const auto now = parser->valueIn("data", "now");
    ASSERT_STRNE("0", now.c_str());
    ASSERT_STRNE("", now.c_str());

    const auto blocksCount = parser->valueIn("data", "blocksCount");
    ASSERT_STRNE("0", blocksCount.c_str());
    ASSERT_STRNE("", blocksCount.c_str());
}

/* test_two_node_status
 * https://dexplorer.ark.io:8443/api/v2/node/syncing
 * Expected Response:
    {
        "data": {
            "syncing": false,
            "blocks": -6303,
            "height": 174893,
            "id": "8997771716382553758"
        }
    }
 */
TEST(api, test_two_node_syncing)
{
    Ark::Client arkClient(DEVNET);

    const auto nodeSycing = arkClient.nodeSycing();
    auto parser = Ark::Test::Utils::makeJSONString(nodeSycing);

    const auto syncing = parser->valueIn("data", "syncing");
    ASSERT_STREQ("false", syncing.c_str());

    const auto blocks = parser->valueIn("data", "blocks");
    ASSERT_STRNE("0", blocks.c_str());
    ASSERT_STRNE("", blocks.c_str());

    const auto height = parser->valueIn("data", "height");
    ASSERT_STRNE("0", height.c_str());
    ASSERT_STRNE("", height.c_str());

    const auto id = parser->valueIn("data", "id");
    ASSERT_STRNE("0", id.c_str());
    ASSERT_STRNE("", id.c_str());
}

#endif
