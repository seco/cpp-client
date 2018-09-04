

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_TWO_API

/* test_two_vote_identifier
 * https://dexplorer.ark.io:8443/api/v2/wallets/DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu
 * Expected Response:
    {
    "data": {
        "address": "DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu",
        "publicKey": "023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359",
        "secondPublicKey": null,
        "balance": 97400000000,
        "isDelegate": true
    }
    }
 */
TEST(api, test_two_wallet)
{
    Ark::Client arkClient(DEVNET);

    const auto wallet = arkClient.wallet("DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu");
    auto parser = Ark::Test::Utils::makeJSONString(wallet);

    const auto address = parser->valueIn("data", "address");
    ASSERT_STREQ("DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu", address.c_str());

    const auto publicKey = parser->valueIn("data", "publicKey");
    ASSERT_STREQ("023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359", publicKey.c_str());
    
    const auto balance = parser->valueIn("data", "balance");
    ASSERT_STRNE("0", balance.c_str());
    ASSERT_STRNE("", balance.c_str());

    const auto isDelegate = parser->valueIn("data", "isDelegate");
    ASSERT_STREQ("true", isDelegate.c_str());
}

/* test_two_wallets
 * https://dexplorer.ark.io:8443/api/v2/wallets?limit=5&page=1
 * Expected Response:
{
  "meta": {
    "count": 5,
    "pageCount": 19,
    "totalCount": 94,
    "next": "\/api\/v2\/wallets?limit=5&page=2",
    "previous": null,
    "self": "\/api\/v2\/wallets?limit=5&page=1",
    "first": "\/api\/v2\/wallets?limit=5&page=1",
    "last": "\/api\/v2\/wallets?limit=5&page=19"
  },
  "data": [
    {
      "address": "DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9",
      "publicKey": "03bbfb43ecb5a54a1e227bb37b5812b5321213838d376e2b455b6af78442621dec",
      "secondPublicKey": "02cab2e33ca9ae72a5c0a47202be192bacf39d818004a476ac458877541cc64fe5",
      "balance": 99999400000000,
      "isDelegate": true
    },
    {
      "address": "DRgh1n8oyGHDE6xXVq4yhh3sSajAr7uHJY",
      "publicKey": "03153c994e5306b2fbba9bb533f22871e12e4c1d1d3960d1eeef385ab143b258b4",
      "secondPublicKey": null,
      "balance": 97900000000,
      "isDelegate": true
    },
    {
      "address": "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T",
      "publicKey": "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d",
      "secondPublicKey": null,
      "balance": 97500000000,
      "isDelegate": true
    },
    {
      "address": "DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu",
      "publicKey": "023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359",
      "secondPublicKey": null,
      "balance": 97500000000,
      "isDelegate": true
    },
    {
      "address": "DPWsg7a3LXUaGYb6mbn6pUaidYNqunPdrw",
      "publicKey": "036f1cb6a811173e8d193e41a4ceb77253c3e4f2832e7a4ba3cf3f8f9e606f5f05",
      "secondPublicKey": null,
      "balance": 97500000000,
      "isDelegate": true
    }
  ]
}
 */
TEST(api, test_two_wallets)
{
    Ark::Client arkClient(DEVNET);

    const auto wallets = arkClient.wallets(5, 1);
    auto parser = Ark::Test::Utils::makeJSONString(wallets);

    for (int i = 0; i < 5; i++)
    {
        const auto address = parser->subarrayValueIn("data", i, "address");
        ASSERT_STRNE("", address.c_str());

        const auto publicKey = parser->subarrayValueIn("data", i, "publicKey");
        ASSERT_STRNE("", publicKey.c_str());

        const auto balance = parser->subarrayValueIn("data", i, "balance");
        ASSERT_STRNE("0", balance.c_str());
        ASSERT_STRNE("", balance.c_str());

        const auto isDelegate = parser->subarrayValueIn("data", i, "isDelegate");
        ASSERT_STRNE("", isDelegate.c_str());
    };
}

/* test_two_wallets_search
 *
 * Expected Response:
    {
    "meta": {
        "count": 1,
        "pageCount": 1,
        "totalCount": 1,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/wallets\/search?limit=5&page=1",
        "first": "\/api\/v2\/wallets\/search?limit=5&page=1",
        "last": "\/api\/v2\/wallets\/search?limit=5&page=1"
    },
    "data": [
        {
        "address": "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T",
        "publicKey": "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d",
        "secondPublicKey": null,
        "balance": 532210000000,
        "isDelegate": true
        }
    ]
    }
 */
TEST(api, test_two_wallets_search)
{
    Ark::Client arkClient(DEVNET);

    const auto walletsSearch = arkClient.walletsSearch({"username", "baldninja"});

    auto parser = Ark::Test::Utils::makeJSONString(walletsSearch);

    const auto address = parser->subarrayValueIn("data", 0, "address");
    ASSERT_STREQ("DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T", address.c_str());

    const auto publicKey = parser->subarrayValueIn("data", 0, "publicKey");
    ASSERT_STREQ("03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d", publicKey.c_str());
}

/* test_two_wallets_top_limit_page
 * https://dexplorer.ark.io:8443/api/v2/wallets/top?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": 5,
        "pageCount": 19,
        "totalCount": 94,
        "next": "\/api\/v2\/wallets\/top?limit=5&page=2",
        "previous": null,
        "self": "\/api\/v2\/wallets\/top?limit=5&page=1",
        "first": "\/api\/v2\/wallets\/top?limit=5&page=1",
        "last": "\/api\/v2\/wallets\/top?limit=5&page=19"
    },
    "data": [
        {
        "address": "D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax",
        "publicKey": "03d3fdad9c5b25bf8880e6b519eb3611a5c0b31adebc8455f0e096175b28321aff",
        "secondPublicKey": null,
        "balance": 1.238999997e+16,
        "isDelegate": false
        },
        {
        "address": "DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9",
        "publicKey": "03bbfb43ecb5a54a1e227bb37b5812b5321213838d376e2b455b6af78442621dec",
        "secondPublicKey": "02cab2e33ca9ae72a5c0a47202be192bacf39d818004a476ac458877541cc64fe5",
        "balance": 99999400000000,
        "isDelegate": true
        },
        {
        "address": "DPQgzJ5L1Xb3G1VJBu1vkkk1eD53PhETU9",
        "publicKey": "0300ebc83a90cbf7fe8e87b3241012f43a325a814119ede6554a1d7e49cf65f0d3",
        "secondPublicKey": null,
        "balance": 6799680000000,
        "isDelegate": false
        },
        {
        "address": "DFjEQmsDDCgXV5NWmgscjM4gFYw4XSQfVe",
        "publicKey": null,
        "secondPublicKey": null,
        "balance": 100000000000,
        "isDelegate": false
        },
        {
        "address": "DAYS6o9sA51kMCSaSP216GZ8pomGkRsQiR",
        "publicKey": null,
        "secondPublicKey": null,
        "balance": 100000000000,
        "isDelegate": false
        }
    ]
    }
 */
TEST(api, test_two_wallets_top)
{
    Ark::Client arkClient(DEVNET);

    const auto walletsTop = arkClient.walletsTop(5, 1);
    auto parser = Ark::Test::Utils::makeJSONString(walletsTop);

    const auto count = parser->valueIn("meta", "count");
    ASSERT_STREQ("5", count.c_str());

    const auto pageCount = parser->valueIn("meta", "pageCount");
    ASSERT_STRNE("0", pageCount.c_str());
    ASSERT_STRNE("", pageCount.c_str());

    const auto totalCount = parser->valueIn("meta", "totalCount");
    ASSERT_STRNE("0", totalCount.c_str());
    ASSERT_STRNE("", totalCount.c_str());

    for (int i = 0; i < 5; i++)
    {
        const auto address = parser->subarrayValueIn("data", i, "address");
        ASSERT_STRNE("", address.c_str());

        // const auto publicKey = parser->subarrayValueIn("data", i, "publicKey");
        // ASSERT_STRNE("", publicKey.c_str());

        const auto balance = parser->subarrayValueIn("data", i, "balance");
        ASSERT_STRNE("", balance.c_str());

        const auto isDelegate = parser->subarrayValueIn("data", i, "isDelegate");
        ASSERT_STRNE("", isDelegate.c_str());
    };
}

/* test_two_wallets_transactions
 * https://dexplorer.ark.io:8443/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions?limit=2&page=1
 * Expected Response:
    {
    "meta": {
        "count": 2,
        "pageCount": 2,
        "totalCount": "3",
        "next": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/transactions?limit=2&page=2",
        "previous": null,
        "self": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/transactions?limit=2&page=1",
        "first": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/transactions?limit=2&page=1",
        "last": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/transactions?limit=2&page=2"
    },
    "data": [
        {
        "id": "0f8830b12c65f36ed8ec753d8d4e155b0a5351e7834e2542fd9712954a0f143f",
        "blockId": "14911599679969610348",
        "type": 3,
        "amount": 0,
        "fee": 100000000,
        "sender": "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk",
        "recipient": "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk",
        "signature": "3045022100b445dcd4a36b5a430da000369cb7603fbf8e77464c6f945145518953115aff3a0220339578500533376722b88526323ca8188bd9d11f46a59ac3d12c2737b194b71b",
        "asset": {
            "votes": [
            "+03b12f99375c3b0e4f5f5c7ea74e723f0b84a6f169b47d9105ed2a179f30c82df2"
            ]
        },
        "confirmations": 356,
        "timestamp": {
            "epoch": 45021285,
            "unix": 1535122485,
            "human": "2018-08-24T14:54:45Z"
        }
        },
        {
        "id": "f67aae8047495e9b67c88c7ca919f10332e74c1c3224fa8c47ce1b4066bd00e8",
        "blockId": "17044958519703434496",
        "type": 0,
        "amount": 700000000,
        "fee": 10000000,
        "sender": "D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax",
        "recipient": "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk",
        "signature": "304402202aa803427b662f891d089e26c7d8375c87944d548a3adb5a3e8c91299f6162de02202243c442017664907aa96eee33b6b31afcb4054f4cc065e07af8e937a63c57f6",
        "confirmations": 365,
        "timestamp": {
            "epoch": 45021208,
            "unix": 1535122408,
            "human": "2018-08-24T14:53:28Z"
        }
        }
    ]
    }
 */
TEST(api, test_two_wallets_transactions)
{
    Ark::Client arkClient(DEVNET);

    const auto walletsTransactions = arkClient.walletsTransactions("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 2, 1);
    auto parser = Ark::Test::Utils::makeJSONString(walletsTransactions);

    const auto count = parser->valueIn("meta", "count");
    ASSERT_STREQ("2", count.c_str());

    const auto pageCount = parser->valueIn("meta", "pageCount");
    ASSERT_STRNE("", pageCount.c_str());

    const auto totalCount = parser->valueIn("meta", "totalCount");
    ASSERT_STRNE("", totalCount.c_str());

    const auto id = parser->subarrayValueIn("data", 0, "id");
    ASSERT_STRNE("", id.c_str());

    const auto blockId = parser->subarrayValueIn("data", 0, "blockId");
    ASSERT_STRNE("", blockId.c_str());

    const auto type = parser->subarrayValueIn("data", 0, "type");
    ASSERT_STRNE("", type.c_str());

    const auto amount = parser->subarrayValueIn("data", 0, "amount");
    ASSERT_STRNE("", amount.c_str());

    const auto fee = parser->subarrayValueIn("data", 0, "fee");
    ASSERT_STRNE("", fee.c_str());

    const auto sender = parser->subarrayValueIn("data", 0, "sender");
    ASSERT_STRNE("", sender.c_str());

    const auto recipient = parser->subarrayValueIn("data", 0, "recipient");
    ASSERT_STRNE("", recipient.c_str());

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

/* test_two_wallets_transactions_received
 * https://dexplorer.ark.io:8443/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions/received?limit=2&page=1
 * Expected Response:
    {
    "meta": {
        "count": 0,
        "pageCount": 0,
        "totalCount": 0,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/transactions\/received?limit=2&page=1",
        "first": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/transactions\/received?limit=2&page=1",
        "last": null
    },
    "data": [
        
    ]
    }
 */
TEST(api, test_two_wallets_transactions_received)
{
    Ark::Client arkClient(DEVNET);

    const auto walletsTransactionsReceived = arkClient.walletsTransactionsReceived("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 2, 1);
    auto parser = Ark::Test::Utils::makeJSONString(walletsTransactionsReceived);

    const auto count = parser->valueIn("meta", "count");
    ASSERT_STRNE("0", count.c_str());

    const auto pageCount = parser->valueIn("meta", "pageCount");
    ASSERT_STRNE("0", pageCount.c_str());

    const auto totalCount = parser->valueIn("meta", "totalCount");
    ASSERT_STRNE("0", totalCount.c_str());
}

/* test_two_wallets_transactions_sent
 * https://dexplorer.ark.io:8443/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions/sent?limit=2&page=1
 * Expected Response:
    {
    "meta": {
        "count": 0,
        "pageCount": 0,
        "totalCount": 0,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/transactions\/sent?limit=2&page=1",
        "first": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/transactions\/sent?limit=2&page=1",
        "last": null
    },
    "data": [
        
    ]
    }
 */
TEST(api, test_two_wallets_transactions_sent)
{
    Ark::Client arkClient(DEVNET);

    const auto walletsTransactionsSent = arkClient.walletsTransactionsSent("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 2, 1);
    auto parser = Ark::Test::Utils::makeJSONString(walletsTransactionsSent);

    const auto count = parser->valueIn("meta", "count");
    ASSERT_STRNE("0", count.c_str());

    const auto pageCount = parser->valueIn("meta", "pageCount");
    ASSERT_STRNE("0", pageCount.c_str());

    const auto totalCount = parser->valueIn("meta", "totalCount");
    ASSERT_STRNE("0", totalCount.c_str());
}

/* test_two_wallets_votes
 * https://dexplorer.ark.io:8443/api/v2/wallets/DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9/votes?limit=1&page=1
 * Expected Response:
    {
    "meta": {
        "count": 1,
        "pageCount": 1,
        "totalCount": 1,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/wallets\/DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9\/votes?limit=2&page=1",
        "first": "\/api\/v2\/wallets\/DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9\/votes?limit=2&page=1",
        "last": "\/api\/v2\/wallets\/DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9\/votes?limit=2&page=1"
    },
    "data": [
        {
        "id": "1a5d9e65bca63104bc64b5155aee1f48884a637c6ee5f99e62e60fe9404bf6c7",
        "blockId": "17140518373702680714",
        "type": 3,
        "amount": 0,
        "fee": 100000000,
        "sender": "DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9",
        "recipient": "DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9",
        "signature": "3044022020742302b3719bb70abeb9a619be803990cfaac86e841ce3aff8501ac8fd7e83022056b9f51243c66b26e5589b22fda7c0f9e4ee50330cad17b3db7fdfe00fb10287",
        "asset": {
            "votes": [
            "+03bbfb43ecb5a54a1e227bb37b5812b5321213838d376e2b455b6af78442621dec"
            ]
        },
        "confirmations": 6604,
        "timestamp": {
            "epoch": 44911726,
            "unix": 1535012926,
            "human": "2018-08-23T08:28:46Z"
        }
        }
    ]
    }
 */
TEST(api, test_two_wallets_votes)
{
    Ark::Client arkClient(DEVNET);

    const auto walletsVotes = arkClient.walletsVotes("DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9", 1, 1);
    auto parser = Ark::Test::Utils::makeJSONString(walletsVotes);

    const auto count = parser->valueIn("meta", "count");
    ASSERT_STREQ("1", count.c_str());

    const auto pageCount = parser->valueIn("meta", "pageCount");
    ASSERT_STREQ("1", pageCount.c_str());

    const auto totalCount = parser->valueIn("meta", "totalCount");
    ASSERT_STREQ("1", totalCount.c_str());

    const auto id = parser->subarrayValueIn("data", 0, "id");
    ASSERT_STRNE("", id.c_str());

    const auto blockId = parser->subarrayValueIn("data", 0, "blockId");
    ASSERT_STRNE("", blockId.c_str());

    const auto type = parser->subarrayValueIn("data", 0, "type");
    ASSERT_STRNE("", type.c_str());

    const auto amount = parser->subarrayValueIn("data", 0, "amount");
    ASSERT_STRNE("", amount.c_str());

    const auto fee = parser->subarrayValueIn("data", 0, "fee");
    ASSERT_STRNE("", fee.c_str());

    const auto sender = parser->subarrayValueIn("data", 0, "sender");
    ASSERT_STREQ("DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9", sender.c_str());

    const auto recipient = parser->subarrayValueIn("data", 0, "recipient");
    ASSERT_STRNE("", recipient.c_str());

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

#endif
