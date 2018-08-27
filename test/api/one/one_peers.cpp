

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_ONE_API

TEST(api, test_one_peers_peer)
{
    Ark::Client arkClient(DEVNET);

    const auto peerResponse = arkClient.peer("167.114.29.54", 4002);

    auto parser = Ark::Test::Utils::ParseJSON(peerResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto ip = parser->getRoot()["peer"]["ip"].as<const char*>();
    ASSERT_STREQ("167.114.29.54", ip);

    const auto peer = parser->getRoot()["peer"]["port"].as<int>();
    ASSERT_EQ(4002, peer);

    const auto version = parser->getRoot()["peer"]["version"].as<const char*>();
    // ASSERT_STREQ("1.1.1", version);
    ASSERT_STREQ("2.0.0", version);

    const auto errors = parser->getRoot()["peer"]["errors"].as<int>();
    ASSERT_EQ(0, errors);

    const auto os = parser->getRoot()["peer"]["os"].as<const char*>();
    ASSERT_STREQ("linux4.4.0-79-generic", os);

    const auto height = parser->getRoot()["peer"]["height"].as<int>();
    ASSERT_NE(0, height);

    const auto status = parser->getRoot()["peer"]["status"].as<const char*>();
    ASSERT_STREQ("OK", status);

    const auto delay = parser->getRoot()["peer"]["delay"].as<int>();
    ASSERT_NE(0, delay);
}

TEST(api, test_one_peers_peers)
{
    Ark::Client arkClient(DEVNET);

    const auto peersResponse = arkClient.peers();

    auto parser = Ark::Test::Utils::ParseJSON(peersResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    for (int i = 0; i < 20; i++)
    {
        const auto ip = parser->getRoot()["peers"][i]["ip"].as<const char*>();
        ASSERT_STRNE("", ip);

        const auto port = parser->getRoot()["peers"][i]["port"].as<int>();
        ASSERT_EQ(4002, port); // actual value 4002 (int).

        const auto version = parser->getRoot()["peers"][i]["version"].as<int>();
        ASSERT_STRNE("", toString(version).c_str());

        const auto errors = parser->getRoot()["peers"][i]["errors"].as<int>();
        ASSERT_STRNE("", toString(errors).c_str());

        const auto os = parser->getRoot()["peers"][i]["os"].as<const char*>();
        ASSERT_STRNE("", os);

        const auto height = parser->getRoot()["peers"][i]["height"].as<int>();
        ASSERT_NE(0, os);

        const auto status = parser->getRoot()["peers"][i]["status"].as<const char*>();
        ASSERT_STREQ("OK", status);

        const auto delay = parser->getRoot()["peers"][i]["delay"].as<int>();
        ASSERT_NE(0, delay); // actual value is (int).
    };
}

TEST(api, test_one_peers_version)
{
    Ark::Client arkClient(DEVNET);

    const auto versionResponse = arkClient.peerVersion();

    auto parser = Ark::Test::Utils::ParseJSON(versionResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto version = parser->getRoot()["version"].as<const char*>();
    // ASSERT_STREQ("1.3.0", version.c_str());
    // ASSERT_STREQ("2.0.0", version);

    const auto build = parser->getRoot()["build"].as<const char*>();
    ASSERT_STREQ("", build);
}

#endif
