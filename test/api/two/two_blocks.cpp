

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"
#include <vector>

#if defined(HAS_TWO_API) && !defined(HAS_ONE_API)

/* test_two_blocks_block
 * https://dexplorer.ark.io:8443/api/v2/blocks/17103087165885061305
 * Expected Response:
    {
    "data": {
        "id": "17103087165885061305",
        "version": 0,
        "height": 154381,
        "previous": "3454540003776685435",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "kolap",
            "address": "DMDLntCxSJQmvebSU5ad5yjkBxjF6TgWQi",
            "publicKey": "022ffb5fa4eb5b2e71c985b1d796642528802f04a6ddf9a449ba1aab292a9744aa"
        },
        "signature": "304402200ae59a27429e86af17937dd2f573f4a33a362c24512ca0b2b190850123b3553302201fe78161a5e7df2b2977f51ac2e11000c02e4bec0cc364db2db7941201905e26",
        "transactions": 0,
        "timestamp": {
            "epoch": 44448202,
            "unix": 1534549402,
            "human": "2018-08-17T23:43:22Z"
        }
    }
    }
 */
TEST(api, test_two_blocks_block)
{
    ARK::Client arkClient(DEVNET);

    const auto blockResponse = arkClient.block("17103087165885061305");
    auto parser = ARK::Test::Utils::makeJSONString(blockResponse);

    const auto id = parser->valueIn("data", "id");
    ASSERT_STREQ("17103087165885061305", id.c_str());

    const auto version = parser->valueIn("data", "version");
    ASSERT_STREQ("0", version.c_str());

    const auto height = parser->valueIn("data", "height");
    ASSERT_STREQ("154381", height.c_str());

    const auto previous = parser->valueIn("data", "previous");
    ASSERT_STREQ("3454540003776685435", previous.c_str());

    const auto reward = parser->subvalueNestedIn("data", "forged", "reward");
    ASSERT_STREQ("200000000", reward.c_str());

    const auto fee = parser->subvalueNestedIn("data", "forged", "fee");
    ASSERT_STREQ("0", fee.c_str());

    const auto total = parser->subvalueNestedIn("data", "forged", "total");
    ASSERT_STREQ("200000000", total.c_str());

    const auto hash = parser->subvalueNestedIn("data", "payload", "hash");
    ASSERT_STREQ("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855", hash.c_str());

    const auto length = parser->subvalueNestedIn("data", "payload", "length");
    ASSERT_STREQ("0", length.c_str());

    const auto username = parser->subvalueNestedIn("data", "generator", "username");
    ASSERT_STREQ("kolap", username.c_str());

    const auto address = parser->subvalueNestedIn("data", "generator", "address");
    ASSERT_STREQ("DMDLntCxSJQmvebSU5ad5yjkBxjF6TgWQi", address.c_str());

    const auto publicKey = parser->subvalueNestedIn("data", "generator", "publicKey");
    ASSERT_STREQ("022ffb5fa4eb5b2e71c985b1d796642528802f04a6ddf9a449ba1aab292a9744aa", publicKey.c_str());

    const auto signature = parser->valueIn("data", "signature");
    ASSERT_STREQ("304402200ae59a27429e86af17937dd2f573f4a33a362c24512ca0b2b190850123b3553302201fe78161a5e7df2b2977f51ac2e11000c02e4bec0cc364db2db7941201905e26", signature.c_str());

    const auto transactions = parser->valueIn("data", "transactions");
    ASSERT_STREQ("0", transactions.c_str());

    const auto epoch = parser->subvalueNestedIn("data", "timestamp", "epoch");
    ASSERT_STREQ("44448202", epoch.c_str());

    const auto unix = parser->subvalueNestedIn("data", "timestamp", "unix");
    ASSERT_STREQ("1534549402", unix.c_str());

    const auto human = parser->subvalueNestedIn("data", "timestamp", "human");
    ASSERT_STREQ("2018-08-17T23:43:22Z", human.c_str());
}


/* test_two_blocks_blocks
 * https://dexplorer.ark.io:8443/api/v2/blocks
 * Expected Response:
    {
    "meta": {
        "count": 10,
        "pageCount": 1,
        "totalCount": 10,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/blocks?limit=10&page=1",
        "first": "\/api\/v2\/blocks?limit=10&page=1",
        "last": "\/api\/v2\/blocks?limit=10&page=1"
    },
    "data": [
        {
        "id": "13890013278817254382",
        "version": 0,
        "height": 174144,
        "previous": "18213773356435001696",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "kolap",
            "address": "DMDLntCxSJQmvebSU5ad5yjkBxjF6TgWQi",
            "publicKey": "022ffb5fa4eb5b2e71c985b1d796642528802f04a6ddf9a449ba1aab292a9744aa"
        },
        "signature": "3044022046095908593fb5b383fc32c154e9757678db14b159294364b162841f0b9b1b37022012f6a184621f6ef5c02f8650be9132c1c2725492c57c5596a8eb0962a78abc61",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608098,
            "unix": 1534709298,
            "human": "2018-08-19T20:08:18Z"
        }
        },
        {
        "id": "18213773356435001696",
        "version": 0,
        "height": 174143,
        "previous": "13102846857501316197",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "genesis_43",
            "address": "DNpPXpZrRSKsk9aiM2p4g5PiKFHxEFCtqb",
            "publicKey": "021b0f58eca7f123428a8647ffe0644a9454c510f066d3864c27d8c7ad8f5a8aa4"
        },
        "signature": "3045022100ed148d8388f0073ba1946d550ebdc78745a1e0fd7e293df2ae24caca90d57959022026040bab9d116bd3f950863a81118d8a534931e4590dd979781f22a7e78dd532",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608090,
            "unix": 1534709290,
            "human": "2018-08-19T20:08:10Z"
        }
        },
        {
        "id": "13102846857501316197",
        "version": 0,
        "height": 174142,
        "previous": "11084352102779081298",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "arkvader",
            "address": "DEkLRB1xrP6KCLPQzw7eGcSzzqWvYyrWDh",
            "publicKey": "031539f3715a1fa3f8c7cb1d2cd9c9cf71217913cd11afea3b5ac062f558a882f7"
        },
        "signature": "3045022100c49fa1fb2b9ea9feaeb0f82bbc5b4dd2b4f20ecea83a7159bab98f5ed61e7083022075630c824d1126e71665f729a3d3313aaaa3bb96d873b6c6203699fc3b67c29c",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608082,
            "unix": 1534709282,
            "human": "2018-08-19T20:08:02Z"
        }
        },
        {
        "id": "11084352102779081298",
        "version": 0,
        "height": 174141,
        "previous": "14670846950982721376",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "genesis_1",
            "address": "DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK",
            "publicKey": "02511f16ffb7b7e9afc12f04f317a11d9644e4be9eb5a5f64673946ad0f6336f34"
        },
        "signature": "3045022100f83242e6e55bf8589fa90cc7c89b02a7a737007517b8bfa64553e1a679dc61d70220211fae21eb4e4f4ee093ad7dfb0dc5b7a4d7982a276896e812de36ef8372446e",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608074,
            "unix": 1534709274,
            "human": "2018-08-19T20:07:54Z"
        }
        },
        {
        "id": "14670846950982721376",
        "version": 0,
        "height": 174140,
        "previous": "16903933677675228937",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "genesis_27",
            "address": "DKY5eyQUKKYyaCfPp6MUv3Y4FW6EbNF53A",
            "publicKey": "03508436f55577f406be58a5e7e59307cea823943c5312d62f4e3f3c63966f6e7c"
        },
        "signature": "3045022100939324f4b53bb5ee2b36bf5401f2798e46b49c03d7d02f34ada47c7f2f9ad1d0022065859dd894b3355ed82e12ff1d4571700d90a38f36a536d02abdc63db335dbd2",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608066,
            "unix": 1534709266,
            "human": "2018-08-19T20:07:46Z"
        }
        },
        {
        "id": "16903933677675228937",
        "version": 0,
        "height": 174139,
        "previous": "10668931166781059878",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "darkghost",
            "address": "D8YhYStb94gxmddRwU7DsD233mghUBrrUf",
            "publicKey": "0344f455358055213235a21eff6deffa4d8ded38e43b9103e10184cc4c108ee81c"
        },
        "signature": "3044022068219a7cb3695b322283ba33724fd6107c65c48ff671c26b676a9b7543e5e56202204ab6fb93b832d84e6d827195521059b5b377b83cb5f4e28bc066f939d4467c01",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608058,
            "unix": 1534709258,
            "human": "2018-08-19T20:07:38Z"
        }
        },
        {
        "id": "10668931166781059878",
        "version": 0,
        "height": 174138,
        "previous": "18351204754468438251",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "genesis_8",
            "address": "DEHtM61jVo4uJWP23B6mGrb6p9batXCHZs",
            "publicKey": "02c3d1ae1b8fe831218f78cf09d864e60818ebdba4aacc74ecc2bcf2734aadf5ea"
        },
        "signature": "3045022100c650a21058f785e413643b43805a3b44ace3f3f85fa4f8c5d26e4be9a214bb8702202773cae3e3bd95c2b4839a8dda2335497aea44befe09ce091978bf420cb1ee4d",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608050,
            "unix": 1534709250,
            "human": "2018-08-19T20:07:30Z"
        }
        },
        {
        "id": "18351204754468438251",
        "version": 0,
        "height": 174137,
        "previous": "1977493179760416103",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "stevenhop2",
            "address": "DNfK7HEZJnYswSfFYB44HGhxtAKrVgBJqE",
            "publicKey": "03d4ec98dfc6f3fe2ccb64a950534709ab6bb9134ae02205822f7cecf4391f03bd"
        },
        "signature": "3043021f1c146e1aec46167c3b172725f8683164a05edd94e186407125494d97acd3bc02205cfb0c2a3f03b480fb10bc4cba48dc3bda7100cabd9cd04043b79ed28b5f3602",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608042,
            "unix": 1534709242,
            "human": "2018-08-19T20:07:22Z"
        }
        },
        {
        "id": "1977493179760416103",
        "version": 0,
        "height": 174136,
        "previous": "782883334344763835",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "arklabs",
            "address": "D9z1ZUcCUHHeiFLEtYhwk6z8kmbCCHTRFd",
            "publicKey": "0394685435d7331d178effe91d6b101ce7c4a6e03d2a96cfd5be1fffb0ae156e58"
        },
        "signature": "30440220210a3c448308a3e303a0aed23060f0df4e671efab57daddc8262cde2a9d244a102202c41c99b2fedc7a2f114f826e105446a8cfe4c2634e1f17d26e9f1740655b093",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608034,
            "unix": 1534709234,
            "human": "2018-08-19T20:07:14Z"
        }
        },
        {
        "id": "782883334344763835",
        "version": 0,
        "height": 174135,
        "previous": "1308836096667701535",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "darkegeron",
            "address": "DTaacNrDbUiXfpxirPm7svnrR4uasS3xk5",
            "publicKey": "030c0d642b9b5337d8f9f257e9e460bdd9d15e0581391896336dd8acb24b5d47b4"
        },
        "signature": "3045022100da3f0e9ff90fa10b1d760cfc74240a60f9f3c21895891f5d27bf74fa673d0db1022070b35da5e8ab079b264d8c3abcd912d9b030c239ac49b464a119160585495d64",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608026,
            "unix": 1534709226,
            "human": "2018-08-19T20:07:06Z"
        }
        }
    ]
    }
 */
TEST(api, test_two_blocks_blocks)
{
    ARK::Client arkClient(DEVNET);

    const auto blocksResponse = arkClient.blocks();
    auto parser = ARK::Test::Utils::makeJSONString(blocksResponse);

    for (int i = 0; i < 10; i++)
    {
        const auto version = parser->subarrayValueIn("data", i, "version");
        ASSERT_STREQ("0", version.c_str());
    }
}

/* test_two_blocks_blocks_limit_page
 * https://dexplorer.ark.io:8443/api/v2/blocks?limit=10&page=1
 * Expected Response:
    {
    "meta": {
        "count": 10,
        "pageCount": 1,
        "totalCount": 10,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/blocks?limit=10&page=1",
        "first": "\/api\/v2\/blocks?limit=10&page=1",
        "last": "\/api\/v2\/blocks?limit=10&page=1"
    },
    "data": [
        {
        "id": "13890013278817254382",
        "version": 0,
        "height": 174144,
        "previous": "18213773356435001696",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "kolap",
            "address": "DMDLntCxSJQmvebSU5ad5yjkBxjF6TgWQi",
            "publicKey": "022ffb5fa4eb5b2e71c985b1d796642528802f04a6ddf9a449ba1aab292a9744aa"
        },
        "signature": "3044022046095908593fb5b383fc32c154e9757678db14b159294364b162841f0b9b1b37022012f6a184621f6ef5c02f8650be9132c1c2725492c57c5596a8eb0962a78abc61",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608098,
            "unix": 1534709298,
            "human": "2018-08-19T20:08:18Z"
        }
        },
        {
        "id": "18213773356435001696",
        "version": 0,
        "height": 174143,
        "previous": "13102846857501316197",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "genesis_43",
            "address": "DNpPXpZrRSKsk9aiM2p4g5PiKFHxEFCtqb",
            "publicKey": "021b0f58eca7f123428a8647ffe0644a9454c510f066d3864c27d8c7ad8f5a8aa4"
        },
        "signature": "3045022100ed148d8388f0073ba1946d550ebdc78745a1e0fd7e293df2ae24caca90d57959022026040bab9d116bd3f950863a81118d8a534931e4590dd979781f22a7e78dd532",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608090,
            "unix": 1534709290,
            "human": "2018-08-19T20:08:10Z"
        }
        },
        {
        "id": "13102846857501316197",
        "version": 0,
        "height": 174142,
        "previous": "11084352102779081298",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "arkvader",
            "address": "DEkLRB1xrP6KCLPQzw7eGcSzzqWvYyrWDh",
            "publicKey": "031539f3715a1fa3f8c7cb1d2cd9c9cf71217913cd11afea3b5ac062f558a882f7"
        },
        "signature": "3045022100c49fa1fb2b9ea9feaeb0f82bbc5b4dd2b4f20ecea83a7159bab98f5ed61e7083022075630c824d1126e71665f729a3d3313aaaa3bb96d873b6c6203699fc3b67c29c",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608082,
            "unix": 1534709282,
            "human": "2018-08-19T20:08:02Z"
        }
        },
        {
        "id": "11084352102779081298",
        "version": 0,
        "height": 174141,
        "previous": "14670846950982721376",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "genesis_1",
            "address": "DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK",
            "publicKey": "02511f16ffb7b7e9afc12f04f317a11d9644e4be9eb5a5f64673946ad0f6336f34"
        },
        "signature": "3045022100f83242e6e55bf8589fa90cc7c89b02a7a737007517b8bfa64553e1a679dc61d70220211fae21eb4e4f4ee093ad7dfb0dc5b7a4d7982a276896e812de36ef8372446e",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608074,
            "unix": 1534709274,
            "human": "2018-08-19T20:07:54Z"
        }
        },
        {
        "id": "14670846950982721376",
        "version": 0,
        "height": 174140,
        "previous": "16903933677675228937",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "genesis_27",
            "address": "DKY5eyQUKKYyaCfPp6MUv3Y4FW6EbNF53A",
            "publicKey": "03508436f55577f406be58a5e7e59307cea823943c5312d62f4e3f3c63966f6e7c"
        },
        "signature": "3045022100939324f4b53bb5ee2b36bf5401f2798e46b49c03d7d02f34ada47c7f2f9ad1d0022065859dd894b3355ed82e12ff1d4571700d90a38f36a536d02abdc63db335dbd2",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608066,
            "unix": 1534709266,
            "human": "2018-08-19T20:07:46Z"
        }
        },
        {
        "id": "16903933677675228937",
        "version": 0,
        "height": 174139,
        "previous": "10668931166781059878",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "darkghost",
            "address": "D8YhYStb94gxmddRwU7DsD233mghUBrrUf",
            "publicKey": "0344f455358055213235a21eff6deffa4d8ded38e43b9103e10184cc4c108ee81c"
        },
        "signature": "3044022068219a7cb3695b322283ba33724fd6107c65c48ff671c26b676a9b7543e5e56202204ab6fb93b832d84e6d827195521059b5b377b83cb5f4e28bc066f939d4467c01",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608058,
            "unix": 1534709258,
            "human": "2018-08-19T20:07:38Z"
        }
        },
        {
        "id": "10668931166781059878",
        "version": 0,
        "height": 174138,
        "previous": "18351204754468438251",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "genesis_8",
            "address": "DEHtM61jVo4uJWP23B6mGrb6p9batXCHZs",
            "publicKey": "02c3d1ae1b8fe831218f78cf09d864e60818ebdba4aacc74ecc2bcf2734aadf5ea"
        },
        "signature": "3045022100c650a21058f785e413643b43805a3b44ace3f3f85fa4f8c5d26e4be9a214bb8702202773cae3e3bd95c2b4839a8dda2335497aea44befe09ce091978bf420cb1ee4d",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608050,
            "unix": 1534709250,
            "human": "2018-08-19T20:07:30Z"
        }
        },
        {
        "id": "18351204754468438251",
        "version": 0,
        "height": 174137,
        "previous": "1977493179760416103",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "stevenhop2",
            "address": "DNfK7HEZJnYswSfFYB44HGhxtAKrVgBJqE",
            "publicKey": "03d4ec98dfc6f3fe2ccb64a950534709ab6bb9134ae02205822f7cecf4391f03bd"
        },
        "signature": "3043021f1c146e1aec46167c3b172725f8683164a05edd94e186407125494d97acd3bc02205cfb0c2a3f03b480fb10bc4cba48dc3bda7100cabd9cd04043b79ed28b5f3602",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608042,
            "unix": 1534709242,
            "human": "2018-08-19T20:07:22Z"
        }
        },
        {
        "id": "1977493179760416103",
        "version": 0,
        "height": 174136,
        "previous": "782883334344763835",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "arklabs",
            "address": "D9z1ZUcCUHHeiFLEtYhwk6z8kmbCCHTRFd",
            "publicKey": "0394685435d7331d178effe91d6b101ce7c4a6e03d2a96cfd5be1fffb0ae156e58"
        },
        "signature": "30440220210a3c448308a3e303a0aed23060f0df4e671efab57daddc8262cde2a9d244a102202c41c99b2fedc7a2f114f826e105446a8cfe4c2634e1f17d26e9f1740655b093",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608034,
            "unix": 1534709234,
            "human": "2018-08-19T20:07:14Z"
        }
        },
        {
        "id": "782883334344763835",
        "version": 0,
        "height": 174135,
        "previous": "1308836096667701535",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "darkegeron",
            "address": "DTaacNrDbUiXfpxirPm7svnrR4uasS3xk5",
            "publicKey": "030c0d642b9b5337d8f9f257e9e460bdd9d15e0581391896336dd8acb24b5d47b4"
        },
        "signature": "3045022100da3f0e9ff90fa10b1d760cfc74240a60f9f3c21895891f5d27bf74fa673d0db1022070b35da5e8ab079b264d8c3abcd912d9b030c239ac49b464a119160585495d64",
        "transactions": 0,
        "timestamp": {
            "epoch": 44608026,
            "unix": 1534709226,
            "human": "2018-08-19T20:07:06Z"
        }
        }
    ]
    }
 */
TEST(api, test_two_blocks_blocks_limit_page)
{
	ARK::Client arkClient(DEVNET);

    const int limit = 10;
    const int page = 1;
    const auto blocksResponse = arkClient.blocks(limit, page);
    auto parser = ARK::Test::Utils::makeJSONString(blocksResponse);

    for (int i = 0; i < 10; i++)
    {
        const auto version = parser->subarrayValueIn("data", i, "version");
        ASSERT_STREQ("0", version.c_str());
    }
}

/* test_two_blocks_block_transactions
 * https://dexplorer.ark.io:8443/api/v2/blocks/4738358981673511380/transactions
 * Espected Response:
    {
    "meta": {
        "count": 1,
        "pageCount": 1,
        "totalCount": 1,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/blocks\/4738358981673511380\/transactions?page=1&limit=100",
        "first": "\/api\/v2\/blocks\/4738358981673511380\/transactions?page=1&limit=100",
        "last": "\/api\/v2\/blocks\/4738358981673511380\/transactions?page=1&limit=100"
    },
    "data": [
        {
        "id": "752cf99e5c247f61bf64878377b809409edece83be0e236c2e470899cde15e24",
        "blockId": "4738358981673511380",
        "type": 0,
        "amount": 10000000,
        "fee": 1000000,
        "sender": "DMzBk3g7ThVQPYmpYDTHBHiqYuTtZ9WdM3",
        "recipient": "DMzBk3g7ThVQPYmpYDTHBHiqYuTtZ9WdM3",
        "signature": "3045022100973bd2dedc89719218ee17b6d598f518dbb33961e76c721fbad10f1e348f8007022067190b2c27f4a43a577e8f7688011b7e2fbb7d45715bc12d6a7aa53dd7fe5082",
        "vendorField": "Override Test-0.01",
        "confirmations": 77,
        "timestamp": {
            "epoch": 44607881,
            "unix": 1534709081,
            "human": "2018-08-19T20:04:41Z"
        }
        }
    ]
    }
 */
TEST(api, test_two_blocks_block_transactions)
{
	ARK::Client arkClient(DEVNET);

    const auto blockTransactionsResponse = arkClient.blockTransactions("4738358981673511380");
    auto parser = ARK::Test::Utils::makeJSONString(blockTransactionsResponse);

    const auto id = parser->subarrayValueIn("data", 0, "id");
    ASSERT_STREQ("752cf99e5c247f61bf64878377b809409edece83be0e236c2e470899cde15e24", id.c_str());

    const auto blockId = parser->subarrayValueIn("data", 0, "blockId");
    ASSERT_STREQ("4738358981673511380", blockId.c_str());

    const auto type = parser->subarrayValueIn("data", 0, "type");
    ASSERT_STREQ("0", type.c_str());

    const auto amount = parser->subarrayValueIn("data", 0, "amount");
    ASSERT_STREQ("10000000", amount.c_str());

    const auto fee = parser->subarrayValueIn("data", 0, "fee");
    ASSERT_STREQ("1000000", fee.c_str());

    const auto sender = parser->subarrayValueIn("data", 0, "sender");
    ASSERT_STREQ("DMzBk3g7ThVQPYmpYDTHBHiqYuTtZ9WdM3", sender.c_str());

    const auto recipient = parser->subarrayValueIn("data", 0, "recipient");
    ASSERT_STREQ("DMzBk3g7ThVQPYmpYDTHBHiqYuTtZ9WdM3", recipient.c_str());

    const auto signature = parser->subarrayValueIn("data", 0, "signature");
    ASSERT_STREQ("3045022100973bd2dedc89719218ee17b6d598f518dbb33961e76c721fbad10f1e348f8007022067190b2c27f4a43a577e8f7688011b7e2fbb7d45715bc12d6a7aa53dd7fe5082", signature.c_str());

    const auto vendorField = parser->subarrayValueIn("data", 0, "vendorField");
    ASSERT_STREQ("Override Test-0.01", vendorField.c_str());

    const auto confirmations = parser->subarrayValueIn("data", 0, "confirmations");
    ASSERT_STRNE("0", confirmations.c_str());
    ASSERT_STRNE("", confirmations.c_str());

    const auto epoch = parser->subarrayValueNestedIn("data", 0, "timestamp", "epoch");
    ASSERT_STREQ("44607881", epoch.c_str());

    const auto unix = parser->subarrayValueNestedIn("data", 0, "timestamp", "unix");
    ASSERT_STREQ("1534709081", unix.c_str());

    const auto human = parser->subarrayValueNestedIn("data", 0, "timestamp", "human");
    ASSERT_STREQ("2018-08-19T20:04:41Z", human.c_str());
}

#endif
