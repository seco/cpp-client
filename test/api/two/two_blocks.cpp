

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
 * https://dexplorer.ark.io:8443/api/v2/blocks/13114381566690093367/transactions?limit=1&page=1
 * Espected Response:
{
  "meta": {
    "count": 1,
    "pageCount": 1,
    "totalCount": 1,
    "next": null,
    "previous": null,
    "self": "\/api\/v2\/blocks\/13114381566690093367\/transactions?limit=1&page=1",
    "first": "\/api\/v2\/blocks\/13114381566690093367\/transactions?limit=1&page=1",
    "last": "\/api\/v2\/blocks\/13114381566690093367\/transactions?limit=1&page=1"
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
      "confirmations": 119294,
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

    const auto blockTransactionsResponse = arkClient.blockTransactions("13114381566690093367", 1, 1);
    auto parser = Ark::Test::Utils::makeJSONString(blockTransactionsResponse);

    const auto id = parser->subarrayValueIn("data", 0, "id");
    ASSERT_STREQ("3e3817fd0c35bc36674f3874c2953fa3e35877cbcdb44a08bdc6083dbd39d572", id.c_str());

    const auto blockId = parser->subarrayValueIn("data", 0, "blockId");
    ASSERT_STREQ("13114381566690093367", blockId.c_str());

    const auto type = parser->subarrayValueIn("data", 0, "type");
    ASSERT_STREQ("0", type.c_str());

    const auto fee = parser->subarrayValueIn("data", 0, "fee");
    ASSERT_STRNE("", fee.c_str());

    const auto sender = parser->subarrayValueIn("data", 0, "sender");
    ASSERT_STREQ("DLK7ts2DpkbeBjFamuFtHLoDAq5upDhCmf", sender.c_str());

    const auto recipient = parser->subarrayValueIn("data", 0, "recipient");
    ASSERT_STREQ("D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax", recipient.c_str());

    const auto signature = parser->subarrayValueIn("data", 0, "signature");
    ASSERT_STREQ("304402203a3f0f80aad4e0561ae975f241f72a074245f1205d676d290d6e5630ed4c027502207b31fee68e64007c380a4b6baccd4db9b496daef5f7894676586e1347ac30a3b", signature.c_str());

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
 * https://dexplorer.ark.io:8443/api/v2/blocks?limit=1&page=1
 * Expected Response:
    {
    "meta": {
        "count": 1,
        "pageCount": 1,
        "totalCount": 1,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/blocks?limit=1&page=1",
        "first": "\/api\/v2\/blocks?limit=1&page=1",
        "last": "\/api\/v2\/blocks?limit=1&page=1"
    },
    "data": [
        {
        "id": "6492907700717217545",
        "version": 0,
        "height": 119329,
        "previous": "13044306174678084911",
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
            "username": "jarunik",
            "address": "DHsUfWJCvQK87Afd1kUStDr2gmpYdGPtsH",
            "publicKey": "0235d06f70a883b429446d7c461e07b6615feb0c34e152d7caf9f38b13ad4d6009"
        },
        "signature": "30450221009deeb3fdda3590890c9718808910b788dfe24edaf300c7285d07f28fdeb2547002203e7e69300ed601d13f7860cc7d748b00038eb2d57a4e81d45b8642d4e1cb00c7",
        "transactions": 0,
        "timestamp": {
            "epoch": 45993386,
            "unix": 1536094586,
            "human": "2018-09-04T20:56:26Z"
        }
        }
    ]
    }
 */
TEST(api, test_two_blocks)
{
    Ark::Client arkClient(DEVNET);

    const auto blocksResponse = arkClient.blocks(1,1);
    auto parser = Ark::Test::Utils::makeJSONString(blocksResponse);

    const auto version = parser->subarrayValueIn("data", 0, "version");
    ASSERT_STRNE("", version.c_str());
}

/* test_two_blocks_blocks_limit_page
 * https://dexplorer.ark.io:8443/api/v2/blocks?limit=1&page=1
 * Expected Response:
    {
    "meta": {
        "count": 1,
        "pageCount": 1,
        "totalCount": 1,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/blocks?limit=1&page=1",
        "first": "\/api\/v2\/blocks?limit=1&page=1",
        "last": "\/api\/v2\/blocks?limit=1&page=1"
    },
    "data": [
        {
        "id": "6492907700717217545",
        "version": 0,
        "height": 119329,
        "previous": "13044306174678084911",
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
            "username": "jarunik",
            "address": "DHsUfWJCvQK87Afd1kUStDr2gmpYdGPtsH",
            "publicKey": "0235d06f70a883b429446d7c461e07b6615feb0c34e152d7caf9f38b13ad4d6009"
        },
        "signature": "30450221009deeb3fdda3590890c9718808910b788dfe24edaf300c7285d07f28fdeb2547002203e7e69300ed601d13f7860cc7d748b00038eb2d57a4e81d45b8642d4e1cb00c7",
        "transactions": 0,
        "timestamp": {
            "epoch": 45993386,
            "unix": 1536094586,
            "human": "2018-09-04T20:56:26Z"
        }
        }
    ]
    }
 */
TEST(api, test_two_blocks_limit_page)
{
    Ark::Client arkClient(DEVNET);

    const auto blocksResponse = arkClient.blocks(1, 1);
    auto parser = Ark::Test::Utils::makeJSONString(blocksResponse);

    const auto version = parser->subarrayValueIn("data", 0, "version");
    ASSERT_STRNE("", version.c_str());
}

#ifndef USE_IOT
/* test_two_blocks_search
 *
 * Expected Response:
    {
    "meta": {
        "count": 1,
        "pageCount": 1,
        "totalCount": "1",
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/blocks\/search?limit=5&page=1",
        "first": "\/api\/v2\/blocks\/search?limit=5&page=1",
        "last": "\/api\/v2\/blocks\/search?limit=5&page=1"
    },
    "data": [
        {
        "id": "8337447655053578871",
        "version": 0,
        "height": 118783,
        "previous": "6440284271011893973",
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
            "username": "genesis_46",
            "address": "DGKgCQ1srb8HZyr47RqQqMvGZ4cDyr4eMo",
            "publicKey": "029a20963b506afabb2bd805830a46cef8d59218cd88c0dca9d2a0158045b1c3e0"
        },
        "signature": "304402201ec15a9bec30bad58c7d9f5ccf1447bccb36b39901d0b91f09217bb4c3efcf6a02207232bdfe9ab6e4d80eb2668d642b431ca704cf4ba8ce9958cfd202070e31f2c8",
        "transactions": 0,
        "timestamp": {
            "epoch": 45988754,
            "unix": 1536089954,
            "human": "2018-09-04T19:39:14Z"
        }
        }
    ]
    }
 */
TEST(api, test_two_blocks_search)
{
    Ark::Client arkClient(DEVNET);

    const auto walletsSearch = arkClient.blocksSearch({"id", "8337447655053578871"}, 1, 1);

    auto parser = Ark::Test::Utils::makeJSONString(walletsSearch);

    const auto id = parser->subarrayValueIn("data", 0, "id");
    ASSERT_STREQ("8337447655053578871", id.c_str());

    const auto previous = parser->subarrayValueIn("data", 0, "previous");
    ASSERT_STREQ("6440284271011893973", previous.c_str());
}
#endif 

#endif
