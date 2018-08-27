

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_ONE_API

TEST(api, test_one_blocks_block)
{
    Ark::Client arkClient(DEVNET);

    const auto blockResponse = arkClient.block("4367122150875693402");

    auto parser = Ark::Test::Utils::JSONParser(blockResponse);

    const auto id = parser->getRoot()["block"]["id"].as<const char*>();
    ASSERT_STREQ("4367122150875693402", id);

    const auto version = parser->getRoot()["block"]["version"].as<int>();
    ASSERT_EQ(0, version);

    const auto timestamp = parser->getRoot()["block"]["timestamp"].as<int>();
    ASSERT_EQ(25271824, timestamp);

    const auto height = parser->getRoot()["block"]["height"].as<int>();
    ASSERT_EQ(2287265, height);

    const auto previousBlock = parser->getRoot()["block"]["previousBlock"].as<const char*>();
    ASSERT_STREQ("17021413347323836951", previousBlock);

    const auto numberOfTransactions = parser->getRoot()["block"]["numberOfTransactions"].as<int>();
    ASSERT_EQ(0, numberOfTransactions);

    const auto totalAmount = parser->getRoot()["block"]["totalAmount"].as<unsigned long long>();
    ASSERT_STREQ("0", toString(totalAmount).c_str());

    const auto totalFee = parser->getRoot()["block"]["totalFee"].as<unsigned long long>();
    ASSERT_STREQ("0", toString(totalFee).c_str());

    const auto reward = parser->getRoot()["block"]["reward"].as<unsigned long long>();
    ASSERT_STREQ("200000000", toString(reward).c_str());

    const auto payloadLength = parser->getRoot()["block"]["payloadLength"].as<int>();
    ASSERT_EQ(0, payloadLength);

    const auto payloadHash = parser->getRoot()["block"]["payloadHash"].as<const char*>();
    ASSERT_STREQ("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855", payloadHash);

    const auto generatorPublicKey = parser->getRoot()["block"]["generatorPublicKey"].as<const char*>();
    ASSERT_STREQ("02a9a0ac34a94f9d27fd9b4b56eb3c565a9a3f61e660f269775fb456f7f3301586", generatorPublicKey);

    const auto generatorId = parser->getRoot()["block"]["generatorId"].as<const char*>();
    ASSERT_STREQ("D5PXQVeJmchVrZFHL7cALZK8mWWzjCaVfz", generatorId);

    const auto blockSignature = parser->getRoot()["block"]["blockSignature"].as<const char>());
    ASSERT_STREQ("3045022100954a3726e3592d74e6005841ebf9eaef576a40291881ba0b3739da325b75fcbf022023ff247d11a1238052b48f01930f04380c501309f01ae0dbc6b6cf637c16f3b0", blockSignature);

    const auto confirmations = parser->getRoot()["block"]["confirmations"].as<int>();
    ASSERT_NE(0, confirmations);

    const auto totalForged = parser->getRoot()["block"]["totalForged"].as<unsigned long long>();
    ASSERT_STREQ("200000000", toString(totalForged).c_str());
}

TEST(api, test_one_blocks_blocks)
{
    Ark::Client arkClient(DEVNET);

    const auto blocksResponse = arkClient.blocks();

    auto parser = Ark::Test::Utils::JSONParser(blocksResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    for (int i = 0; i < 10; i++) // Full-list too large for MCU; limit to last 20 blocks.
    {
        const auto version = parser->getRoot()["blocks"][i]["version"].as<int>();
        ASSERT_EQ(0, version);
    }
}

TEST(api, test_one_blocks_epoch)
{
    Ark::Client arkClient(DEVNET);

    const auto epochResponse = 	arkClient.blockEpoch();

    auto parser = Ark::Test::Utils::JSONParser(epochResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto epoch = parser->getRoot()["epoch"].as<const char*>();
    ASSERT_STREQ("2017-03-21T13:00:00.000Z", epoch);
}

TEST(api, test_one_blocks_fee)
{
    Ark::Client arkClient(DEVNET);

    const auto blockFeeResponse = arkClient.blockFee();

    auto parser = Ark::Test::Utils::JSONParser(blockFeeResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto blockFee = parser->getRoot()["fee"].as<unsigned long long>();
    ASSERT_STREQ("10000000", toString(blockFee).c_str());
}

TEST(api, test_one_blocks_fees)
{
    Ark::Client arkClient(DEVNET);

    const auto blockFeesResponse = arkClient.blockFees();

    auto parser = Ark::Test::Utils::JSONParser(blockFeesResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto send = parser->getRoot()["fees"]["send"].as<unsigned long long>();
    ASSERT_STREQ("10000000", toString(send).c_str());

    const auto vote = parser->getRoot()["fees"]["vote"].as<unsigned long long>();
    ASSERT_STREQ("100000000", toString(vote).c_str());

    const auto secondsignature = parser->getRoot()["fees"]["secondsignature"].as<unsigned long long>();
    ASSERT_STREQ("500000000", toString(secondsignature).c_str());

    const auto delegate = parser->getRoot()["fees"]["delegate"].as<unsigned long long>();
    ASSERT_STREQ("2500000000", toString(delegate).c_str());

    const auto multisignature = parser->getRoot()["fees"]["multisignature"].as<unsigned long long>();
    ASSERT_STREQ("500000000", toString(multisignature).c_str());
}

TEST(api, test_one_blocks_height)
{
    Ark::Client arkClient(DEVNET);

    const auto blockHeightResponse = arkClient.blockHeight();

    auto parser = Ark::Test::Utils::JSONParser(blockHeightResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto height = parser->getRoot()["height"].as<int>();
    ASSERT_NE(0, height);

    const auto id = parser->getRoot()["id"].as<const char*>();
    ASSERT_STRNE("", id);
}

TEST(api, test_one_blocks_milestone)
{
    Ark::Client arkClient(DEVNET);

    const auto blockMilestoneResponse = arkClient.blockMilestone();

    auto parser = Ark::Test::Utils::JSONParser(blockMilestoneResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto milestone = parser->getRoot()["milestone"].as<int>();
    ASSERT_EQ(0, milestone);
}

TEST(api, test_one_blocks_nethash)
{
    Ark::Client arkClient(DEVNET);

    const auto nethashResponse = arkClient.blockNethash();

    auto parser = Ark::Test::Utils::JSONParser(nethashResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto nethash = parser->getRoot()["nethash"].as<const char*>();
    // ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", nethash); // v1 devnet nethash
    ASSERT_STREQ("2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867", nethash); // v2 devnet nethash
}

TEST(api, test_one_blocks_reward)
{
    Ark::Client arkClient(DEVNET);

    const auto blockRewardResponse = arkClient.blockReward();

    auto parser = Ark::Test::Utils::JSONParser(blockRewardResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto reward = parser->getRoot()["reward"].as<unsigned long long>();
    ASSERT_STREQ("200000000", toString(reward).c_str());
}

TEST(api, test_one_blocks_status)
{
    Ark::Client arkClient(DEVNET);

    const auto blockStatusResponse = arkClient.blockStatus();

    auto parser = Ark::Test::Utils::JSONParser(blockStatusResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto epoch = parser->getRoot()["epoch"].as<const char*>();
    ASSERT_STREQ("2017-03-21T13:00:00.000Z", epoch);

    const auto height = parser->getRoot()["height"].as<int>();
    ASSERT_NE(0, height);

    const auto fee = parser->getRoot()["fee"].as<unsigned long long>();
    ASSERT_STREQ("10000000", toString(fee).c_str());

    const auto milestone = parser->getRoot()["milestone"].as<int>();
    ASSERT_STREQ("0", milestone);

    const auto nethash = parser->getRoot()["nethash"].as<const char*>();
    // ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", nethash); // v1 devnet nethash
    ASSERT_STREQ("2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867", nethash);  // v2 devnet nethash
    
    const auto reward = parser->getRoot()["reward"].as<unsigned long long>();
    ASSERT_STREQ("200000000", toString(reward).c_str());

    const auto supply = parser->getRoot()["supply"].as<unsigned long long>();
    ASSERT_STRNE("0", toString(supply).c_str());
}

TEST(api, test_one_blocks_supply)
{
    Ark::Client arkClient(DEVNET);

    const auto blockSupplyResponse = arkClient.blockSupply();

    auto parser = Ark::Test::Utils::JSONParser(blockSupplyResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto supply = parser->getRoot()["supply"].as<unsigned long long>();
    ASSERT_STREQ("12962158800000000", toString(supply).c_str());
}

#endif
