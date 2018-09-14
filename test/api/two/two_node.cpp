

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

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
                "transfer": unsigned long long,
                "secondSignature": unsigned long long,
                "delegateRegistration": unsigned long long,
                "vote": unsigned long long,
                "multiSignature": unsigned long long,
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

    DynamicJsonBuffer jsonBuffer(nodeConfiguration.size());
    JsonObject& root = jsonBuffer.parseObject(nodeConfiguration);

    JsonObject& data = root["data"];

    const char* nethash = data["nethash"];
    ASSERT_STREQ("2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867", nethash);

    const char* token = data["token"];
    ASSERT_STREQ("DARK", token);

    const char* symbol = data["symbol"];
    ASSERT_STREQ("D\xD1\xA6", symbol);

    const char* explorer = data["explorer"];
    ASSERT_STREQ("https://dexplorer.ark.io", explorer);

    int version = data["version"];
    ASSERT_EQ(30, version);


    JsonObject& ports = data["ports"];

    int core_p2p = ports["@arkecosystem/core-p2p"];
    ASSERT_EQ(4002, core_p2p);

    int core_api = ports["@arkecosystem/core-api"];
    ASSERT_EQ(4003, core_api);
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

    DynamicJsonBuffer jsonBuffer(nodeStatus.size());
    JsonObject& root = jsonBuffer.parseObject(nodeStatus);

    JsonObject& data = root["data"];

    bool synced = data["synced"];
    ASSERT_EQ(1, synced);

    int now = data["now"];
    ASSERT_NE(0, now);

    int blocksCount = data["blocksCount"];
    ASSERT_NE(0, blocksCount);
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

    DynamicJsonBuffer jsonBuffer(nodeSycing.size());
    JsonObject& root = jsonBuffer.parseObject(nodeSycing);

    JsonObject& data = root["data"];

    bool syncing = data["syncing"];
    ASSERT_EQ(0, syncing);

    int blocks = data["blocks"];
    ASSERT_NE(0, blocks);

    const auto height = data["height"].as<unsigned long>();
    ASSERT_STRNE("0", toString(height).c_str());

    const char* id = data["id"];
    ASSERT_STRNE("", id);
}

#endif
