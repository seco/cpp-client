

#include "gtest/gtest.h"
#include "arkClient.h"

#ifdef USE_IOT
	#include "utils/json/json.h"
#else
	#include "test/utils/json/json.h"
#endif

TEST(api, test_blocks_block)
{
	ARK::Client arkClient(DEVNET);

	const auto blockResponse = arkClient.block("4367122150875693402");
    auto parser = ARK::Test::Utils::makeJSONString(blockResponse);

    const auto id = parser->valueIn("block", "id");
	ASSERT_STREQ("4367122150875693402", id.c_str());

    const auto version = parser->valueIn("block", "version");
	ASSERT_STREQ("0", version.c_str()); // actual value is 0 (int).

    const auto timestamp = parser->valueIn("block", "timestamp");
	ASSERT_STREQ("25271824", timestamp.c_str());

    const auto height = parser->valueIn("block", "height");
	ASSERT_STREQ("2287265", height.c_str());

    const auto previousBlock = parser->valueIn("block", "previousBlock");
	ASSERT_STREQ("17021413347323836951", previousBlock.c_str());

    const auto numberOfTransactions = parser->valueIn("block", "numberOfTransactions");
	ASSERT_STREQ("0", numberOfTransactions.c_str());

    const auto totalAmount = parser->valueIn("block", "totalAmount");
	ASSERT_STREQ("0", totalAmount.c_str());

    const auto totalFee = parser->valueIn("block", "totalFee");
	ASSERT_STREQ("0", totalFee.c_str());

    const auto reward = parser->valueIn("block", "reward");
	ASSERT_STREQ("200000000", reward.c_str());

    const auto payloadLength = parser->valueIn("block", "payloadLength");
	ASSERT_STREQ("0", payloadLength.c_str());

    const auto payloadHash = parser->valueIn("block", "payloadHash");
	ASSERT_STREQ("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855", payloadHash.c_str());

    const auto generatorPublicKey = parser->valueIn("block", "generatorPublicKey");
	ASSERT_STREQ("02a9a0ac34a94f9d27fd9b4b56eb3c565a9a3f61e660f269775fb456f7f3301586", generatorPublicKey.c_str());

    const auto generatorId = parser->valueIn("block", "generatorId");
	ASSERT_STREQ("D5PXQVeJmchVrZFHL7cALZK8mWWzjCaVfz", generatorId.c_str());

    const auto blockSignature = parser->valueIn("block", "blockSignature");
	ASSERT_STREQ("3045022100954a3726e3592d74e6005841ebf9eaef576a40291881ba0b3739da325b75fcbf022023ff247d11a1238052b48f01930f04380c501309f01ae0dbc6b6cf637c16f3b0", blockSignature.c_str());

    const auto confirmations = parser->valueIn("block", "confirmations");
	ASSERT_STRNE("0", confirmations.c_str());
	ASSERT_STRNE("", confirmations.c_str());

    const auto totalForged = parser->valueIn("block", "totalForged");
	ASSERT_STREQ("200000000", totalForged.c_str());
}

TEST(api, test_blocks_blocks)
{
	ARK::Client arkClient(DEVNET);

	const auto blocksResponse = arkClient.blocks();
    auto parser = ARK::Test::Utils::makeJSONString(blocksResponse);

	for (int i = 0; i < 20; i++) // Full-list too large for MCU; limit to last 20 blocks.
	{
        const auto version = parser->subarrayValueIn("blocks", i, "version");
		ASSERT_STREQ("0", version.c_str());
	}
}

TEST(api, test_blocks_epoch)
{
	ARK::Client arkClient(DEVNET);

    const auto epochResponse = 	arkClient.blockEpoch();
    auto parser = ARK::Test::Utils::makeJSONString(epochResponse);

    const auto epoch = parser->valueFor("epoch");
	ASSERT_STREQ("2017-03-21T13:00:00.000Z", epoch.c_str());
}

TEST(api, test_blocks_fee)
{
	ARK::Client arkClient(DEVNET);

	const auto blockFeeResponse = arkClient.blockFee();
    auto parser = ARK::Test::Utils::makeJSONString(blockFeeResponse);

    const auto blockFee = parser->valueFor("fee");
	ASSERT_STREQ("10000000", blockFee.c_str());
}

TEST(api, test_blocks_fees)
{
	ARK::Client arkClient(DEVNET);

	const auto blockFeesResponse = arkClient.blockFees();
    auto parser = ARK::Test::Utils::makeJSONString(blockFeesResponse);

    const auto send = parser->valueIn("fees", "send");
	ASSERT_STREQ("10000000", send.c_str());

	const auto vote = parser->valueIn("fees", "vote");
	ASSERT_STREQ("100000000", vote.c_str());

	const auto secondsignature = parser->valueIn("fees", "secondsignature");
	ASSERT_STREQ("500000000", secondsignature.c_str());

    const auto delegate = parser->valueIn("fees", "delegate");
	ASSERT_STREQ("2500000000", delegate.c_str());

    const auto multisignature = parser->valueIn("fees", "multisignature");
	ASSERT_STREQ("500000000", multisignature.c_str());
}

TEST(api, test_blocks_height)
{
	ARK::Client arkClient(DEVNET);

	const auto blockHeightResponse = arkClient.blockHeight();
    auto parser = ARK::Test::Utils::makeJSONString(blockHeightResponse);

    const auto height = parser->valueFor("height");
	ASSERT_STRNE("0", height.c_str());
	ASSERT_STRNE("", height.c_str());

    const auto id = parser->valueFor("id");
	ASSERT_STRNE("0", id.c_str());
	ASSERT_STRNE("", id.c_str());
}

TEST(api, test_blocks_milestone)
{
	ARK::Client arkClient(DEVNET);

	const auto blockMilestoneResponse = arkClient.blockMilestone();
    auto parser = ARK::Test::Utils::makeJSONString(blockMilestoneResponse);

    const auto milestone = parser->valueFor("milestone");
	ASSERT_STREQ("0", milestone.c_str());
	ASSERT_STRNE("", milestone.c_str());
}

TEST(api, test_blocks_nethash)
{
	ARK::Client arkClient(DEVNET);

	const auto nethashResponse = arkClient.blockNethash();
    auto parser = ARK::Test::Utils::makeJSONString(nethashResponse);

    const auto nethash = parser->valueFor("nethash");
	ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", nethash.c_str());
}


TEST(api, test_blocks_reward)
{
	ARK::Client arkClient(DEVNET);

	const auto blockRewardResponse = arkClient.blockReward();
    auto parser = ARK::Test::Utils::makeJSONString(blockRewardResponse);

    const auto reward = parser->valueFor("reward");
	ASSERT_STREQ("200000000", reward.c_str());
}

TEST(api, test_blocks_status)
{
	ARK::Client arkClient(DEVNET);	

	const auto blockStatusResponse = arkClient.blockStatus();
    auto parser = ARK::Test::Utils::makeJSONString(blockStatusResponse);

    const auto epoch = parser->valueFor("epoch");
	ASSERT_STREQ("2017-03-21T13:00:00.000Z", epoch.c_str());

    const auto height = parser->valueFor("height");
	ASSERT_STRNE("0", height.c_str());
	ASSERT_STRNE("", height.c_str());

    const auto fee = parser->valueFor("fee");
	ASSERT_STREQ("10000000", fee.c_str());
	ASSERT_STRNE("", fee.c_str());

    const auto milestone = parser->valueFor("milestone");
	ASSERT_STREQ("0", milestone.c_str());
	ASSERT_STRNE("", milestone.c_str());

    const auto nethash = parser->valueFor("nethash");
	ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", nethash.c_str());
	
    const auto reward = parser->valueFor("reward");
	ASSERT_STREQ("200000000", reward.c_str());
	ASSERT_STRNE("", reward.c_str());

    const auto supply = parser->valueFor("supply");
	ASSERT_STRNE("00", supply.c_str());
	ASSERT_STRNE("", supply.c_str());
}

TEST(api, test_blocks_supply)
{
	ARK::Client arkClient(DEVNET);

	const auto blockSupplyResponse = arkClient.blockSupply();
    auto parser = ARK::Test::Utils::makeJSONString(blockSupplyResponse);

    const auto supply = parser->valueFor("supply");
	// ASSERT_STREQ("12962158800000000", supply.c_str());
	ASSERT_STRNE("0", supply.c_str());
	ASSERT_STRNE("", supply.c_str());
}
