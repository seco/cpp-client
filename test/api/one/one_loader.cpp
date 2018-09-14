

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

#ifdef HAS_ONE_API

TEST(api, test_one_loader_autoconfigure)
{
    Ark::Client arkClient(DEVNET);

    const auto autoconfigureResponse = arkClient.loaderAutoconfigure();

    DynamicJsonBuffer jsonBuffer(autoconfigureResponse.size());
    JsonObject& root = jsonBuffer.parseObject(autoconfigureResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);


    JsonObject& network = root["network"];

    const char* nethash = network["nethash"];
    // ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", nethash); // v1 devnet nethash
    ASSERT_STREQ("2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867", nethash); // v2 devnet nethash

    const char* token = network["token"];
    ASSERT_STREQ("DArk", token);

    const char* symbol = network["symbol"];
    ASSERT_STREQ(u8"DѦ", symbol);

    const char* explorer = network["explorer"];
    ASSERT_STREQ("http://dexplorer.ark.io", explorer);

    int version = network["version"];
    ASSERT_EQ(30, version);
}

TEST(api, test_one_loader_status)
{
    Ark::Client arkClient(DEVNET);
    
    const auto statusResponse = arkClient.loaderStatus();

    DynamicJsonBuffer jsonBuffer(statusResponse.size());
    JsonObject& root = jsonBuffer.parseObject(statusResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    bool loaded = root["loaded"];
    ASSERT_TRUE(loaded);

    int now = root["now"];
    ASSERT_NE(0, now);
    
    int blocksCount = root["blocksCount"];
    ASSERT_EQ(0, blocksCount);
}

TEST(api, test_one_loader_sync)
{
    Ark::Client arkClient(DEVNET);

    const auto syncResponse = arkClient.loaderSync();

    DynamicJsonBuffer jsonBuffer(syncResponse.size());
    JsonObject& root = jsonBuffer.parseObject(syncResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    bool syncing = root["syncing"];
    ASSERT_FALSE(syncing);

    int blocks = root["blocks"];
    ASSERT_STRNE("", toString(blocks).c_str());

    int height = root["height"];
    ASSERT_NE(0, height);

    const char* id = root["id"];
    ASSERT_STRNE("", id);
}

#endif
