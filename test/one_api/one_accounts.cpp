

#include "gtest/gtest.h"
#include "src/arkClient.h"
#include "nlohmann/json.hpp"

namespace
{
	const auto darkAddress = "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA";
}

TEST(api, test_accounts_account)
{
	ARK::Client arkClient(DEVNET);
	const auto accountResponse = arkClient.account(darkAddress);
	
    nlohmann::json parsedResponse = nlohmann::json::parse(accountResponse.c_str());
    const auto& account = parsedResponse["account"];

    const auto& address = account["address"];
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address.get<std::string>().c_str());
	
    const auto& publicKey = account["publicKey"];
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey.get<std::string>().c_str());
	
	const auto& unconfirmedSignature = account["unconfirmedSignature"];
	ASSERT_EQ(1, unconfirmedSignature);

    const auto& secondSignature = account["secondSignature"];
	ASSERT_EQ(1, secondSignature);

	const auto& secondPublicKey = account["secondPublicKey"];
	ASSERT_STREQ("03ad2a481719c80571061f0c941d57e91c928700d8dd132726edfc0bf9c4cb2869", secondPublicKey.get<std::string>().c_str());
}

TEST(api, test_accounts_balance)
{
	ARK::Client arkClient(DEVNET);
	const auto accountBalanceResponse = arkClient.accountBalance(darkAddress);
	nlohmann::json parsedResponse = nlohmann::json::parse(accountBalanceResponse.c_str());

    const auto& balance = parsedResponse["balance"];
	ASSERT_STREQ("7808415341862", balance.get<std::string>().c_str());

    const auto& unconfirmedBalance = parsedResponse["unconfirmedBalance"];
	ASSERT_STREQ("7808415341862", balance.get<std::string>().c_str());
}

TEST(api, test_accounts_delegates)
{
	ARK::Client arkClient(DEVNET);
	const auto delegateResponse = arkClient.accountDelegates(darkAddress);

	nlohmann::json parsedResponse = nlohmann::json::parse(delegateResponse.c_str());
    const auto& delegates = parsedResponse["delegates"];

    const auto& username = delegates[0]["username"];
	ASSERT_STREQ("sleepdeficit", username.get<std::string>().c_str());
	
	const auto& address = delegates[0]["address"];
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address.get<std::string>().c_str());
	
    const auto& publicKey = delegates[0]["publicKey"];
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey.get<std::string>().c_str());
}

TEST(api, test_accounts_delegates_fee)
{
	ARK::Client arkClient(DEVNET);

	const auto delegatesFeeResponse = arkClient.accountDelegatesFee(darkAddress);
	nlohmann::json parsedResponse = nlohmann::json::parse(delegatesFeeResponse.c_str());

    const auto& delegatesFee = parsedResponse["fee"];
	ASSERT_EQ(2500000000, delegatesFee);
}

TEST(api, test_accounts_public_key)
{
	ARK::Client arkClient(DEVNET);

	const auto pubkeyResponse = arkClient.accountPublickey(darkAddress);
	nlohmann::json parsedResponse = nlohmann::json::parse(pubkeyResponse.c_str());

    const auto& publicKey = parsedResponse["publicKey"];
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey.get<std::string>().c_str());
}
