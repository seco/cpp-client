

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_ONE_API

namespace
{
    const auto darkPubkey = "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456";
}

TEST(api, test_one_delegates_fee)
{
    Ark::Client arkClient(DEVNET);

    const auto delegateFeeResponse = arkClient.delegateFee();

    auto parser = Ark::Test::Utils::JSONParser(delegateFeeResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto delegateFee = parser->getRoot()["fee"].as<unsigned long long>();
    ASSERT_STREQ("2500000000", toString(delegateFee).c_str());
}

TEST(api, test_one_delegates_forged_by_account)
{
    Ark::Client arkClient(DEVNET);

    const auto forgedByAccountResponse = arkClient.delegateForgedByAccount(darkPubkey);

    auto parser = Ark::Test::Utils::JSONParser(forgedByAccountResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto fees = parser->getRoot()["fees"].as<unsigned long long>();
    ASSERT_STRNE("", toString(fees).c_str());

    const auto rewards = parser->getRoot()["rewards"].as<unsigned long long>();
    ASSERT_STRNE("", toString(rewards).c_str());

    const auto forged = parser->getRoot()["forged"].as<unsigned long long>();
    ASSERT_STRNE("", toString(forged).c_str());
}

TEST(api, test_one_delegates_next_forgers)
{
    Ark::Client arkClient(DEVNET);

    const auto nextForgersResponse = arkClient.delegateNextForgers();

    auto parser = Ark::Test::Utils::JSONParser(nextForgersResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto currentBlock = parser->getRoot()["currentBlock"].as<int>();
    ASSERT_NE("0", currentBlock);

    const auto currentSlot = parser->getRoot()["currentSlot"].as<int>();
    ASSERT_NE(0, currentSlot);

    for (int i = 0; i < 10; ++i)
    {
        const auto delegateKey = parser->getRoot()["delegates"][i].as<const char*>();
        ASSERT_STRNE("", delegateKey);
    };
}

TEST(api, test_one_delegates_delegate_by_public_key)
{
    Ark::Client arkClient(DEVNET);

    auto delegateResponse = arkClient.delegate(darkPubkey);

    auto parser = Ark::Test::Utils::JSONParser(delegateResponse);

    const auto username = parser->getRoot()["delegate"]["username"].as<const char*>();
    ASSERT_STREQ("sleepdeficit", username);

    const auto address = parser->getRoot()["delegate"]["address"].as<const char*>();
    ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address);

    const auto publicKey = parser->getRoot()["delegate"]["publicKey"].as<const char*>();
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey);

    const auto vote = parser->getRoot()["delegate"]["vote"].as<unsigned long long>();
    ASSERT_STRNE("", toString(vote).c_str());

    const auto producedblocks = parser->getRoot()["delegate"]["producedblocks"].as<int>();
    ASSERT_NE(0, producedblocks);

    const auto missedblocks = parser->getRoot()["delegate"]["missedblocks"].as<int>();
    ASSERT_NE(0, missedblocks);

    const auto rate = parser->getRoot()["delegate"]["rate"].as<int>();
    ASSERT_NE(0, rate);

    const auto approval = parser->getRoot()["delegate"]["approval"].as<double>();
    ASSERT_NE(0.00, approval);

    const auto productivity = parser->getRoot()["delegate"]["productivity"].as<double>();
    ASSERT_NE(0.00, productivity);
}

TEST(api, test_one_delegates_delegate_by_username)
{
    Ark::Client arkClient(DEVNET);

    const auto delegateResponse = arkClient.delegate("sleepdeficit");

    auto parser = Ark::Test::Utils::JSONParser(delegateResponse);

    const auto username = parser->getRoot()["delegate"]["username"].as<const char>();
    ASSERT_STREQ("sleepdeficit", username);

    const auto address = parser->getRoot()["delegate"]["address"].as<const char>();
    ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address);

    const auto publicKey = parser->getRoot()["delegate"]["publicKey"].as<const char*>();
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey);

    const auto vote = parser->getRoot()["delegate"]["vote"].as<unsigned long long>();
    ASSERT_NE(0, vote);

    const auto producedblocks = parser->getRoot()["delegate"]["producedblocks"].as<int>();
    ASSERT_NE(0, producedblocks);

    const auto missedblocks = parser->getRoot()["delegate"]["missedblocks"].as<int>();
    ASSERT_NE(0, missedblocks);

    const auto rate = parser->getRoot()["delegate"]["rate"].as<int>();
    ASSERT_NE(0, rate);

    const auto approval = parser->getRoot()["delegate"]["approval"].as<double>();
    ASSERT_NE(0.00, approval);

    const auto productivity = parser->getRoot()["delegate"]["productivity"].as<double>();
    ASSERT_NE(0.00, productivity);
}

TEST(api, test_one_delegates_delegates)
{
    Ark::Client arkClient(DEVNET);

    const auto delegatesResponse = arkClient.delegates();
    auto parser = Ark::Test::Utils::JSONParser(delegatesResponse);

    const auto success = parser->getRoot()["success");
    ASSERT_STREQ("true", success.c_str());

    for (int i = 0; i < 20; i++) 
    {
        const auto username = parser->getRoot()["delegates"][i]["username"].as<const char*>();
        ASSERT_STRNE("", username);

        const auto address = parser->getRoot()["delegates"][i]["address"].as<const char*>();
        ASSERT_STRNE("", address);

        const auto publicKey = parser->getRoot()["delegates"][i]["publicKey"].as<const char*>();
        ASSERT_STRNE("", publicKey);

        const auto vote = parser->getRoot()["delegates"][i]["vote"].as<unsigned long long>();
        ASSERT_STRNE("0", toString(vote).c_str());

        const auto producedblocks = parser->getRoot()["delegates"][i]["producedblocks"].as<int>();
        ASSERT_NE(0, producedblocks);

        const auto missedblocks = parser->getRoot()["delegates"][i]["missedblocks"].as<int>();
        ASSERT_NE(0, missedblocks);

        const auto rate = parser->getRoot()["delegates"][i]["rate"].as<int>();
        ASSERT_NE(0, rate);

        const auto approval = parser->getRoot()["delegates"][i]["approval"].as<double>();
        ASSERT_NE(0.00, approval);

        const auto productivity = parser->getRoot()["delegates"][i]["productivity"].as<double>();
        ASSERT_NE(0.00, productivity);
    }
}

TEST(api, test_one_delegates_voters)
{
    Ark::Client arkClient(DEVNET);

    const auto votersResponse = arkClient.delegateVoters(darkPubkey);

    auto parser = Ark::Test::Utils::JSONParser(votersResponse);

    const auto success = parser->getRoot()["success"].as<bool>());
    ASSERT_EQ(1, success);

    const auto address0 = parser->getRoot()["accounts"][0]["address"].as<const char>();
    ASSERT_STREQ("DS3jiY1uPToqfGKmmfsdFnBhMmsrQY47gd", address0);

    const auto publicKey0 = parser->getRoot()["accounts"][0]["publicKey"].as<const char*>();
    ASSERT_STREQ("03c57e437203403c5438bdb93f34d46a708a5d23a63fa9fe44c5fed1fa458d0717", publicKey0);

    const auto balance0 = parser->getRoot()["accounts"][0]["balance"].as<unsigned long long>();
    ASSERT_STREQ("0", toString(balance0).c_str());

    const auto username1 = parser->getRoot()["accounts"][1]["username"].as<const char>();
    ASSERT_STREQ("sleepdeficit", username1);

    const auto address1 = parser->getRoot()["accounts"][1]["address"].as<const char*>();
    ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address1);

    const auto publicKey1 = parser->getRoot()["accounts"][1]["publicKey"].as<const char*>();
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey1);

    const auto balance1 = parser->getRoot()["accounts"][1]["balance"].as<unsigned long long>();
    ASSERT_EQ(0, balance0);
}

TEST(api, test_one_delegates_search)
{
    Ark::Client arkClient(DEVNET);

    const auto delegateResponse = arkClient.delegate("sleepdeficit");

    auto parser = Ark::Test::Utils::JSONParser(delegateResponse);

    const auto username = parser->getRoot()["delegate"]["username"].as<const char*>();
    ASSERT_STREQ("sleepdeficit", username);

    const auto address = parser->getRoot()["delegate"]["address"].as<const char*>();
    ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address);

    const auto publicKey = parser->getRoot()["delegate"]["publicKey"].as<const char*>();
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey);

    const auto vote = parser->getRoot()["delegate"]["vote"].as<unsigned long long>();
    ASSERT_NE(0, vote);

    const auto producedblocks = parser->getRoot()["delegate"]["producedblocks"].as<int>();
    ASSERT_NE(0, producedblocks);

    const auto missedblocks = parser->getRoot()["delegate"]["missedblocks"].as<int>();
    ASSERT_NE(0, missedblocks);

    const auto rate = parser->getRoot()["delegate"]["rate"].as<int>();
    ASSERT_NE(0, rate);

    const auto approval = parser->getRoot()["delegate"]["approval"].as<double>();
    ASSERT_NE(0.00, approval);

    const auto productivity = parser->getRoot()["delegate"]["productivity"].as<double>();
    ASSERT_NE(0.00, productivity);
}

TEST(api, test_one_delegates_count)
{
    Ark::Client arkClient(DEVNET);

    const auto delegatesCountResponse = arkClient.delegatesCount();

    auto parser = Ark::Test::Utils::JSONParser(delegatesCountResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto count = parser->getRoot()["count"].as<int>();
    ASSERT_NE(0, count);
}

#endif
