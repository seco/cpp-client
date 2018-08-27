

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_TWO_API

/* test_two_delegates_delegate
 * https://dexplorer.ark.io:8443/api/v2/delegates/boldninja
 * Expected Response:
    {
    "data": {
        "username": "boldninja",
        "address": "DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu",
        "publicKey": "023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359",
        "votes": 97400000000,
        "rank": 2,
        "blocks": {
            "produced": 2,
            "missed": 0,
            "last": {
                    "id": "8419773826740796799",
                    "timestamp": {
                    "epoch": 45023658,
                    "unix": 1535124858,
                    "human": "2018-08-24T15:34:18Z"
                }
            }
        },
        "production": {
            "approval": 0,
            "productivity": 100
        }
    }
    }
 */
TEST(api, test_two_delegate)
{
    Ark::Client arkClient(DEVNET);

    const auto delegateResponse = arkClient.delegate("boldninja");
    auto parser = Ark::Test::Utils::makeJSONString(delegateResponse);

    const auto username = parser->valueIn("data", "username");
    ASSERT_STREQ("boldninja", username.c_str());

    const auto address = parser->valueIn("data", "address");
    ASSERT_STREQ("DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu", address.c_str());

    const auto publicKey = parser->valueIn("data", "publicKey");
    ASSERT_STREQ("023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359", publicKey.c_str());

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
    ASSERT_STRNE("", missed.c_str());

    const auto approval = parser->subvalueNestedIn("data", "production", "approval");
    ASSERT_STRNE("100.00", approval.c_str());
    ASSERT_STRNE("", approval.c_str());

    const auto productivity = parser->subvalueNestedIn("data", "production", "productivity");
    ASSERT_STRNE("", productivity.c_str());
}

/* test_two_delegates_delegate_blocks
 * https://dexplorer.ark.io:8443/api/v2/delegates/boldninja/blocks?limit=3&page=1
 * Expected Response:
    {
    "meta": {
        "count": 2,
        "pageCount": 1,
        "totalCount": 2,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/delegates\/boldninja\/blocks?limit=3&page=1",
        "first": "\/api\/v2\/delegates\/boldninja\/blocks?limit=3&page=1",
        "last": "\/api\/v2\/delegates\/boldninja\/blocks?limit=3&page=1"
    },
    "data": [
        {
        "id": "8419773826740796799",
        "version": 0,
        "height": 341,
        "previous": "12108310298585828947",
        "forged": {
            "reward": 0,
            "fee": 0,
            "total": 0
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "boldninja",
            "address": "DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu",
            "publicKey": "023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359"
        },
        "signature": "304502210095edc2d4f422f80178b8a70defe598e7d11b9bcb19330a2f437a30bd6366657a022079f285f14b3665df2eb94ea2da11b2648178baf8c089e558f5fdc3003684fcbf",
        "transactions": 0,
        "timestamp": {
            "epoch": 45023658,
            "unix": 1535124858,
            "human": "2018-08-24T15:34:18Z"
        }
        },
        {
        "id": "15418666565905655111",
        "version": 0,
        "height": 291,
        "previous": "13351218843284937354",
        "forged": {
            "reward": 0,
            "fee": 0,
            "total": 0
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "boldninja",
            "address": "DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu",
            "publicKey": "023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359"
        },
        "signature": "30450221009803e66ad537db632e6c92758f13bf7b8a3714dbbb2f5f32d8987d17a3638a1f02204f4e9b6ec19477b0865bf93400a676e2e59ff6b27caa429a664f3d78beb53564",
        "transactions": 0,
        "timestamp": {
            "epoch": 45023258,
            "unix": 1535124458,
            "human": "2018-08-24T15:27:38Z"
        }
        }
    ]
    }
 */
TEST(api, test_two_delegate_blocks)
{
    Ark::Client arkClient(DEVNET);

    const auto delegateBlocksResponse = arkClient.delegateBlocks("boldninja", 3, 1);
    auto parser = Ark::Test::Utils::makeJSONString(delegateBlocksResponse);

    const auto id = parser->subarrayValueIn("data", 0, "id");
    ASSERT_STRNE("", id.c_str());

    const auto version = parser->subarrayValueIn("data", 0, "version");
    ASSERT_STRNE("", version.c_str());

    const auto height = parser->subarrayValueIn("data", 0, "height");
    ASSERT_STRNE("0", height.c_str());
    ASSERT_STRNE("", height.c_str());

    const auto previous = parser->subarrayValueIn("data", 0, "previous");
    ASSERT_STRNE("0", previous.c_str());
    ASSERT_STRNE("", previous.c_str());

    const auto username = parser->subarrayValueNestedIn("data", 0, "generator", "username");
    ASSERT_STREQ("boldninja", username.c_str());

    const auto address = parser->subarrayValueNestedIn("data", 0, "generator", "address");
    ASSERT_STREQ("DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu", address.c_str());

    const auto publicKey = parser->subarrayValueNestedIn("data", 0, "generator", "publicKey");
    ASSERT_STREQ("023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359", publicKey.c_str());
}

/* test_two_delegates_delegate_voters
 * https://dexplorer.ark.io:8443/api/v2/delegates/boldninja/voters?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": 1,
        "pageCount": 1,
        "totalCount": 1,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/delegates\/boldninja\/voters?limit=5&page=1",
        "first": "\/api\/v2\/delegates\/boldninja\/voters?limit=5&page=1",
        "last": "\/api\/v2\/delegates\/boldninja\/voters?limit=5&page=1"
    },
    "data": [
        {
        "address": "DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu",
        "publicKey": "023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359",
        "secondPublicKey": null,
        "balance": 97400000000,
        "isDelegate": true
        }
    ]
    }
 */
TEST(api, test_two_delegate_voters)
{
    Ark::Client arkClient(DEVNET);

    const auto delegateVotersResponse = arkClient.delegateVoters("boldninja", 5, 1);
    auto parser = Ark::Test::Utils::makeJSONString(delegateVotersResponse);

    const auto address = parser->subarrayValueIn("data", 0, "address");
    ASSERT_STREQ("DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu", address.c_str());

    const auto publicKey = parser->subarrayValueIn("data", 0, "publicKey");
    ASSERT_STREQ("023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359", publicKey.c_str());

    // const auto secondPublicKey = parser->subarrayValueIn("data", 0, "secondPublicKey");
    // ASSERT_STREQ("", secondPublicKey.c_str());

    // const auto balance = parser->subarrayValueIn("data", 0, "balance");
    // ASSERT_STREQ("97400000000", balance.c_str());

    const auto isDelegate = parser->subarrayValueIn("data", 0, "isDelegate");
    ASSERT_STREQ("true", isDelegate.c_str());

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
TEST(api, test_two_delegates)
{
    Ark::Client arkClient(DEVNET);

    const auto delegates = arkClient.delegates(5, 1);
    auto parser = Ark::Test::Utils::makeJSONString(delegates);

    for (int i = 0; i < 5; i++)
    {
        const auto votes = parser->subarrayValueIn("data", i, "votes");
        ASSERT_STRNE("0", votes.c_str());
        ASSERT_STRNE("", votes.c_str());
    }
}

#endif
