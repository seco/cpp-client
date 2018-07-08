

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

TEST(api, test_peers_peer)
{
	ARK::Client arkClient(DEVNET);

    const auto peerResponse = arkClient.peer("167.114.29.54", 4002);
	auto parser = ARK::Test::Utils::makeJSONString(peerResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto ip = parser->valueIn("peer", "ip");
	ASSERT_STREQ("167.114.29.54", ip.c_str());

    const auto peer = parser->valueIn("peer", "port");
	ASSERT_STREQ("4002", peer.c_str()); // actual value 4002 (int).

    const auto version = parser->valueIn("peer", "version");
	ASSERT_STREQ("1.3.0", version.c_str());

    const auto errors = parser->valueIn("peer", "errors");
	ASSERT_STREQ("0", errors.c_str()); // actual value 0 (int).
	ASSERT_STRNE("", errors.c_str());

    const auto os = parser->valueIn("peer", "os");
	ASSERT_STREQ("linux4.4.0-79-generic", os.c_str());

    const auto height = parser->valueIn("peer", "height");
	ASSERT_STRNE("0", height.c_str());
	ASSERT_STRNE("", height.c_str());

    const auto status = parser->valueIn("peer", "status");
	ASSERT_STREQ("OK", status.c_str());

    const auto delay = parser->valueIn("peer", "delay");
	ASSERT_STRNE("0", delay.c_str()); // actual value is (int).
	ASSERT_STRNE("", delay.c_str());
}

TEST(api, test_peers_peers)
{
	ARK::Client arkClient(DEVNET);

	const auto peersResponse = arkClient.peers();
	auto parser = ARK::Test::Utils::makeJSONString(peersResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    for (int i = 0; i < 20; i++)
	{
        const auto ip = parser->subarrayValueIn("peers", i, "ip");
	    ASSERT_STRNE("", ip.c_str());

        const auto port = parser->subarrayValueIn("peers", i, "port");
	    ASSERT_STREQ("4002", port.c_str()); // actual value 4002 (int).

        const auto version = parser->subarrayValueIn("peers", i, "version");
	    ASSERT_STRNE("", version.c_str());

        const auto errors = parser->subarrayValueIn("peers", i, "errors");
        // ASSERT_STREQ("0", errors.c_str()); // actual value 0 (int). (1-peer: error `12`).
        ASSERT_STRNE("", errors.c_str());

        const auto os = parser->subarrayValueIn("peers", i, "os");
        ASSERT_STRNE("", os.c_str());

        const auto height = parser->subarrayValueIn("peers", i, "height");
        ASSERT_STRNE("0", os.c_str()); // actual value is (int).
        ASSERT_STRNE("", os.c_str());

        const auto status = parser->subarrayValueIn("peers", i, "status");
	    ASSERT_STREQ("OK", status.c_str());

        const auto delay = parser->subarrayValueIn("peers", i, "delay");
        ASSERT_STRNE("0", delay.c_str()); // actual value is (int).
        ASSERT_STRNE("", delay.c_str());
	};
}

TEST(api, test_peers_version)
{
	ARK::Client arkClient(DEVNET);

	const auto versionResponse = arkClient.peerVersion();
	auto parser = ARK::Test::Utils::makeJSONString(versionResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

    const auto version = parser->valueFor("version");
	ASSERT_STREQ("1.3.0", version.c_str());

    const auto build = parser->valueFor("build");
	ASSERT_STREQ("", build.c_str());
}
