

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

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

    DynamicJsonBuffer jsonBuffer(peer.size());
    JsonObject& root = jsonBuffer.parseObject(peer);

    JsonObject& data = root["data"];

    const char* ip = data["ip"];
    ASSERT_STREQ("167.114.29.55", ip);

    int port = data["port"];
    ASSERT_EQ(4002, port);

    const char* version = data["version"];
    ASSERT_STREQ("2.0.0", version);

    const char* status = data["status"];
    ASSERT_STREQ("OK", status);

    const char* os = data["os"];
    ASSERT_STREQ("linux", os);

    int latency = data["latency"];
    ASSERT_STRNE("", toString(latency).c_str());
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

    DynamicJsonBuffer jsonBuffer(peers.size());
    JsonObject& root = jsonBuffer.parseObject(peers);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);


    JsonObject& dataZero = root["data"][0];

    const char* ip = dataZero["ip"];
    ASSERT_STRNE("", ip);

    int port = dataZero["port"];
    ASSERT_EQ(4002, port);

    const char* version = dataZero["version"];
    ASSERT_STREQ("2.0.0", version);

    const char* os = dataZero["os"];
    ASSERT_STRNE("", os);

    int latency = dataZero["latency"];
    ASSERT_STRNE("", toString(latency).c_str());
}

#endif
