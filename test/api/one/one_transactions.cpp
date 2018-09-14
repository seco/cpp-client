

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

#ifdef HAS_ONE_API

namespace
{
    const auto transactionID = "4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e";
}

TEST(api, test_transactions_transaction)
{
    Ark::Client arkClient(DEVNET);

    const auto transactionResponse = arkClient.transaction(transactionID);

    DynamicJsonBuffer jsonBuffer(transactionResponse.size());
    JsonObject& root = jsonBuffer.parseObject(transactionResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);


    JsonObject& transaction = root["transaction"];

    const char* id = transaction["id"];
    ASSERT_STREQ("4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e", id);
    
    const char* blockid = transaction["blockid"];
    ASSERT_STREQ("6571939080722822408", blockid);
    
    int height = transaction["height"];
    ASSERT_STREQ("1696504", toString(height).c_str());
    
    int type = transaction["type"];
    ASSERT_EQ(0, type);
    
    int timestamp = transaction["timestamp"];
    ASSERT_EQ(19637685, timestamp);
    
    int amount = transaction["amount"];
    ASSERT_EQ(149, amount);
    
    const auto fee = transaction["fee"].as<unsigned long long>();
    ASSERT_STREQ("10000000", toString(fee).c_str());
    
    const char* vendorField = transaction["vendorField"];
    ASSERT_STREQ("1Ark-GOLang is saying whoop whooop", vendorField);
    
    const char* senderId = transaction["senderId"];
    ASSERT_STREQ("DPJBH7wfE1msZMVDQLeJUPi31fJZodJCkU", senderId);
    
    const char* recipientId = transaction["recipientId"];
    ASSERT_STREQ("DFTzLwEHKKn3VGce6vZSueEmoPWpEZswhB", recipientId);
    
    const char* senderPublicKey = transaction["senderPublicKey"];
    ASSERT_STREQ("03a151b47a5779949a47dd9c17e05c832304721a242b535f36528cd7e547dac439", senderPublicKey);

    const char* signature = transaction["signature"];
    ASSERT_STREQ("3045022100dc9590c6c6fce66a523481f13237d95518056387076de9a9534cb4a039fbede90220322e7f17b227f8fe9401460980b7b3c1baacf076b9020620ec5c4388673e7e12", signature);

    int confirmations = transaction["confirmations"];
    ASSERT_TRUE(confirmations >= 0);
}

TEST(api, test_transactions_transactions)
{
    Ark::Client arkClient(DEVNET);

    const auto transactionsResponse = arkClient.transactions();

    DynamicJsonBuffer jsonBuffer(transactionsResponse.size());
    JsonObject& root = jsonBuffer.parseObject(transactionsResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    JsonArray& transactions = root["transactions"];

    for (int i = 0; i < 10; i++)
    {
        const char* id = transactions[i]["id"];
        ASSERT_STRNE("", id);

        const char* blockid = transactions[i]["blockid"];
        ASSERT_STRNE("", blockid);

        int type = transactions[i]["type"];
        ASSERT_TRUE(type >= 0);

        int timestamp = transactions[i]["timestamp"];
        ASSERT_TRUE(timestamp >= 0);

        const auto amount = transactions[i]["amount"].as<unsigned long long>();
        ASSERT_STRNE("", toString(amount).c_str());

        const auto fee = transactions[i]["fee"].as<unsigned long long>();
        ASSERT_STRNE("0", toString(fee).c_str());

        const char* vendorField = transactions[i]["vendorField"];
        ASSERT_STRNE("", vendorField);

        const char* senderId = transactions[i]["senderId"];
        ASSERT_STRNE("", senderId);

        const char* recipientId = transactions[i]["recipientId"];
        ASSERT_STRNE("", recipientId);

        const char* senderPublicKey = transactions[i]["senderPublicKey"];
        ASSERT_STRNE("", senderPublicKey);

        const char* signature = transactions[i]["signature"];
        ASSERT_STRNE("", signature);

        int confirmations = transactions[i]["confirmations"];
        ASSERT_NE(0, confirmations);
    };
}

#endif
