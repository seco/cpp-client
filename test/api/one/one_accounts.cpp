

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_ONE_API

namespace
{
    const auto darkAddress = "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA";
}

TEST(api, test_one_accounts_account)
{
    Ark::Client arkClient(DEVNET);

    const auto accountResponse = arkClient.account(darkAddress);

    auto parser = Ark::Test::Utils::JSONParser(accountResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto address = parser->getRoot()["account"]["address"].as<const char*>();
    ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address);
    
    const auto unconfirmedBalance = parser->getRoot()["account"]["unconfirmedBalance"].as<unsigned long long>();
    ASSERT_STRNE("", toString(unconfirmedBalance).c_str());

    const auto balance = parser->getRoot()["account"]["balance"].as<unsigned long long>();
    ASSERT_NE("", toString(balance).c_str());

    const auto publicKey = parser->getRoot()["account"]["publicKey"].as<const char*>();
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey);
    
    const auto unconfirmedSignature = parser->getRoot()["account"]["unconfirmedSignature"].as<int>();
    ASSERT_EQ(1, unconfirmedSignature); // actual value is 1 (int).

    const auto secondSignature = parser->getRoot()["account"]["secondSignature"].as<int>();
    ASSERT_EQ(1, secondSignature); 

    const auto secondPublicKey = parser->getRoot()["account"]["secondPublicKey"].as<const char*>();
    ASSERT_STREQ("03ad2a481719c80571061f0c941d57e91c928700d8dd132726edfc0bf9c4cb2869", secondPublicKey);
}

TEST(api, test_one_accounts_balance)
{
    Ark::Client arkClient(DEVNET);

    const auto accountBalanceResponse = arkClient.accountBalance(darkAddress);

    auto parser = Ark::Test::Utils::JSONParser(accountBalanceResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto balance = parser->getRoot()["balance"].as<unsigned long long>();
    ASSERT_STRNE("", toString(balance).c_str());

    const auto unconfirmedBalance = parser->getRoot()["unconfirmedBalance"].as<unsigned long long>();
    ASSERT_STRNE("", toString(unconfirmedBalance).c_str());
}

TEST(api, test_one_accounts_delegates)
{
    Ark::Client arkClient(DEVNET);

    const auto delegateResponse = arkClient.accountDelegates(darkAddress);

    auto parser = Ark::Test::Utils::JSONParser(delegateResponse);

    const auto username = parser->getRoot()["delegates"][0]["username"].as<const char*>();
    ASSERT_EQ("sleepdeficit", username);
    
    const auto address = parser->getRoot()["delegates"][0]["address"].as<const char*>();
    ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address);
    
    const auto publicKey = parser->getRoot()["delegates"][0]["publicKey"].as<const char*>();
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey);

    const auto vote = parser->getRoot()["delegates"][0]["vote"].as<unsigned long long>();
    ASSERT_NE(0, toString(vote).c_str());

    const auto producedblocks = parser->getRoot()["delegates"][0]["producedblocks"].as<int>;
    ASSERT_NE(0, producedblocks);

    const auto missedblocks = parser->getRoot()["delegates"][0]["missedblocks"].as<int>();
    ASSERT_NE(0, missedblocks);

    const auto rate = parser->getRoot()["delegates"][0]["rate"].as<int>();
    ASSERT_NE(0, rate);

    const auto approval = parser->getRoot()["delegates"][0]["approval"].as<double>();
    ASSERT_NE(0.00, approval);

    const auto productivity = parser->getRoot()["delegates"][0]["productivity"].as<double>();
    ASSERT_NE(0.00, productivity);
}

TEST(api, test_one_accounts_delegates_fee)
{
    Ark::Client arkClient(DEVNET);

    const auto delegatesFeeResponse = arkClient.accountDelegatesFee(darkAddress);

    auto parser = Ark::Test::Utils::JSONParser(delegatesFeeResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto delegatesFee = parser->getRoot()["fee"].as<unsigned long long>();
    ASSERT_EQ("2500000000", toString(delegatesFee));
}

TEST(api, test_one_accounts_public_key)
{
    Ark::Client arkClient(DEVNET);

    const auto pubkeyResponse = arkClient.accountPublickey(darkAddress);

    auto parser = Ark::Test::Utils::JSONParser(pubkeyResponse);

    const auto publicKey = parser->getRoot()["publicKey"].as<const char*>();
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey);
}

#endif
