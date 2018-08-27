

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
    auto parser = Ark::Test::Utils::makeJSONString(accountResponse);

    const auto success = parser->valueFor("success");
    ASSERT_STREQ("true", success.c_str());

    const auto address = parser->valueIn("account", "address");
    ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address.c_str());
    
    const auto unconfirmedBalance = parser->valueIn("account", "unconfirmedBalance");
    ASSERT_STRNE("", unconfirmedBalance.c_str());

    const auto balance = parser->valueIn("account", "balance");
    ASSERT_STRNE("", balance.c_str());

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
    Ark::Client arkClient(DEVNET);

    const auto accountBalanceResponse = arkClient.accountBalance(darkAddress);
    auto parser = Ark::Test::Utils::makeJSONString(accountBalanceResponse);

    const auto success = parser->valueFor("success");
    ASSERT_STREQ("true", success.c_str());

    const auto balance = parser->valueFor("balance");
    ASSERT_STRNE("", balance.c_str());

    const auto unconfirmedBalance = parser->valueFor("unconfirmedBalance");
    ASSERT_STRNE("0", unconfirmedBalance.c_str());
    ASSERT_STRNE("", unconfirmedBalance.c_str());
}

TEST(api, test_one_accounts_delegates)
{
    Ark::Client arkClient(DEVNET);

    const auto delegateResponse = arkClient.accountDelegates(darkAddress);
    auto parser = Ark::Test::Utils::makeJSONString(delegateResponse);

    const auto username = parser->subarrayValueIn("delegates", 0, "username");
    ASSERT_STREQ("sleepdeficit", username.c_str());
    
    const auto address = parser->subarrayValueIn("delegates", 0, "address");
    ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address.c_str());
    
    const auto publicKey = parser->subarrayValueIn("delegates", 0, "publicKey");
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey.c_str());

    const auto vote = parser->subarrayValueIn("delegates", 0, "vote");
    ASSERT_STRNE("", vote.c_str());

    const auto producedblocks = parser->subarrayValueIn("delegates", 0, "producedblocks");
    ASSERT_STRNE("0", producedblocks.c_str());
    ASSERT_STRNE("", producedblocks.c_str());

    const auto missedblocks = parser->subarrayValueIn("delegates", 0, "missedblocks");
    ASSERT_STRNE("0", missedblocks.c_str());
    ASSERT_STRNE("", missedblocks.c_str());

    const auto rate = parser->subarrayValueIn("delegates", 0, "rate");
    ASSERT_STRNE("0", rate.c_str());
    ASSERT_STRNE("", rate.c_str());

    const auto approval = parser->subarrayValueIn("delegates", 0, "approval");
    ASSERT_STRNE("0.0", approval.c_str());
    ASSERT_STRNE("", approval.c_str());

    const auto productivity = parser->subarrayValueIn("delegates", 0, "productivity");
    ASSERT_STRNE("0.0", productivity.c_str());
    ASSERT_STRNE("", productivity.c_str());
}

TEST(api, test_one_accounts_delegates_fee)
{
    Ark::Client arkClient(DEVNET);

    const auto delegatesFeeResponse = arkClient.accountDelegatesFee(darkAddress);
    auto parser = Ark::Test::Utils::makeJSONString(delegatesFeeResponse);

    const auto success = parser->valueFor("success");
    ASSERT_STREQ("true", success.c_str());

    const auto delegatesFee = parser->valueFor("fee");
    ASSERT_STREQ("2500000000", delegatesFee.c_str()); // actual value is 2500000000 (int).
}

TEST(api, test_one_accounts_public_key)
{
    Ark::Client arkClient(DEVNET);

    const auto pubkeyResponse = arkClient.accountPublickey(darkAddress);
    auto parser = Ark::Test::Utils::makeJSONString(pubkeyResponse);

    const auto publicKey = parser->valueFor("publicKey");
    ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey.c_str());
}

#endif
