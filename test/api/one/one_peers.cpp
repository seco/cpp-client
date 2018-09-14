

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

#ifdef HAS_ONE_API

TEST(api, test_one_peers_peer)
{
    Ark::Client arkClient(DEVNET);

    const auto peerResponse = arkClient.peer("167.114.29.54", 4002);

    DynamicJsonBuffer jsonBuffer(peerResponse.size());
    JsonObject& root = jsonBuffer.parseObject(peerResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);


    JsonObject& peer = root["peer"];

    const char* ip = peer["ip"];
    ASSERT_STREQ("167.114.29.54", ip);

    int port = peer["port"];
    ASSERT_EQ(4002, port);

    const char* version = peer["version"];
    ASSERT_STRNE("", version);
    // ASSERT_STREQ("1.1.1", version);
    // ASSERT_STREQ("2.0.0", version);

    int errors = peer["errors"];
    ASSERT_EQ(0, errors);

    const char* os = peer["os"];
    ASSERT_STREQ("linux4.4.0-79-generic", os);

    int height = peer["height"];
    ASSERT_TRUE(height >= 0);

    const char* status = peer["status"];
    ASSERT_STREQ("OK", status);

    int delay = peer["delay"];
    ASSERT_NE(0, delay);
}

TEST(api, test_one_peers_peers)
{
    Ark::Client arkClient(DEVNET);

    const auto peersResponse = arkClient.peers();

    DynamicJsonBuffer jsonBuffer(peersResponse.size());
    JsonObject& root = jsonBuffer.parseObject(peersResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);


    JsonArray& peers = root["peers"];

    for (int i = 0; i < 20; i++)
    {
        const char* ip = peers[i]["ip"];
        ASSERT_STRNE("", ip);

        int port = peers[i]["port"];
        ASSERT_EQ(4002, port);

        int version = peers[i]["version"];
        ASSERT_STRNE("", toString(version).c_str());

        int errors = peers[i]["errors"];
        ASSERT_STRNE("", toString(errors).c_str());

        const char* os = peers[i]["os"];
        ASSERT_STRNE("", os);

        int height = peers[i]["height"];
        ASSERT_TRUE(height > 0);

        const char* status = peers[i]["status"];
        ASSERT_STREQ("OK", status);

        int delay = peers[i]["delay"];
        ASSERT_TRUE(delay >= 0);
    };
}

TEST(api, test_one_peers_version)
{
    Ark::Client arkClient(DEVNET);

    const auto versionResponse = arkClient.peerVersion();

    DynamicJsonBuffer jsonBuffer(versionResponse.size());
    JsonObject& root = jsonBuffer.parseObject(versionResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const char* version = root["version"];
    ASSERT_STRNE("", version);
    // ASSERT_STREQ("1.3.0", version);
    // ASSERT_STREQ("2.0.0", version);

    const char* build = root["build"];
    ASSERT_STRNE("", build);
}

#endif
