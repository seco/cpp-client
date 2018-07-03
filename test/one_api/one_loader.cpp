

#include "gtest/gtest.h"
#include "arkClient.h"

#ifdef USE_IOT
	#include "utils/json/json.h"
#else
	#include "test/utils/json/json.h"
#endif

TEST(api, test_one_loader_autoconfigure)
{
	ARK::Client arkClient(DEVNET);

	const auto autoconfigureResponse = arkClient.loaderAutoconfigure();
	auto parser = ARK::Test::Utils::makeJSONString(autoconfigureResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto nethash = parser->valueIn("network", "nethash");
	ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", nethash.c_str());

    const auto token = parser->valueIn("network", "token");
	ASSERT_STREQ("DARK", token.c_str());

    const auto symbol = parser->valueIn("network", "symbol");
	ASSERT_STREQ(u8"DѦ", symbol.c_str());

    const auto explorer = parser->valueIn("network", "explorer");
	ASSERT_STREQ("http://dexplorer.ark.io", explorer.c_str());

    const auto version = parser->valueIn("network", "version");
	ASSERT_STREQ("30", version.c_str()); // actual value 30 (int).
}

TEST(api, test_one_loader_status)
{
	ARK::Client arkClient(DEVNET);
    
	const auto statusResponse = arkClient.loaderStatus();
	auto parser = ARK::Test::Utils::makeJSONString(statusResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto loaded = parser->valueFor("loaded");
	ASSERT_STREQ("false", loaded.c_str());

    const auto now = parser->valueFor("now"); // actual value 2338842 (int)
	ASSERT_STRNE("0", now.c_str());
	ASSERT_STRNE("", now.c_str());
    
    const auto blocksCount = parser->valueFor("blocksCount"); // actual value 0 (int)
	ASSERT_STREQ("0", blocksCount.c_str());
	ASSERT_STRNE("", blocksCount.c_str());
}

TEST(api, test_one_loader_sync)
{
    ARK::Client arkClient(DEVNET);
    
	const auto syncResponse = arkClient.loaderSync();
	auto parser = ARK::Test::Utils::makeJSONString(syncResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto syncing = parser->valueFor("syncing");
    ASSERT_STREQ("false", syncing.c_str());

    const auto blocks = parser->valueFor("blocks");
    ASSERT_STREQ("0", blocks.c_str());

    const auto height = parser->valueFor("height");
	ASSERT_STRNE("0", height.c_str());
	ASSERT_STRNE("", height.c_str());

    const auto id = parser->valueFor("id");
	ASSERT_STRNE("0", id.c_str());
	ASSERT_STRNE("", id.c_str());
}
