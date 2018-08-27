

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_TWO_API

/* test_two_blocks_block
 * https://dexplorer.ark.io:8443/api/v2/blocks/13114381566690093367
 * Expected Response:
    {
    "data": {
        "id": "13114381566690093367",
        "version": 0,
        "height": 1,
        "previous": null,
        "forged": {
            "reward": 0,
            "fee": 0,
            "total": 0
        },
        "payload": {
            "hash": "2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867",
            "length": 11395
        },
        "generator": {
        "username": null,
        "address": "D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax",
        "publicKey": "03d3fdad9c5b25bf8880e6b519eb3611a5c0b31adebc8455f0e096175b28321aff"
        },
        "signature": "3044022035694a9b99a9236655c658eb07fc3b02ce5edcc24b76424a7287c54ed3822b0602203621e92defb360490610f763d85e94c2db2807a4bd7756cc8a6a585463ef7bae",
        "transactions": 52,
        "timestamp": {
        "epoch": 0,
        "unix": 1490101200,
        "human": "2017-03-21T13:00:00Z"
        }
    }
    }
 */
TEST(api, test_two_block)
{
    Ark::Client arkClient(DEVNET);

    const auto blockResponse = arkClient.block("13114381566690093367");
    auto parser = Ark::Test::Utils::makeJSONString(blockResponse);

    const auto id = parser->valueIn("data", "id");
    ASSERT_STREQ("13114381566690093367", id.c_str());

    const auto version = parser->valueIn("data", "version");
    ASSERT_STREQ("0", version.c_str());

    const auto height = parser->valueIn("data", "height");
    ASSERT_STREQ("1", height.c_str());

    const auto reward = parser->subvalueNestedIn("data", "forged", "reward");
    ASSERT_STREQ("0", reward.c_str());

    const auto fee = parser->subvalueNestedIn("data", "forged", "fee");
    ASSERT_STREQ("0", fee.c_str());

    const auto total = parser->subvalueNestedIn("data", "forged", "total");
    ASSERT_STREQ("0", total.c_str());

    const auto hash = parser->subvalueNestedIn("data", "payload", "hash");
    ASSERT_STREQ("2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867", hash.c_str());

    const auto length = parser->subvalueNestedIn("data", "payload", "length");
    ASSERT_STREQ("11395", length.c_str());

    const auto address = parser->subvalueNestedIn("data", "generator", "address");
    ASSERT_STREQ("D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax", address.c_str());

    const auto publicKey = parser->subvalueNestedIn("data", "generator", "publicKey");
    ASSERT_STREQ("03d3fdad9c5b25bf8880e6b519eb3611a5c0b31adebc8455f0e096175b28321aff", publicKey.c_str());

    const auto signature = parser->valueIn("data", "signature");
    ASSERT_STREQ("3044022035694a9b99a9236655c658eb07fc3b02ce5edcc24b76424a7287c54ed3822b0602203621e92defb360490610f763d85e94c2db2807a4bd7756cc8a6a585463ef7bae", signature.c_str());

    const auto transactions = parser->valueIn("data", "transactions");
    ASSERT_STREQ("52", transactions.c_str());

    const auto epoch = parser->subvalueNestedIn("data", "timestamp", "epoch");
    ASSERT_STREQ("0", epoch.c_str());

    const auto timestampUnix = parser->subvalueNestedIn("data", "timestamp", "unix");
    ASSERT_STREQ("1490101200", timestampUnix.c_str());

    const auto human = parser->subvalueNestedIn("data", "timestamp", "human");
    ASSERT_STREQ("2017-03-21T13:00:00Z", human.c_str());
}

/* test_two_blocks_block_transactions
 * https://dexplorer.ark.io:8443/api/v2/blocks/10241408650344629183/transactions
 * Espected Response:
{
  "meta": {
    "count": 52,
    "pageCount": 1,
    "totalCount": 52,
    "next": null,
    "previous": null,
    "self": "\/api\/v2\/blocks\/13114381566690093367\/transactions?page=1&limit=100",
    "first": "\/api\/v2\/blocks\/13114381566690093367\/transactions?page=1&limit=100",
    "last": "\/api\/v2\/blocks\/13114381566690093367\/transactions?page=1&limit=100"
  },
  "data": [
    {
      "id": "3e3817fd0c35bc36674f3874c2953fa3e35877cbcdb44a08bdc6083dbd39d572",
      "blockId": "13114381566690093367",
      "type": 0,
      "amount": 1.25e+16,
      "fee": 0,
      "sender": "DLK7ts2DpkbeBjFamuFtHLoDAq5upDhCmf",
      "recipient": "D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax",
      "signature": "304402203a3f0f80aad4e0561ae975f241f72a074245f1205d676d290d6e5630ed4c027502207b31fee68e64007c380a4b6baccd4db9b496daef5f7894676586e1347ac30a3b",
      "confirmations": 316,
      "timestamp": {
        "epoch": 0,
        "unix": 1490101200,
        "human": "2017-03-21T13:00:00Z"
      }
    },
    ...
    {
      "id": "7d7418341dabf8406726f30b33d22db8a6e5713a36b87f4d5c2a12e44cae2564",
      "blockId": "13114381566690093367",
      "type": 2,
      "amount": 0,
      "fee": 0,
      "sender": "DKY5eyQUKKYyaCfPp6MUv3Y4FW6EbNF53A",
      "signature": "3045022100aa88c4528c44c168fa205cc88b240ad73bde9bd0bf7b6c3607d15cd7dd1a6bfe022024c361cf430531ddf6345fe00c40eeb4f7ebeebd853ecf927f34f465ec87d134",
      "asset": {
        "delegate": {
          "username": "genesis_27"
        }
      },
      "confirmations": 316,
      "timestamp": {
        "epoch": 0,
        "unix": 1490101200,
        "human": "2017-03-21T13:00:00Z"
      }
    }
  ]
}
 */
TEST(api, test_two_block_transactions)
{
    Ark::Client arkClient(DEVNET);

    const auto blockTransactionsResponse = arkClient.blockTransactions("10241408650344629183");
    auto parser = Ark::Test::Utils::makeJSONString(blockTransactionsResponse);

    const auto id = parser->subarrayValueIn("data", 0, "id");
    ASSERT_STRNE("", id.c_str());

    const auto blockId = parser->subarrayValueIn("data", 0, "blockId");
    ASSERT_STRNE("", blockId.c_str());

    const auto type = parser->subarrayValueIn("data", 0, "type");
    ASSERT_STRNE("", type.c_str());

    // const auto amount = parser->subarrayValueIn("data", 0, "amount");
    // ASSERT_STREQ("0", amount.c_str());

    const auto fee = parser->subarrayValueIn("data", 0, "fee");
    ASSERT_STRNE("", fee.c_str());

    const auto sender = parser->subarrayValueIn("data", 0, "sender");
    ASSERT_STRNE("", sender.c_str());

    // const auto recipient = parser->subarrayValueIn("data", 0, "recipient");
    // ASSERT_STREQ("", recipient.c_str());

    const auto signature = parser->subarrayValueIn("data", 0, "signature");
    ASSERT_STRNE("", signature.c_str());

    const auto confirmations = parser->subarrayValueIn("data", 0, "confirmations");
    ASSERT_STRNE("0", confirmations.c_str());
    ASSERT_STRNE("", confirmations.c_str());

    const auto epoch = parser->subarrayValueNestedIn("data", 0, "timestamp", "epoch");
    ASSERT_STRNE("", epoch.c_str());

    const auto timestampUnix = parser->subarrayValueNestedIn("data", 0, "timestamp", "unix");
    ASSERT_STRNE("", timestampUnix.c_str());

    const auto human = parser->subarrayValueNestedIn("data", 0, "timestamp", "human");
    ASSERT_STRNE("", human.c_str());
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
TEST(api, test_two_blocks)
{
    Ark::Client arkClient(DEVNET);

    const auto blocksResponse = arkClient.blocks();
    auto parser = Ark::Test::Utils::makeJSONString(blocksResponse);

    const auto version = parser->subarrayValueIn("data", 0, "version");
    ASSERT_STRNE("", version.c_str());
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
TEST(api, test_two_blocks_limit_page)
{
    Ark::Client arkClient(DEVNET);

    const auto blocksResponse = arkClient.blocks(5, 1);
    auto parser = Ark::Test::Utils::makeJSONString(blocksResponse);

    for (int i = 0; i < 5; i++)
    {
        const auto version = parser->subarrayValueIn("data", i, "version");
        ASSERT_STREQ("0", version.c_str());
    }
}

#endif
