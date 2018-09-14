

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

#ifdef HAS_ONE_API

TEST(api, test_one_blocks_block)
{
    Ark::Client arkClient(DEVNET);

    const auto blockResponse = arkClient.block("4367122150875693402");

    DynamicJsonBuffer jsonBuffer(blockResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockResponse);

    JsonObject& block = root["block"];

    const auto id = block["id"];
    ASSERT_STREQ("4367122150875693402", id);

    int version = block["version"];
    ASSERT_EQ(0, version);

    int timestamp = block["timestamp"];
    ASSERT_EQ(25271824, timestamp);

    int height = block["height"];
    ASSERT_EQ(2287265, height);

    const char* previousBlock = block["previousBlock"];
    ASSERT_STREQ("17021413347323836951", previousBlock);

    int numberOfTransactions = block["numberOfTransactions"];
    ASSERT_EQ(0, numberOfTransactions);

    const auto totalAmount = block["totalAmount"].as<unsigned long long>();
    ASSERT_STREQ("0", toString(totalAmount).c_str());

    const auto totalFee = block["totalFee"].as<unsigned long long>();
    ASSERT_STREQ("0", toString(totalFee).c_str());

    const auto reward = block["reward"].as<unsigned long long>();
    ASSERT_STREQ("200000000", toString(reward).c_str());

    int payloadLength = block["payloadLength"];
    ASSERT_EQ(0, payloadLength);

    const char* payloadHash = block["payloadHash"];
    ASSERT_STREQ("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855", payloadHash);

    const char* generatorPublicKey = block["generatorPublicKey"];
    ASSERT_STREQ("02a9a0ac34a94f9d27fd9b4b56eb3c565a9a3f61e660f269775fb456f7f3301586", generatorPublicKey);

    const char* generatorId = block["generatorId"];
    ASSERT_STREQ("D5PXQVeJmchVrZFHL7cALZK8mWWzjCaVfz", generatorId);

    const char* blockSignature = block["blockSignature"];
    ASSERT_STREQ("3045022100954a3726e3592d74e6005841ebf9eaef576a40291881ba0b3739da325b75fcbf022023ff247d11a1238052b48f01930f04380c501309f01ae0dbc6b6cf637c16f3b0", blockSignature);

    int confirmations = block["confirmations"];
    ASSERT_NE(0, confirmations);

    const auto totalForged = block["totalForged"].as<unsigned long long>();
    ASSERT_STREQ("200000000", toString(totalForged).c_str());
}

TEST(api, test_one_blocks_blocks)
{
    Ark::Client arkClient(DEVNET);

    const auto blocksResponse = arkClient.blocks();

    DynamicJsonBuffer jsonBuffer(blocksResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blocksResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);


    JsonArray& blocks = root["blocks"];

    for (int i = 0; i < 10; i++) {
        int version = blocks[i]["version"];
        ASSERT_EQ(0, version);
    }
}

TEST(api, test_one_blocks_epoch)
{
    Ark::Client arkClient(DEVNET);

    const auto epochResponse = 	arkClient.blockEpoch();

    DynamicJsonBuffer jsonBuffer(epochResponse.size());
    JsonObject& root = jsonBuffer.parseObject(epochResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const char* epoch = root["epoch"];
    ASSERT_STREQ("2017-03-21T13:00:00.000Z", epoch);
}

TEST(api, test_one_blocks_fee)
{
    Ark::Client arkClient(DEVNET);

    const auto blockFeeResponse = arkClient.blockFee();

    DynamicJsonBuffer jsonBuffer(blockFeeResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockFeeResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const auto blockFee = root["fee"].as<unsigned long long>();
    ASSERT_STREQ("10000000", toString(blockFee).c_str());
}

TEST(api, test_one_blocks_fees)
{
    Ark::Client arkClient(DEVNET);

    const auto blockFeesResponse = arkClient.blockFees();

    DynamicJsonBuffer jsonBuffer(blockFeesResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockFeesResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);


    JsonObject& fees = root["fees"];

    const auto send = fees["send"].as<unsigned long long>();
    ASSERT_STREQ("10000000", toString(send).c_str());

    const auto vote = fees["vote"].as<unsigned long long>();
    ASSERT_STREQ("100000000", toString(vote).c_str());

    const auto secondsignature = fees["secondsignature"].as<unsigned long long>();
    ASSERT_STREQ("500000000", toString(secondsignature).c_str());

    const auto delegate = fees["delegate"].as<unsigned long long>();
    ASSERT_STREQ("2500000000", toString(delegate).c_str());

    const auto multisignature = fees["multisignature"].as<unsigned long long>();
    ASSERT_STREQ("500000000", toString(multisignature).c_str());
}

TEST(api, test_one_blocks_height)
{
    Ark::Client arkClient(DEVNET);

    const auto blockHeightResponse = arkClient.blockHeight();

    DynamicJsonBuffer jsonBuffer(blockHeightResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockHeightResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    int height = root["height"];
    ASSERT_NE(0, height);

    const char* id = root["id"];
    ASSERT_STRNE("", id);
}

TEST(api, test_one_blocks_milestone)
{
    Ark::Client arkClient(DEVNET);

    const auto blockMilestoneResponse = arkClient.blockMilestone();

    DynamicJsonBuffer jsonBuffer(blockMilestoneResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockMilestoneResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    int milestone = root["milestone"];
    ASSERT_EQ(0, milestone);
}

TEST(api, test_one_blocks_nethash)
{
    Ark::Client arkClient(DEVNET);

    const auto nethashResponse = arkClient.blockNethash();

    DynamicJsonBuffer jsonBuffer(nethashResponse.size());
    JsonObject& root = jsonBuffer.parseObject(nethashResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const char* nethash = root["nethash"];
    // ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", nethash); // v1 devnet nethash
    ASSERT_STREQ("2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867", nethash); // v2 devnet nethash
}

TEST(api, test_one_blocks_reward)
{
    Ark::Client arkClient(DEVNET);

    const auto blockRewardResponse = arkClient.blockReward();

    DynamicJsonBuffer jsonBuffer(blockRewardResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockRewardResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const auto reward = root["reward"].as<unsigned long long>();
    ASSERT_STREQ("200000000", toString(reward).c_str());
}

TEST(api, test_one_blocks_status)
{
    Ark::Client arkClient(DEVNET);

    const auto blockStatusResponse = arkClient.blockStatus();

    DynamicJsonBuffer jsonBuffer(blockStatusResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockStatusResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const char* epoch = root["epoch"];
    ASSERT_STREQ("2017-03-21T13:00:00.000Z", epoch);

    int height = root["height"];
    ASSERT_NE(0, height);

    const auto fee = root["fee"].as<unsigned long long>();
    ASSERT_STREQ("10000000", toString(fee).c_str());

    int milestone = root["milestone"];
    ASSERT_EQ(0, milestone);

    const char* nethash = root["nethash"];
    // ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", nethash); // v1 devnet nethash
    ASSERT_STREQ("2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867", nethash);  // v2 devnet nethash
    
    const auto reward = root["reward"].as<unsigned long long>();
    ASSERT_STREQ("200000000", toString(reward).c_str());

    const auto supply = root["supply"].as<unsigned long long>();
    ASSERT_STRNE("0", toString(supply).c_str());
}

TEST(api, test_one_blocks_supply)
{
    Ark::Client arkClient(DEVNET);

    const auto blockSupplyResponse = arkClient.blockSupply();

    DynamicJsonBuffer jsonBuffer(blockSupplyResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockSupplyResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const auto supply = root["supply"].as<unsigned long long>();
    ASSERT_STREQ("12962158800000000", toString(supply).c_str());
}

#endif
