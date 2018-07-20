

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#if defined(HAS_ONE_API) && !defined(HAS_TWO_API)

namespace
{
	const auto darkPubkey = "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456";
}

TEST(api, test_one_delegates_fee)
{
	ARK::Client arkClient(DEVNET);

	const auto delegateFeeResponse = arkClient.delegateFee();
	auto parser = ARK::Test::Utils::makeJSONString(delegateFeeResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto delegateFee = parser->valueFor("fee");
	ASSERT_STREQ("2500000000", delegateFee.c_str()); // actual value 2500000000 (int).
}

TEST(api, test_one_delegates_forged_by_account)
{
	ARK::Client arkClient(DEVNET);

	const auto forgedByAccountResponse = arkClient.delegateForgedByAccount(darkPubkey);
	auto parser = ARK::Test::Utils::makeJSONString(forgedByAccountResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto fees = parser->valueFor("fees");
	ASSERT_STRNE("0", fees.c_str());
	ASSERT_STRNE("", fees.c_str());

    const auto rewards = parser->valueFor("rewards");
	ASSERT_STRNE("0", rewards.c_str());
	ASSERT_STRNE("", rewards.c_str());

    const auto forged = parser->valueFor("forged");
	ASSERT_STRNE("0", forged.c_str());
	ASSERT_STRNE("", forged.c_str());
}

TEST(api, test_one_delegates_next_forgers)
{
	ARK::Client arkClient(DEVNET);

	const auto nextForgersResponse = arkClient.delegateNextForgers();
	auto parser = ARK::Test::Utils::makeJSONString(nextForgersResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto currentBlock = parser->valueFor("currentBlock");
    ASSERT_STRNE("0", currentBlock.c_str());
	ASSERT_STRNE("", currentBlock.c_str());

    const auto currentSlot = parser->valueFor("currentSlot");
	ASSERT_STRNE("0", currentSlot.c_str());
	ASSERT_STRNE("", currentSlot.c_str());

    for (int i = 0; i < 10; ++i)
	{
        const auto delegateKey = parser->subvalueFor("delegates", i);
	    ASSERT_STRNE("", delegateKey.c_str());
	};
}

TEST(api, test_one_delegates_delegate_by_public_key)
{
	ARK::Client arkClient(DEVNET);

	auto delegateResponse = arkClient.delegate(darkPubkey);
	auto parser = ARK::Test::Utils::makeJSONString(delegateResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto username = parser->valueIn("delegate", "username");
	ASSERT_STREQ("sleepdeficit", username.c_str());

    const auto address = parser->valueIn("delegate", "address");
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address.c_str());

    const auto publicKey = parser->valueIn("delegate", "publicKey");
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey.c_str());
    
    const auto vote = parser->valueIn("delegate", "vote");
	ASSERT_STRNE("0", vote.c_str());
	ASSERT_STRNE("", vote.c_str());

    const auto producedblocks = parser->valueIn("delegate", "producedblocks");
	ASSERT_STRNE("0", producedblocks.c_str());
	ASSERT_STRNE("", producedblocks.c_str());

    const auto missedblocks = parser->valueIn("delegate", "missedblocks");
	ASSERT_STRNE("0", missedblocks.c_str());
	ASSERT_STRNE("", missedblocks.c_str());

    const auto rate = parser->valueIn("delegate", "rate");
	ASSERT_STRNE("0", rate.c_str());
	ASSERT_STRNE("", rate.c_str());

    const auto approval = parser->valueIn("delegate", "approval");
	ASSERT_STRNE("0.0", approval.c_str());
	ASSERT_STRNE("", approval.c_str());

    const auto productivity = parser->valueIn("delegate", "productivity");
	ASSERT_STRNE("0.0", productivity.c_str());
	ASSERT_STRNE("", productivity.c_str());
}

TEST(api, test_one_delegates_delegate_by_username)
{
	ARK::Client arkClient(DEVNET);

	const auto delegateResponse = arkClient.delegate("sleepdeficit");
	auto parser = ARK::Test::Utils::makeJSONString(delegateResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto username = parser->valueIn("delegate", "username");
	ASSERT_STREQ("sleepdeficit", username.c_str());

    const auto address = parser->valueIn("delegate", "address");
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address.c_str());

    const auto publicKey = parser->valueIn("delegate", "publicKey");
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey.c_str());
    
    const auto vote = parser->valueIn("delegate", "vote");
	ASSERT_STRNE("0", vote.c_str());
	ASSERT_STRNE("", vote.c_str());

    const auto producedblocks = parser->valueIn("delegate", "producedblocks");
	ASSERT_STRNE("0", producedblocks.c_str());
	ASSERT_STRNE("", producedblocks.c_str());

    const auto missedblocks = parser->valueIn("delegate", "missedblocks");
	ASSERT_STRNE("0", missedblocks.c_str());
	ASSERT_STRNE("", missedblocks.c_str());

    const auto rate = parser->valueIn("delegate", "rate");
	ASSERT_STRNE("0", rate.c_str());
	ASSERT_STRNE("", rate.c_str());

    const auto approval = parser->valueIn("delegate", "approval");
	ASSERT_STRNE("0.0", approval.c_str());
	ASSERT_STRNE("", approval.c_str());

    const auto productivity = parser->valueIn("delegate", "productivity");
	ASSERT_STRNE("0.0", productivity.c_str());
	ASSERT_STRNE("", productivity.c_str());
}

TEST(api, test_one_delegates_delegates)
{
	ARK::Client arkClient(DEVNET);

    const auto delegatesResponse = arkClient.delegates();
	auto parser = ARK::Test::Utils::makeJSONString(delegatesResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

	for (int i = 0; i < 20; i++) // Full-list too large for MCU; limit to top 20 delegates.
	{
        const auto username = parser->subarrayValueIn("delegates", i, "username");
        ASSERT_STRNE("", username.c_str());

        const auto address = parser->subarrayValueIn("delegates", i, "address");
        ASSERT_STRNE("", address.c_str());

        const auto publicKey = parser->subarrayValueIn("delegates", i, "publicKey");
        ASSERT_STRNE("", publicKey.c_str());
        
        const auto vote = parser->subarrayValueIn("delegates", i, "vote");
        ASSERT_STRNE("0", vote.c_str());
        ASSERT_STRNE("", vote.c_str());

        const auto producedblocks = parser->subarrayValueIn("delegates", i, "producedblocks");
        ASSERT_STRNE("0", producedblocks.c_str());
        ASSERT_STRNE("", producedblocks.c_str());

        const auto missedblocks = parser->subarrayValueIn("delegates", i, "missedblocks");
        // ASSERT_STRNE("0", missedblocks.c_str());
        ASSERT_STRNE("", missedblocks.c_str());

        const auto rate = parser->subarrayValueIn("delegates", i, "rate");
        ASSERT_STRNE("0", rate.c_str());
        ASSERT_STRNE("", rate.c_str());

        const auto approval = parser->subarrayValueIn("delegates", i, "approval");
        ASSERT_STRNE("0.0", approval.c_str());
        ASSERT_STRNE("", approval.c_str());

        const auto productivity = parser->subarrayValueIn("delegates", i, "productivity");
        ASSERT_STRNE("0.0", productivity.c_str());
        ASSERT_STRNE("", productivity.c_str());
	}
}

TEST(api, test_one_delegates_voters)
{
	ARK::Client arkClient(DEVNET);

	const auto votersResponse = arkClient.delegateVoters(darkPubkey);
	auto parser = ARK::Test::Utils::makeJSONString(votersResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto username0 = parser->subarrayValueIn("accounts", 0, "username");
	ASSERT_STREQ("io.pi.relay.ds3", username0.c_str());

	const auto address0 = parser->subarrayValueIn("accounts", 0, "address");
    ASSERT_STREQ("DS3jiY1uPToqfGKmmfsdFnBhMmsrQY47gd", address0.c_str());

	const auto publicKey0 = parser->subarrayValueIn("accounts", 0, "publicKey");
	ASSERT_STREQ("03c57e437203403c5438bdb93f34d46a708a5d23a63fa9fe44c5fed1fa458d0717", publicKey0.c_str());

    const auto balance0 = parser->subarrayValueIn("accounts", 0, "balance");
	ASSERT_STREQ("0", balance0.c_str());
	ASSERT_STRNE("", balance0.c_str());


	const auto username1 = parser->subarrayValueIn("accounts", 1, "username");
	ASSERT_STREQ("sleepdeficit", username1.c_str());

	const auto address1 = parser->subarrayValueIn("accounts", 1, "address");
    ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address1.c_str());

	const auto publicKey1 = parser->subarrayValueIn("accounts", 1, "publicKey");
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey1.c_str());

	const auto balance1 = parser->subarrayValueIn("accounts", 1, "balance");
	ASSERT_STREQ("0", balance0.c_str());
	ASSERT_STRNE("", balance0.c_str());
}

TEST(api, test_one_delegates_search)
{
	ARK::Client arkClient(DEVNET);

	const auto delegateResponse = arkClient.delegate("sleepdeficit");
	auto parser = ARK::Test::Utils::makeJSONString(delegateResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto username = parser->valueIn("delegate", "username");
	ASSERT_STREQ("sleepdeficit", username.c_str());

    const auto address = parser->valueIn("delegate", "address");
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address.c_str());

    const auto publicKey = parser->valueIn("delegate", "publicKey");
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", publicKey.c_str());
    
    const auto vote = parser->valueIn("delegate", "vote");
	ASSERT_STRNE("0", vote.c_str());
	ASSERT_STRNE("", vote.c_str());

    const auto producedblocks = parser->valueIn("delegate", "producedblocks");
	ASSERT_STRNE("0", producedblocks.c_str());
	ASSERT_STRNE("", producedblocks.c_str());

    const auto missedblocks = parser->valueIn("delegate", "missedblocks");
	ASSERT_STRNE("0", missedblocks.c_str());
	ASSERT_STRNE("", missedblocks.c_str());

    const auto rate = parser->valueIn("delegate", "rate");
	ASSERT_STRNE("0", rate.c_str());
	ASSERT_STRNE("", rate.c_str());

    const auto approval = parser->valueIn("delegate", "approval");
	ASSERT_STRNE("0.0", approval.c_str());
	ASSERT_STRNE("", approval.c_str());

    const auto productivity = parser->valueIn("delegate", "productivity");
	ASSERT_STRNE("0.0", productivity.c_str());
	ASSERT_STRNE("", productivity.c_str());
}

TEST(api, test_one_delegates_count)
{
	ARK::Client arkClient(DEVNET);

    const auto delegatesCountResponse = arkClient.delegatesCount();
	auto parser = ARK::Test::Utils::makeJSONString(delegatesCountResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto count = parser->valueFor("count");
	ASSERT_STRNE("0", count.c_str());
	ASSERT_STRNE("", count.c_str());
}

#endif
