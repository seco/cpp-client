

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_TWO_API

/* test_two_peers_peer
 * https://dexplorer.ark.io:8443/api/v2/peers/167.114.29.55
 * Expected Response:
    {
    "data": {
        "ip": "string",
        "port": int,
        "version": "string",
        "status": "string",
        "os": "string",
        "latency": int
    }
    }
 */
TEST(api, test_two_peer)
{
    Ark::Client arkClient(DEVNET);

    const auto peer = arkClient.peer("167.114.29.55");

    auto parser = Ark::Test::Utils::JSONParser(peer);

    const auto ip = parser->getRoot()["data"]["ip"].as<const char*>();
    ASSERT_STREQ("167.114.29.55", ip);

    const auto port = parser->getRoot()["data"]["port"].as<int>();
    ASSERT_STREQ("4002", toString(port).c_str());

    const auto version = parser->getRoot()["data"]["version"].as<const char*>();
    ASSERT_STREQ("2.0.0", version);

    const auto status = parser->getRoot()["data"]["status"].as<const char*>();
    ASSERT_STREQ("OK", status);

    const auto os = parser->getRoot()["data"]["os"].as<const char*>();
    ASSERT_STREQ("linux", os);

    const auto latency = parser->getRoot()["data"]["latency"].as<int>();
    ASSERT_STRNE("0", toString(latency).c_str());
}

/* test_two_peers_peers
 * https://dexplorer.ark.io:8443/api/v2/peers?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/peers?limit=5&page=1",
        "first": "/api/v2/peers?limit=5&page=1",
        "last": "/api/v2/peers?limit=5&page=1"
    },
    "data": [
        {
        "ip": "string",
        "port": "string",
        "version": "string",
        "status": "string",
        "os": "string",
        "latency": int
        }
    ]
    }
 */
TEST(api, test_two_peers)
{
    Ark::Client arkClient(DEVNET);

    const auto peers = arkClient.peers(5, 1);
    auto parser = Ark::Test::Utils::JSONParser(peers);

    const auto count = parser->getRoot()["meta"]["count"].as<int>();
    ASSERT_EQ(5, count);

    const auto pageCount = parser->getRoot()["meta"]["pageCount"].as<int>();
    ASSERT_EQ(1, pageCount);

    const auto totalCount = parser->getRoot()["meta"]["totalCount"].as<int>();
    ASSERT_EQ(5, totalCount);

    for (int i = 0; i < 5; i++)
    {
        const auto ip = parser->getRoot()["data"][i]["ip"].as<const char*>();
        ASSERT_STRNE("", ip);

        const auto port = parser->getRoot()["data"][i]["port"].as<int>();
        ASSERT_EQ(4002, port);

        const auto version = parser->getRoot()["data"][i]["version"].as<const char*>();
        ASSERT_STREQ("2.0.0", version);

        // const auto status = parser->getRoot()["data"][i]["status"].as<const char*>();
        // ASSERT_STREQ("OK", status);
        // ASSERT_STREQ("ECONNABORTED", status);

        const auto os = parser->getRoot()["data"][0]["os"].as<const char*>();
        ASSERT_STRNE("", os);

        const auto latency = parser->getRoot()["data"][0]["latency"].as<int>();
        ASSERT_STRNE("0", toString(latency).c_str());
    };
}

#endif
