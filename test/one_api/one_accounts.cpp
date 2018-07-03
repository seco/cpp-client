

#include "gtest/gtest.h"
#include "arkClient.h"

#ifdef USE_IOT
	#include "utils/json/json.h"
#else
	#include "test/utils/json/json.h"
#endif

namespace
{
	const auto darkAddress = "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA";
}

TEST(api, test_one_accounts_account)
{
	ARK::Client arkClient(DEVNET);

	const auto accountResponse = arkClient.account(darkAddress);
	auto parser = ARK::Test::Utils::makeJSONString(accountResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto address = parser->valueIn("account", "address");
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address.c_str());
	
	// parser->valueIn("account", "unconfirmedBalance").c_str()
	// parser->valueIn("account", "balance").c_str()

    const auto publicKey = parser->valueIn("account", "publicKey");
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey.c_str());
	
	const auto unconfirmedSignature = parser->valueIn("account", "unconfirmedSignature");
	ASSERT_STREQ("1", unconfirmedSignature.c_str()); // actual value is 1 (int).

    const auto secondSignature = parser->valueIn("account", "secondSignature");
	ASSERT_STREQ("1", secondSignature.c_str()); // actual value is 1 (int).

	const auto secondPublicKey = parser->valueIn("account", "secondPublicKey");
	ASSERT_STREQ("03ad2a481719c80571061f0c941d57e91c928700d8dd132726edfc0bf9c4cb2869", secondPublicKey.c_str());
}

TEST(api, test_one_accounts_balance)
{
	ARK::Client arkClient(DEVNET);

	const auto accountBalanceResponse = arkClient.accountBalance(darkAddress);
	auto parser = ARK::Test::Utils::makeJSONString(accountBalanceResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto balance = parser->valueFor("balance");
	ASSERT_STREQ("7808415341862", balance.c_str());

    const auto unconfirmedBalance = parser->valueFor("unconfirmedBalance");
	ASSERT_STREQ("7808415341862", unconfirmedBalance.c_str());
}

TEST(api, test_one_accounts_delegates)
{
	ARK::Client arkClient(DEVNET);

	const auto delegateResponse = arkClient.accountDelegates(darkAddress);
	auto parser = ARK::Test::Utils::makeJSONString(delegateResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto username = parser->subarrayValueIn("delegates", 0, "username");
	ASSERT_STREQ("sleepdeficit", username.c_str());
	
	const auto address = parser->subarrayValueIn("delegates", 0, "address");
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address.c_str());
	
    const auto publicKey = parser->subarrayValueIn("delegates", 0, "publicKey");
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey.c_str());

	// parser->subarrayValueIn("delegates", 0, "vote").c_str(),
	// convert_to_int(parser->subarrayValueIn("delegates", 0, "producedblocks").c_str()),
	// convert_to_int(parser->subarrayValueIn("delegates", 0, "missedblocks").c_str()),
	// convert_to_int(parser->subarrayValueIn("delegates", 0, "rate").c_str()),
	// convert_to_float(parser->subarrayValueIn("delegates", 0, "approval").c_str()),
	// convert_to_float(parser->subarrayValueIn("delegates", 0, "productivity").c_str())
}

TEST(api, test_one_accounts_delegates_fee)
{
	ARK::Client arkClient(DEVNET);

	const auto delegatesFeeResponse = arkClient.accountDelegatesFee(darkAddress);
	auto parser = ARK::Test::Utils::makeJSONString(delegatesFeeResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto delegatesFee = parser->valueFor("fee");
	ASSERT_STREQ("2500000000", delegatesFee.c_str()); // actual value is 2500000000 (int).
}

TEST(api, test_one_accounts_public_key)
{
	ARK::Client arkClient(DEVNET);

	const auto pubkeyResponse = arkClient.accountPublickey(darkAddress);
	auto parser = ARK::Test::Utils::makeJSONString(pubkeyResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto publicKey = parser->valueFor("publicKey");
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey.c_str());
}
