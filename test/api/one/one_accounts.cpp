

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

#ifdef HAS_ONE_API

namespace
{
    const auto darkAddress = "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA";
}

TEST(api, test_one_accounts_account)
{
    Ark::Client arkClient(DEVNET);

    const auto accountResponse = arkClient.account(darkAddress);

    DynamicJsonBuffer jsonBuffer(accountResponse.size());
    JsonObject& root = jsonBuffer.parseObject(accountResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    JsonObject& account = root["account"];

    const char* address = account["address"];
    ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address);
    
    const auto unconfirmedBalance = account["unconfirmedBalance"].as<unsigned long long>();
    ASSERT_STRNE("", toString(unconfirmedBalance).c_str());

    const auto balance = account["balance"].as<unsigned long long>();
    ASSERT_NE("", toString(balance).c_str());

    const char* publicKey = account["publicKey"];
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey);
    
    int unconfirmedSignature = account["unconfirmedSignature"];
    ASSERT_EQ(1, unconfirmedSignature);

    int secondSignature = account["secondSignature"];
    ASSERT_EQ(1, secondSignature); 

    const char* secondPublicKey = account["secondPublicKey"];
    ASSERT_STREQ("03ad2a481719c80571061f0c941d57e91c928700d8dd132726edfc0bf9c4cb2869", secondPublicKey);
}

TEST(api, test_one_accounts_balance)
{
    Ark::Client arkClient(DEVNET);

    const auto accountBalanceResponse = arkClient.accountBalance(darkAddress);

    DynamicJsonBuffer jsonBuffer(accountBalanceResponse.size());
    JsonObject& root = jsonBuffer.parseObject(accountBalanceResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const auto balance = root["balance"].as<unsigned long long>();
    ASSERT_STRNE("", toString(balance).c_str());

    const auto unconfirmedBalance = root["unconfirmedBalance"].as<unsigned long long>();
    ASSERT_STRNE("", toString(unconfirmedBalance).c_str());
}

TEST(api, test_one_accounts_delegates)
{
    Ark::Client arkClient(DEVNET);

    const auto delegateResponse = arkClient.accountDelegates(darkAddress);

    DynamicJsonBuffer jsonBuffer(delegateResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegateResponse);

    JsonObject& delegatesZero = root["delegates"][0];

    const char* username = delegatesZero["username"];
    ASSERT_EQ("sleepdeficit", username);
    
    const char* address = delegatesZero["address"];
    ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address);
    
    const char* publicKey = delegatesZero["publicKey"];
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey);

    const auto vote = delegatesZero["vote"].as<unsigned long long>();
    ASSERT_STRNE("0", toString(vote).c_str());

    int producedblocks = delegatesZero["producedblocks"];
    ASSERT_NE(0, producedblocks);

    int missedblocks = delegatesZero["missedblocks"];
    ASSERT_NE(0, missedblocks);

    int rate = delegatesZero["rate"];
    ASSERT_NE(0, rate);

    double approval = delegatesZero["approval"];
    ASSERT_NE(0.00, approval);

    double productivity = delegatesZero["productivity"];
    ASSERT_NE(0.00, productivity);
}

TEST(api, test_one_accounts_delegates_fee)
{
    Ark::Client arkClient(DEVNET);

    const auto delegatesFeeResponse = arkClient.accountDelegatesFee(darkAddress);

    DynamicJsonBuffer jsonBuffer(delegatesFeeResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegatesFeeResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const auto delegatesFee = root["fee"].as<unsigned long long>();
    ASSERT_EQ("2500000000", toString(delegatesFee));
}

TEST(api, test_one_accounts_public_key)
{
    Ark::Client arkClient(DEVNET);

    const auto pubkeyResponse = arkClient.accountPublickey(darkAddress);

    DynamicJsonBuffer jsonBuffer(pubkeyResponse.size());
    JsonObject& root = jsonBuffer.parseObject(pubkeyResponse);

    const char* publicKey = root["publicKey"];
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey);
}

#endif
