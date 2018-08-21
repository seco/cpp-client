

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#if defined(HAS_TWO_API) && !defined(HAS_ONE_API)

/* test_two_delegates_delegate
 * https://dexplorer.ark.io:8443/api/v2/delegates/boldninja
 * Expected Response:
    {
        "data": {
            "username": "boldninja",
            "address": "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T",
            "publicKey": "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d",
            "votes": 6619020000000,
            "rank": 2,
            "blocks": {
                "produced": 3251,
                "missed": 145,
                "last": {
                    "id": "4620351536410950551",
                    "timestamp": {
                        "epoch": 44610242,
                        "unix": 1534711442,
                        "human": "2018-08-19T20:44:02Z"
                    }
                }
            },
            "production": {
                "approval": 0.05,
                "productivity": 95.73
            }
        }
    }
 */
TEST(api, test_two_delegates_delegate)
{
    ARK::Client arkClient(DEVNET);

    const auto delegateResponse = arkClient.delegate("boldninja");
    auto parser = ARK::Test::Utils::makeJSONString(delegateResponse);

    const auto username = parser->valueIn("data", "username");
    ASSERT_STREQ("boldninja", username.c_str());

    const auto address = parser->valueIn("data", "address");
    ASSERT_STREQ("DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T", address.c_str());

    const auto publicKey = parser->valueIn("data", "publicKey");
    ASSERT_STREQ("03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d", publicKey.c_str());

    const auto votes = parser->valueIn("data", "votes");
    ASSERT_STRNE("0", votes.c_str());
    ASSERT_STRNE("", votes.c_str());

    const auto rank = parser->valueIn("data", "rank");
    ASSERT_STRNE("0", rank.c_str());
    ASSERT_STRNE("", rank.c_str());

    const auto produced = parser->subvalueNestedIn("data", "blocks", "produced");
    ASSERT_STRNE("0", produced.c_str());
    ASSERT_STRNE("", produced.c_str());

    const auto missed = parser->subvalueNestedIn("data", "blocks", "missed");
    ASSERT_STRNE("0", missed.c_str());
    ASSERT_STRNE("", missed.c_str());

    const auto approval = parser->subvalueNestedIn("data", "production", "approval");
    ASSERT_STRNE("100.00", approval.c_str());
    ASSERT_STRNE("0", approval.c_str());
    ASSERT_STRNE("", approval.c_str());

    const auto productivity = parser->subvalueNestedIn("data", "production", "productivity");
    ASSERT_STRNE("100.00", productivity.c_str());
    ASSERT_STRNE("0.00", productivity.c_str());
    ASSERT_STRNE("", productivity.c_str());
}

/* test_two_delegates_delegates
 * https://dexplorer.ark.io:8443/api/v2/delegates?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": 5,
        "pageCount": 23,
        "totalCount": 111,
        "next": "\/api\/v2\/delegates?limit=5&page=2",
        "previous": null,
        "self": "\/api\/v2\/delegates?limit=5&page=1",
        "first": "\/api\/v2\/delegates?limit=5&page=1",
        "last": "\/api\/v2\/delegates?limit=5&page=23"
    },
    "data": [
        {
        "username": "arkx",
        "address": "DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9",
        "publicKey": "03bbfb43ecb5a54a1e227bb37b5812b5321213838d376e2b455b6af78442621dec",
        "votes": 49565819956800,
        "rank": 1,
        "blocks": {
            "produced": 785,
            "missed": 1,
            "last": {
            "id": "1407421525749284122",
            "timestamp": {
                "epoch": 44610994,
                "unix": 1534712194,
                "human": "2018-08-19T20:56:34Z"
            }
            }
        },
        "production": {
            "approval": 0.4,
            "productivity": 99.87
        }
        },
        {
        "username": "boldninja",
        "address": "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T",
        "publicKey": "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d",
        "votes": 6619620000000,
        "rank": 2,
        "blocks": {
            "produced": 3254,
            "missed": 145,
            "last": {
            "id": "6277036907304685213",
            "timestamp": {
                "epoch": 44611370,
                "unix": 1534712570,
                "human": "2018-08-19T21:02:50Z"
            }
            }
        },
        "production": {
            "approval": 0.05,
            "productivity": 95.73
        }
        },
        {
        "username": "genesis_7",
        "address": "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk",
        "publicKey": "03b12f99375c3b0e4f5f5c7ea74e723f0b84a6f169b47d9105ed2a179f30c82df2",
        "votes": 6153180000000,
        "rank": 3,
        "blocks": {
            "produced": 3439,
            "missed": 6,
            "last": {
            "id": "10247780330689404313",
            "timestamp": {
                "epoch": 44611250,
                "unix": 1534712450,
                "human": "2018-08-19T21:00:50Z"
            }
            }
        },
        "production": {
            "approval": 0.05,
            "productivity": 99.83
        }
        },
        {
        "username": "genesis_8",
        "address": "DEHtM61jVo4uJWP23B6mGrb6p9batXCHZs",
        "publicKey": "02c3d1ae1b8fe831218f78cf09d864e60818ebdba4aacc74ecc2bcf2734aadf5ea",
        "votes": 5648160000000,
        "rank": 4,
        "blocks": {
            "produced": 3440,
            "missed": 7,
            "last": {
            "id": "13083236844605217497",
            "timestamp": {
                "epoch": 44611178,
                "unix": 1534712378,
                "human": "2018-08-19T20:59:38Z"
            }
            }
        },
        "production": {
            "approval": 0.05,
            "productivity": 99.8
        }
        },
        {
        "username": "genesis_13",
        "address": "DLnysb6HbtTcNpff87P5f47qVpFxYAqUSY",
        "publicKey": "02bc4cfee3716fcf191caa51c7bd2205a796b504b9ad5461864681cf1b33912003",
        "votes": 5645170000000,
        "rank": 5,
        "blocks": {
            "produced": 3425,
            "missed": 14,
            "last": {
            "id": "105798996341228290",
            "timestamp": {
                "epoch": 44611162,
                "unix": 1534712362,
                "human": "2018-08-19T20:59:22Z"
            }
            }
        },
        "production": {
            "approval": 0.05,
            "productivity": 99.59
        }
        }
    ]
    }
 */
TEST(api, test_two_delegates_delegates)
{
    ARK::Client arkClient(DEVNET);

    const auto delegates = arkClient.delegates(5, 1);
    auto parser = ARK::Test::Utils::makeJSONString(delegates);

    for (int i = 0; i < 5; i++)
    {
        const auto votes = parser->subarrayValueIn("data", i, "votes");
        ASSERT_STRNE("0", votes.c_str());
        ASSERT_STRNE("", votes.c_str());
    }
}

/* test_two_delegates_delegate_blocks
 * https://dexplorer.ark.io:8443/api/v2/delegates/boldninja/blocks?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": 5,
        "pageCount": 1,
        "totalCount": 5,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/delegates\/boldninja\/blocks?limit=5&page=1",
        "first": "\/api\/v2\/delegates\/boldninja\/blocks?limit=5&page=1",
        "last": "\/api\/v2\/delegates\/boldninja\/blocks?limit=5&page=1"
    },
    "data": [
        {
        "id": "11003556190154909747",
        "version": 0,
        "height": 174712,
        "previous": "15775691670328162143",
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
            "username": "boldninja",
            "address": "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T",
            "publicKey": "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d"
        },
        "signature": "3045022100bef205439941300e30d76c4de711e7790bd5b03da6c169b6d933a6484fb6ce12022074ff7cf07bc4802452d3d8465097c808d47c94c536b3460868825b42255d93dd",
        "transactions": 0,
        "timestamp": {
            "epoch": 44612706,
            "unix": 1534713906,
            "human": "2018-08-19T21:25:06Z"
        }
        },
        {
        "id": "16964905501394728294",
        "version": 0,
        "height": 174675,
        "previous": "3864615187565929961",
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
            "username": "boldninja",
            "address": "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T",
            "publicKey": "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d"
        },
        "signature": "3045022100b7e075cc73319448337d2fcba306bd7797218a4880a3669433155fbe6d45d60702203bcd758663f04941f67bc9f821dbcce6323710d6cbdcf90e6db8c2bde1c62d93",
        "transactions": 0,
        "timestamp": {
            "epoch": 44612402,
            "unix": 1534713602,
            "human": "2018-08-19T21:20:02Z"
        }
        },
        {
        "id": "12143161846897841986",
        "version": 0,
        "height": 174625,
        "previous": "4978530324409851375",
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
            "username": "boldninja",
            "address": "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T",
            "publicKey": "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d"
        },
        "signature": "304402204c611c6f74bccded816758a0a274ad699fa29be09bd48bf74627ab3a5165f7e9022005e769ca9754fee556c3394becb779751713217a2713eea271f6b18999ef4739",
        "transactions": 0,
        "timestamp": {
            "epoch": 44611994,
            "unix": 1534713194,
            "human": "2018-08-19T21:13:14Z"
        }
        },
        {
        "id": "4241049365425510727",
        "version": 0,
        "height": 174598,
        "previous": "226084146696292114",
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
            "username": "boldninja",
            "address": "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T",
            "publicKey": "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d"
        },
        "signature": "3045022100eef59272598a3e70dad3a2a5243806a34b69ce8c8688e78b7f902acca17f887a0220041d446b63b4d7f5212c162b134d127e7e95bfef4760decdeb28915e784605bf",
        "transactions": 0,
        "timestamp": {
            "epoch": 44611778,
            "unix": 1534712978,
            "human": "2018-08-19T21:09:38Z"
        }
        },
        {
        "id": "6277036907304685213",
        "version": 0,
        "height": 174549,
        "previous": "7640845218274067404",
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
            "username": "boldninja",
            "address": "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T",
            "publicKey": "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d"
        },
        "signature": "3044022052e4f061486a7c77cfa66b72f186a958c3aa8b3d3bf78c3b82dd77659bf32ca902206016387a4e75f84cea682b45f62a5835138ff63db58dcfd24eb3c87790a8c73b",
        "transactions": 0,
        "timestamp": {
            "epoch": 44611370,
            "unix": 1534712570,
            "human": "2018-08-19T21:02:50Z"
        }
        }
    ]
    }
 */
TEST(api, test_two_delegates_delegate_blocks)
{
    ARK::Client arkClient(DEVNET);

    const auto delegateBlocksResponse = arkClient.delegateBlocks("boldninja", 5, 1);
    auto parser = ARK::Test::Utils::makeJSONString(delegateBlocksResponse);

    for (int i = 0; i < 5; i++)
    {
        const auto id = parser->subarrayValueIn("data", i, "id");
        ASSERT_STRNE("", id.c_str());

        const auto version = parser->subarrayValueIn("data", i, "version");
        ASSERT_STREQ("0", version.c_str());
        ASSERT_STRNE("", version.c_str());

        const auto height = parser->subarrayValueIn("data", i, "height");
        ASSERT_STRNE("0", height.c_str());
        ASSERT_STRNE("", height.c_str());

        const auto previous = parser->subarrayValueIn("data", i, "previous");
        ASSERT_STRNE("0", previous.c_str());
        ASSERT_STRNE("", previous.c_str());

        const auto username = parser->subarrayValueNestedIn("data", 0, "generator", "username");
        ASSERT_STRNE("boldninja", username.c_str());

        const auto address = parser->subarrayValueNestedIn("data", 0, "generator", "address");
        ASSERT_STRNE("DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T", address.c_str());

        const auto publicKey = parser->subarrayValueNestedIn("data", 0, "generator", "publicKey");
        ASSERT_STRNE("03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d", publicKey.c_str());
    };

}

/* test_two_delegates_delegate_voters
 * https://dexplorer.ark.io:8443/api/v2/delegates/boldninja/voters?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": 4,
        "pageCount": 1,
        "totalCount": 4,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/delegates\/boldninja\/voters?limit=5&page=1",
        "first": "\/api\/v2\/delegates\/boldninja\/voters?limit=5&page=1",
        "last": "\/api\/v2\/delegates\/boldninja\/voters?limit=5&page=1"
    },
    "data": [
        {
        "address": "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T",
        "publicKey": "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d",
        "secondPublicKey": null,
        "balance": 1120930000000,
        "isDelegate": true
        },
        {
        "address": "DMqhs6Nqg9JADzhmwSKgrbzPvUzUZDC13N",
        "publicKey": "03dc68c48eae3ac0253a1988c4b579b44896c7c7aa597324c17f9daade29910d9e",
        "secondPublicKey": null,
        "balance": 499890000000,
        "isDelegate": false
        },
        {
        "address": "DPvic19nurQuoicqTwbn6LDyYsX5yAAu4Y",
        "publicKey": "03d6953a8cf0e95740bcf314892aa0286828fa79bcd32c1fb63b80dccab009d874",
        "secondPublicKey": null,
        "balance": 4999700000000,
        "isDelegate": false
        },
        {
        "address": "DT8rwnKxBziFJEtR4fSAHwv2Nqu4iUjk6K",
        "publicKey": "020914965a956ca4e5f1bb41308d25bea0fc5bff20fc6bdb28e741327d2ef403ea",
        "secondPublicKey": null,
        "balance": 100000000,
        "isDelegate": false
        }
    ]
    }
 */
TEST(api, test_two_delegates_delegate_voters)
{
    ARK::Client arkClient(DEVNET);

    const auto delegateVotersResponse = arkClient.delegateVoters("boldninja", 5, 1);
    auto parser = ARK::Test::Utils::makeJSONString(delegateVotersResponse);

    for (int i = 0; i < 5; i++)
    {
        const auto address = parser->subarrayValueIn("data", i, "address");
        ASSERT_STRNE("", address.c_str());

        const auto publicKey = parser->subarrayValueIn("data", i, "publicKey");
        ASSERT_STRNE("", publicKey.c_str());

        const auto secondPublicKey = parser->subarrayValueIn("data", i, "secondPublicKey");
        ASSERT_STRNE("", secondPublicKey.c_str());

        const auto balance = parser->subarrayValueIn("data", i, "balance");
        ASSERT_STRNE("", balance.c_str());

        const auto isDelegate = parser->subarrayValueIn("data", i, "isDelegate");
        ASSERT_STRNE("", isDelegate.c_str());
    };
}

#endif
