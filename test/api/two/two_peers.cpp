

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_TWO_API

/* test_two_peers_peer
 * https://dexplorer.ark.io:8443/api/v2/peers/167.114.29.55
 * Expected Response:
    {
    "data": {
        "ip": "167.114.29.55",
        "port": 4002,
        "version": "2.0.0",
        "status": "OK",
        "os": "linux",
        "latency": 190
    }
    }
 */
TEST(api, test_two_peer)
{
    Ark::Client arkClient(DEVNET);

    const auto peer = arkClient.peer("167.114.29.55");
    auto parser = Ark::Test::Utils::makeJSONString(peer);

    const auto ip = parser->valueIn("data", "ip");
    ASSERT_STREQ("167.114.29.55", ip.c_str());

    const auto port = parser->valueIn("data", "port");
    ASSERT_STREQ("4002", port.c_str());

    const auto version = parser->valueIn("data", "version");
    ASSERT_STREQ("2.0.0", version.c_str());

    const auto status = parser->valueIn("data", "status");
    ASSERT_STREQ("OK", status.c_str());

    const auto os = parser->valueIn("data", "os");
    ASSERT_STREQ("linux", os.c_str());

    const auto latency = parser->valueIn("data", "latency");
    ASSERT_STRNE("0", latency.c_str());
    ASSERT_STRNE("", latency.c_str());
}

/* test_two_peers_peers
 * https://dexplorer.ark.io:8443/api/v2/peers?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": 5,
        "pageCount": 1,
        "totalCount": 5,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/peers?limit=5&page=1",
        "first": "\/api\/v2\/peers?limit=5&page=1",
        "last": "\/api\/v2\/peers?limit=5&page=1"
    },
    "data": [
        {
        "ip": "37.59.70.165",
        "port": "4002",
        "version": "2.0.0",
        "status": "OK",
        "os": "linux",
        "latency": 35
        },
        {
        "ip": "145.239.75.25",
        "port": "4002",
        "version": "2.0.0",
        "status": "OK",
        "os": "linux",
        "latency": 36
        },
        {
        "ip": "104.238.173.32",
        "port": "4002",
        "version": "2.0.0",
        "status": "OK",
        "os": "linux",
        "latency": 43
        },
        {
        "ip": "45.77.90.28",
        "port": "4002",
        "version": "2.0.0",
        "status": "OK",
        "os": "linux",
        "latency": 43
        },
        {
        "ip": "209.250.228.98",
        "port": "4002",
        "version": "2.0.0",
        "status": "OK",
        "os": "linux",
        "latency": 43
        }
    ]
    }
 */
TEST(api, test_two_peers)
{
    Ark::Client arkClient(DEVNET);

    const auto peers = arkClient.peers(5, 1);
    auto parser = Ark::Test::Utils::makeJSONString(peers);

    const auto count = parser->valueIn("meta", "count");
    ASSERT_STREQ("5", count.c_str());

    const auto pageCount = parser->valueIn("meta", "pageCount");
    ASSERT_STREQ("1", pageCount.c_str());

    const auto totalCount = parser->valueIn("meta", "totalCount");
    ASSERT_STREQ("5", totalCount.c_str());

    for (int i = 0; i < 5; i++)
    {
        const auto ip = parser->subarrayValueIn("data", i, "ip");
        ASSERT_STRNE("", ip.c_str());

        const auto port = parser->subarrayValueIn("data", i, "port");
        ASSERT_STREQ("4002", port.c_str());

        const auto version = parser->subarrayValueIn("data", i, "version");
        ASSERT_STREQ("2.0.0", version.c_str());

        const auto status = parser->subarrayValueIn("data", i, "status");
        // ASSERT_STREQ("OK", status.c_str());
        // ASSERT_STREQ("ECONNABORTED", status.c_str());

        const auto os = parser->subarrayValueIn("data", 0, "os");
        ASSERT_STRNE("", os.c_str());

        const auto latency = parser->subarrayValueIn("data", 0, "latency");
        ASSERT_STRNE("0", latency.c_str());
        ASSERT_STRNE("", latency.c_str());
    };
}

#endif
