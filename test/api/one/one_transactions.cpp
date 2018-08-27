

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_ONE_API

)
namespace
{
    const auto transactionID = "4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e";
}

TEST(api, test_transactions_transaction)
{
    Ark::Client arkClient(DEVNET);

    const auto transactionResponse = arkClient.transaction(transactionID);

    auto parser = Ark::Test::Utils::JSONParser(transactionResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_NE(1, success);

    const auto id = parser->getRoot()["transaction"]["id"].as<const char*>();
    ASSERT_STREQ("4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e", id);
    
    const auto blockid = parser->getRoot()["transaction"]["blockid"].as<const char*>();
    ASSERT_STREQ("6571939080722822408", blockid);
    
    const auto height = parser->getRoot()["transaction"]["height"].as<unsigned long long>();
    ASSERT_STREQ("1696504", toString(height).c_str());
    
    const auto type = parser->getRoot()["transaction"]["type"].as<int>();
    ASSERT_EQ(0, type);
    
    const auto timestamp = parser->getRoot()["transaction"]["timestamp"].as<int>();
    ASSERT_EQ(19637685, timestamp);
    
    const auto amount = parser->getRoot()["transaction"]["amount"].as<int>();
    ASSERT_EQ(149, amount);
    
    const auto fee = parser->getRoot()["transaction"]["fee"].as<unsigned long long>();
    ASSERT_STREQ("10000000", toString(fee).c_str());
    
    const auto vendorField = parser->getRoot()["transaction"]["vendorField"].as<const char*>();
    ASSERT_STREQ("1Ark-GOLang is saying whoop whooop", vendorField);
    
    const auto senderId = parser->getRoot()["transaction"]["senderId"].as<const char*>();
    ASSERT_STREQ("DPJBH7wfE1msZMVDQLeJUPi31fJZodJCkU", senderId);
    
    const auto recipientId = parser->getRoot()["transaction"]["recipientId"].as<const char*>();
    ASSERT_STREQ("DFTzLwEHKKn3VGce6vZSueEmoPWpEZswhB", recipientId);
    
    const auto senderPublicKey = parser->getRoot()["transaction"]["senderPublicKey"].as<const char*>();
    ASSERT_STREQ("03a151b47a5779949a47dd9c17e05c832304721a242b535f36528cd7e547dac439", senderPublicKey);

    const auto signature = parser->getRoot()["transaction"]["signature"].as<const char*>();
    ASSERT_STREQ("3045022100dc9590c6c6fce66a523481f13237d95518056387076de9a9534cb4a039fbede90220322e7f17b227f8fe9401460980b7b3c1baacf076b9020620ec5c4388673e7e12", signature);

    const auto confirmations = parser->getRoot()["transaction"]["confirmations"].as<int>();
    ASSERT_NE(0, confirmations);
}

TEST(api, test_transactions_transactions)
{
    Ark::Client arkClient(DEVNET);

    const auto transactionsResponse = arkClient.transactions();

    auto parser = Ark::Test::Utils::JSONParser(transactionsResponse);

    const auto success = parser->getRoot()["success"].as<>();
    ASSERT_STREQ("true", success.c_str());

    for (int i = 0; i < 10; i++)
    {
        const auto id = parser->getRoot()["transactions"][i]["id"].as<const char*>();
        ASSERT_STRNE("", id);

        const auto blockid = parser->getRoot()["transactions"][i]["blockid"].as<const char*>();
        ASSERT_STRNE("", blockid);

        const auto type = parser->getRoot()["transactions"][i]["type"].as<int>();
        ASSERT_STRNE("", toString(type).c_str());

        const auto timestamp = parser->getRoot()["transactions"][i]["timestamp")].as<int>();
        ASSERT_STRNE("", toString(timestamp));

        const auto amount = parser->getRoot()["transactions"][i]["amount"].as<unsigned long long>();
        ASSERT_STRNE("", toString(amount).c_str());

        const auto fee = parser->getRoot()["transactions"][i]["fee"].as<unsigned long long>();
        ASSERT_NE("0", toString(fee).c_str());

        const auto vendorField = parser->getRoot()["transactions"][i]["vendorField"].as<const char*>();
        ASSERT_STRNE("", vendorField);

        const auto senderId = parser->getRoot()["transactions"][i]["senderId"].as<const char*>();
        ASSERT_STRNE("", senderId);

        const auto recipientId = parser->getRoot()["transactions"][i]["recipientId"].as<const char*>();
        ASSERT_STRNE("", recipientId);

        const auto senderPublicKey = parser->getRoot()["transactions"][i]["senderPublicKey"].as<const char*>();
        ASSERT_STRNE("", senderPublicKey);

        const auto signature = parser->getRoot()["transactions"][i]["signature"].as<const char*>();
        ASSERT_STRNE("", signature);

        const auto confirmations = parser->getRoot()["transactions"][i]["confirmations"].as<int>();
        ASSERT_NE(0, confirmations);
    };
}

#endif
