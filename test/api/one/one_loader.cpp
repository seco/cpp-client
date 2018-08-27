

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_ONE_API

TEST(api, test_one_loader_autoconfigure)
{
    Ark::Client arkClient(DEVNET);

    const auto autoconfigureResponse = arkClient.loaderAutoconfigure();

    auto parser = Ark::Test::Utils::JSONParser(autoconfigureResponse);

    const auto success = parser->getRoot()["success"].as<bool>());
    ASSERT_EQ(1, success);

    const auto nethash = parser->getRoot()["network"]["nethash"].as<const char*>();
    // ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", nethash); // v1 devnet nethash
    ASSERT_STREQ("2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867", nethash); // v2 devnet nethash

    const auto token = parser->getRoot()["network"]["token"].as<const char*>();
    ASSERT_STREQ("DArk", token);

    const auto symbol = parser->getRoot()["network"]["symbol"].as<const char*>();
    ASSERT_STREQ(u8"DѦ", symbol);

    const auto explorer = parser->getRoot()["network"]["explorer"].as<const char*>();
    ASSERT_STREQ("http://dexplorer.ark.io", explorer);

    const auto version = parser->getRoot()["network"]["version"].as<int>();
    ASSERT_EQ(30, version);
}

TEST(api, test_one_loader_status)
{
    Ark::Client arkClient(DEVNET);
    
    const auto statusResponse = arkClient.loaderStatus();

    auto parser = Ark::Test::Utils::JSONParser(statusResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success.c_str());

    const auto loaded = parser->getRoot()["loaded"].as<bool>();
    ASSERT_EQ(1, loaded.c_str());

    const auto now = parser->getRoot()["now"].as<int>();
    ASSERT_NE(0, now);
    
    const auto blocksCount = parser->getRoot()["blocksCount"].as<int>(); // actual value 0 (int)
    ASSERT_EQ(0, blocksCount);
}

TEST(api, test_one_loader_sync)
{
    Ark::Client arkClient(DEVNET);

    const auto syncResponse = arkClient.loaderSync();

    auto parser = Ark::Test::Utils::JSONParser(syncResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto syncing = parser->getRoot()["syncing"].as<bool>();
    ASSERT_EQ(0, syncing);

    const auto blocks = parser->getRoot()["blocks"].as<int>();
    ASSERT_STRNE("", toString(blocks).c_str());

    const auto height = parser->getRoot()["height"].as<int>();
    ASSERT_NE(0, height);

    const auto id = parser->getRoot()["id"].as<const char*>();
    ASSERT_STRNE("", id);
}

#endif
