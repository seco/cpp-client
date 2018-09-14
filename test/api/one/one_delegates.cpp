

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

#ifdef HAS_ONE_API

namespace
{
    const auto darkPubkey = "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456";
}

TEST(api, test_one_delegates_fee)
{
    Ark::Client arkClient(DEVNET);

    const auto delegateFeeResponse = arkClient.delegateFee();

    DynamicJsonBuffer jsonBuffer(delegateFeeResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegateFeeResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const auto delegateFee = root["fee"].as<unsigned long long>();
    ASSERT_STREQ("2500000000", toString(delegateFee).c_str());
}

TEST(api, test_one_delegates_forged_by_account)
{
    Ark::Client arkClient(DEVNET);

    const auto forgedByAccountResponse = arkClient.delegateForgedByAccount(darkPubkey);

    DynamicJsonBuffer jsonBuffer(forgedByAccountResponse.size());
    JsonObject& root = jsonBuffer.parseObject(forgedByAccountResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const auto fees = root["fees"].as<unsigned long long>();
    ASSERT_STRNE("", toString(fees).c_str());

    const auto rewards = root["rewards"].as<unsigned long long>();
    ASSERT_STRNE("", toString(rewards).c_str());

    const auto forged = root["forged"].as<unsigned long long>();
    ASSERT_STRNE("", toString(forged).c_str());
}

TEST(api, test_one_delegates_next_forgers)
{
    Ark::Client arkClient(DEVNET);

    const auto nextForgersResponse = arkClient.delegateNextForgers();

    DynamicJsonBuffer jsonBuffer(nextForgersResponse.size());
    JsonObject& root = jsonBuffer.parseObject(nextForgersResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    int currentBlock = root["currentBlock"];
    ASSERT_NE(0, currentBlock);

    int currentSlot = root["currentSlot"];
    ASSERT_NE(0, currentSlot);

    JsonArray& delegates = root["delegates"];
    for (int i = 0; i < 10; ++i)
    {
        const char* delegateKey = delegates[i];
        ASSERT_STRNE("", delegateKey);
    };
}

TEST(api, test_one_delegates_delegate_by_public_key)
{
    Ark::Client arkClient(DEVNET);

    auto delegateResponse = arkClient.delegate(darkPubkey);

    DynamicJsonBuffer jsonBuffer(delegateResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegateResponse);

    JsonObject& delegate = root["delegate"];

    const char* username = delegate["username"];
    ASSERT_STREQ("sleepdeficit", username);

    const char* address = delegate["address"];
    ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address);

    const char* publicKey = delegate["publicKey"];
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey);

    const auto vote = delegate["vote"].as<unsigned long>();
    ASSERT_STRNE("", toString(vote).c_str());

    int producedblocks = delegate["producedblocks"];
    ASSERT_NE(0, producedblocks);

    int missedblocks = delegate["missedblocks"];
    ASSERT_NE(0, missedblocks);

    int rate = delegate["rate"];
    ASSERT_NE(0, rate);

    double approval = delegate["approval"];
    ASSERT_NE(0.00, approval);

    double productivity = delegate["productivity"];
    ASSERT_NE(0.00, productivity);
}

TEST(api, test_one_delegates_delegate_by_username)
{
    Ark::Client arkClient(DEVNET);

    const auto delegateResponse = arkClient.delegate("sleepdeficit");

    DynamicJsonBuffer jsonBuffer(delegateResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegateResponse);

    JsonObject& delegate = root["delegate"];

    const char* username = delegate["username"];
    ASSERT_STREQ("sleepdeficit", username);

    const char* address = delegate["address"];
    ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address);

    const char* publicKey = delegate["publicKey"];
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey);

    const auto vote = delegate["vote"];
    ASSERT_NE(0, vote);

    int producedblocks = delegate["producedblocks"];
    ASSERT_NE(0, producedblocks);

    int missedblocks = delegate["missedblocks"];
    ASSERT_NE(0, missedblocks);

    int rate = delegate["rate"];
    ASSERT_NE(0, rate);

    double approval = delegate["approval"];
    ASSERT_NE(0.00, approval);

    double productivity = delegate["productivity"];
    ASSERT_NE(0.00, productivity);
}

TEST(api, test_one_delegates_delegates)
{
    Ark::Client arkClient(DEVNET);

    const auto delegatesResponse = arkClient.delegates();

    DynamicJsonBuffer jsonBuffer(delegatesResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegatesResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);


    JsonArray& delegates = root["delegates"];

    for (int i = 0; i < 20; i++) 
    {
        const char* username = delegates[i]["username"];
        ASSERT_STRNE("", username);

        const char* address = delegates[i]["address"];
        ASSERT_STRNE("", address);

        const char* publicKey = delegates[i]["publicKey"];
        ASSERT_STRNE("", publicKey);

        const auto vote = delegates[i]["vote"].as<unsigned long>();
        ASSERT_STRNE("0", toString(vote).c_str());

        int producedblocks = delegates[i]["producedblocks"];
        ASSERT_NE(0, producedblocks);

        int missedblocks = delegates[i]["missedblocks"];
        ASSERT_NE(0, missedblocks);

        int rate = delegates[i]["rate"];
        ASSERT_NE(0, rate);

        double approval = delegates[i]["approval"];
        ASSERT_NE(0.00, approval);

        double productivity = delegates[i]["productivity"];
        ASSERT_NE(0.00, productivity);
    }
}

TEST(api, test_one_delegates_voters)
{
    Ark::Client arkClient(DEVNET);

    const auto votersResponse = arkClient.delegateVoters(darkPubkey);

    DynamicJsonBuffer jsonBuffer(votersResponse.size());
    JsonObject& root = jsonBuffer.parseObject(votersResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);


    JsonObject& accountsZero = root["accounts"][0];

    const char* address0 = accountsZero["address"];
    ASSERT_STREQ("DS3jiY1uPToqfGKmmfsdFnBhMmsrQY47gd", address0);

    const char* publicKey0 = accountsZero["publicKey"];
    ASSERT_STREQ("03c57e437203403c5438bdb93f34d46a708a5d23a63fa9fe44c5fed1fa458d0717", publicKey0);

    const auto balance0 = accountsZero["balance"].as<unsigned long>();
    ASSERT_STREQ("0", toString(balance0).c_str());


    JsonObject& accountsOne = root["accounts"][1];

    const char* username1 = accountsOne["username"];
    ASSERT_STREQ("sleepdeficit", username1);

    const char* address1 = accountsOne["address"];
    ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address1);

    const char* publicKey1 = accountsOne["publicKey"];
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey1);

    const auto balance1 = accountsOne["balance"].as<unsigned long>();
    ASSERT_EQ(0, balance1);
}

TEST(api, test_one_delegates_search)
{
    Ark::Client arkClient(DEVNET);

    const auto delegateResponse = arkClient.delegate("sleepdeficit");

    DynamicJsonBuffer jsonBuffer(delegateResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegateResponse);

    JsonObject& delegate = root["delegate"];

    const char* username = delegate["username"];
    ASSERT_STREQ("sleepdeficit", username);

    const char* address = delegate["address"];
    ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address);

    const char* publicKey = delegate["publicKey"];
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey);

    const auto vote = delegate["vote"].as<unsigned long>();
    ASSERT_NE(0, vote);

    int producedblocks = delegate["producedblocks"];
    ASSERT_NE(0, producedblocks);

    int missedblocks = delegate["missedblocks"];
    ASSERT_NE(0, missedblocks);

    int rate = delegate["rate"];
    ASSERT_NE(0, rate);

    double  approval = delegate["approval"];
    ASSERT_NE(0.00, approval);

    double productivity = delegate["productivity"];
    ASSERT_NE(0.00, productivity);
}

TEST(api, test_one_delegates_count)
{
    Ark::Client arkClient(DEVNET);

    const auto delegatesCountResponse = arkClient.delegatesCount();

    DynamicJsonBuffer jsonBuffer(delegatesCountResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegatesCountResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    int count = root["count"];
    ASSERT_NE(0, count);
}

#endif
