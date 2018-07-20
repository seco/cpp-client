

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#if defined(HAS_ONE_API) && !defined(HAS_TWO_API)

namespace
{
	const auto transactionID = "4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e";
}

TEST(api, test_transactions_transaction)
{
    ARK::Client arkClient(DEVNET);

    const auto transactionResponse = arkClient.transaction(transactionID);
	auto parser = ARK::Test::Utils::makeJSONString(transactionResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto id = parser->valueIn("transaction", "id");
	ASSERT_STREQ("4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e", id.c_str());
	
    const auto blockid = parser->valueIn("transaction", "blockid");
    ASSERT_STREQ("6571939080722822408", blockid.c_str());
	
    const auto height = parser->valueIn("transaction", "height");
    ASSERT_STREQ("1696504", height.c_str());
	
    const auto type = parser->valueIn("transaction", "type");
    ASSERT_STREQ("0", type.c_str()); // actual value 0 (int).
    ASSERT_STRNE("", type.c_str());
	
    const auto timestamp = parser->valueIn("transaction", "timestamp");
    ASSERT_STREQ("19637685", timestamp.c_str());
	
    const auto amount = parser->valueIn("transaction", "amount");
    ASSERT_STREQ("149", amount.c_str()); // actual value 149 (int).
    ASSERT_STRNE("", amount.c_str());
	
    const auto fee = parser->valueIn("transaction", "fee");
    ASSERT_STREQ("10000000", fee.c_str());
	
    const auto vendorField = parser->valueIn("transaction", "vendorField");
    ASSERT_STREQ("1ARK-GOLang is saying whoop whooop", vendorField.c_str());
	
    const auto senderId = parser->valueIn("transaction", "senderId");
    ASSERT_STREQ("DPJBH7wfE1msZMVDQLeJUPi31fJZodJCkU", senderId.c_str());
	
    const auto recipientId = parser->valueIn("transaction", "recipientId");
    ASSERT_STREQ("DFTzLwEHKKn3VGce6vZSueEmoPWpEZswhB", recipientId.c_str());
	
    const auto senderPublicKey = parser->valueIn("transaction", "senderPublicKey");
    ASSERT_STREQ("03a151b47a5779949a47dd9c17e05c832304721a242b535f36528cd7e547dac439", senderPublicKey.c_str() );

    const auto signature = parser->valueIn("transaction", "signature");
    ASSERT_STREQ("3045022100dc9590c6c6fce66a523481f13237d95518056387076de9a9534cb4a039fbede90220322e7f17b227f8fe9401460980b7b3c1baacf076b9020620ec5c4388673e7e12", signature.c_str());

    const auto confirmations = parser->valueIn("transaction", "confirmations");
    ASSERT_STRNE("0", confirmations.c_str()); // actual value is (int).
    ASSERT_STRNE("", confirmations.c_str());
}

TEST(api, test_transactions_transactions)
{
    ARK::Client arkClient(DEVNET);

    const auto transactionsResponse = arkClient.transactions();
	auto parser = ARK::Test::Utils::makeJSONString(transactionsResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

	for (int i = 0; i < 10; i++)
	{
		const auto id = parser->subarrayValueIn("transactions", i, "id");
        ASSERT_STRNE("", id.c_str());

		const auto blockid = parser->subarrayValueIn("transactions", i, "blockid");
        ASSERT_STRNE("", blockid.c_str());

		// const auto height = parser->subarrayValueIn("transactions", i, "height");
        // ASSERT_STRNE("0", height.c_str());
        // ASSERT_STRNE("", height.c_str());

		const auto type = parser->subarrayValueIn("transactions", i, "type");
        ASSERT_STRNE("", type.c_str());

		const auto timestamp = parser->subarrayValueIn("transactions", i, "timestamp");
        ASSERT_STRNE("", timestamp.c_str());

		const auto amount = parser->subarrayValueIn("transactions", i, "amount");
        ASSERT_STRNE("", amount.c_str());

		const auto fee = parser->subarrayValueIn("transactions", i, "fee");
        ASSERT_STRNE("0", fee.c_str());
        ASSERT_STRNE("", fee.c_str());

		const auto vendorField = parser->subarrayValueIn("transactions", i, "vendorField");
        ASSERT_STRNE("", vendorField.c_str());

		const auto senderId = parser->subarrayValueIn("transactions", i, "senderId");
        ASSERT_STRNE("", senderId.c_str());

		const auto recipientId = parser->subarrayValueIn("transactions", i, "recipientId");
        ASSERT_STRNE("", recipientId.c_str());

		const auto senderPublicKey = parser->subarrayValueIn("transactions", i, "senderPublicKey");
        ASSERT_STRNE("", senderPublicKey.c_str() );

		const auto signature = parser->subarrayValueIn("transactions", i, "signature");
        ASSERT_STRNE("", signature.c_str());

		const auto confirmations = parser->subarrayValueIn("transactions", i, "confirmations");
        ASSERT_STRNE("0", confirmations.c_str()); // actual value is (int).
        ASSERT_STRNE("", confirmations.c_str());
	};
}

#endif
