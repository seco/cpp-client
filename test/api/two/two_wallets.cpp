

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_TWO_API

/* test_two_vote_identifier
 * https://dexplorer.ark.io:8443/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk
 * Expected Response:
    {
    "data": {
        "address": "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk",
        "publicKey": "03b12f99375c3b0e4f5f5c7ea74e723f0b84a6f169b47d9105ed2a179f30c82df2",
        "secondPublicKey": null,
        "balance": 6201980000000,
        "isDelegate": true
    }
    }
 */
TEST(api, test_two_wallet)
{
    Ark::V2::Client arkClient(DEVNET);

    const auto wallet = arkClient.wallet("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk");
    auto parser = Ark::Test::Utils::makeJSONString(wallet);

    const auto address = parser->valueIn("data", "address");
    ASSERT_STREQ("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", address.c_str());

    const auto publicKey = parser->valueIn("data", "publicKey");
    ASSERT_STREQ("03b12f99375c3b0e4f5f5c7ea74e723f0b84a6f169b47d9105ed2a179f30c82df2", publicKey.c_str());

    const auto balance = parser->valueIn("data", "balance");
    ASSERT_STRNE("0", balance.c_str());
    ASSERT_STRNE("", balance.c_str());

    const auto isDelegate = parser->valueIn("data", "isDelegate");
    ASSERT_STREQ("true", isDelegate.c_str());
}

/* test_two_wallets
 * https://dexplorer.ark.io:8443/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk?limit=5&page=1
 * Expected Response:
    {
    "data": {
        "address": "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk",
        "publicKey": "03b12f99375c3b0e4f5f5c7ea74e723f0b84a6f169b47d9105ed2a179f30c82df2",
        "secondPublicKey": null,
        "balance": 6201980000000,
        "isDelegate": true
    }
    }
 */
TEST(api, test_two_wallets)
{
    Ark::V2::Client arkClient(DEVNET);

    const auto wallets = arkClient.wallets("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 5, 1);
    auto parser = Ark::Test::Utils::makeJSONString(wallets);

    const auto address = parser->valueIn("data", "address");
    ASSERT_STREQ("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", address.c_str());

    const auto publicKey = parser->valueIn("data", "publicKey");
    ASSERT_STREQ("03b12f99375c3b0e4f5f5c7ea74e723f0b84a6f169b47d9105ed2a179f30c82df2", publicKey.c_str());

    const auto balance = parser->valueIn("data", "balance");
    ASSERT_STRNE("0", balance.c_str());
    ASSERT_STRNE("", balance.c_str());

    const auto isDelegate = parser->valueIn("data", "isDelegate");
    ASSERT_STREQ("true", isDelegate.c_str());
}

/* test_two_wallets_top_limit_page
 * https://dexplorer.ark.io:8443/api/v2/wallets/top?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": 5,
        "pageCount": 236,
        "totalCount": 1180,
        "next": "\/api\/v2\/wallets\/top?limit=5&page=2",
        "previous": null,
        "self": "\/api\/v2\/wallets\/top?limit=5&page=1",
        "first": "\/api\/v2\/wallets\/top?limit=5&page=1",
        "last": "\/api\/v2\/wallets\/top?limit=5&page=236"
    },
    "data": [
        {
        "address": "D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax",
        "publicKey": "03d3fdad9c5b25bf8880e6b519eb3611a5c0b31adebc8455f0e096175b28321aff",
        "secondPublicKey": null,
        "balance": 1.208855698e+16,
        "isDelegate": false
        },
        {
        "address": "DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9",
        "publicKey": "03bbfb43ecb5a54a1e227bb37b5812b5321213838d376e2b455b6af78442621dec",
        "secondPublicKey": "02657b7361958eccfb509ec52546b9780f684afb85a4454683764f7bd54d39959b",
        "balance": 49615609956800,
        "isDelegate": true
        },
        {
        "address": "DN8nGwcNbE3YcnZYFp8uvvc9z4WWDbytWK",
        "publicKey": "02bc95db1324da240d83273d239c2f98e59f45b17f1aab6ec4d76b144c2442e87b",
        "secondPublicKey": null,
        "balance": 43399880000000,
        "isDelegate": false
        },
        {
        "address": "DT12wG2UnqfaiV8H9a4FuAsjJz5Xa7U689",
        "publicKey": "02a5d79153131348c43fbbf8549225b5309c98df80bff1eda165702661ecffad02",
        "secondPublicKey": null,
        "balance": 14999800000000,
        "isDelegate": false
        },
        {
        "address": "DPQgzJ5L1Xb3G1VJBu1vkkk1eD53PhETU9",
        "publicKey": "0300ebc83a90cbf7fe8e87b3241012f43a325a814119ede6554a1d7e49cf65f0d3",
        "secondPublicKey": null,
        "balance": 11453250000000,
        "isDelegate": false
        }
    ]
    }
 */
TEST(api, test_two_wallets_top)
{
    Ark::V2::Client arkClient(DEVNET);

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

        const auto publicKey = parser->subarrayValueIn("data", i, "publicKey");
        ASSERT_STRNE("", publicKey.c_str());

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
        "totalCount": "4",
        "next": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/transactions?limit=2&page=2",
        "previous": null,
        "self": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/transactions?limit=2&page=1",
        "first": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/transactions?limit=2&page=1",
        "last": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/transactions?limit=2&page=2"
    },
    "data": [
        {
        "id": "f2b1f2405fe6329522e604cee9a5de6d744fdf047ea8ee6df37acc745ea29c96",
        "blockId": "7112417164590428814",
        "type": 0,
        "amount": 5500000000000,
        "fee": 10000000,
        "sender": "D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax",
        "recipient": "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk",
        "signature": "3043022016e1250299706043c7436de979fbef10f00c0275d40a0eba0ba66136ca0c4a40021f1c789e087bace52d6ab345945634db1da6879de001d92b56f843ae1cc155bb",
        "confirmations": 161533,
        "timestamp": {
            "epoch": 43405581,
            "unix": 1533506781,
            "human": "2018-08-05T22:06:21Z"
        }
        },
        {
        "id": "eae0711f7cc6ba1028996a434af62f4594c83435b5e67622d76308cd47734d09",
        "blockId": "10509273630282971045",
        "type": 3,
        "amount": 0,
        "fee": 100000000,
        "sender": "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk",
        "recipient": "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk",
        "signature": "3044022016967baa95af24e6bd8b56d880f8b3097c8632a974608b0d3970ce4ea3c5a696022074c85af7a00b2ddcee8dc76de58042c24d27256edb7c25aa7c22941772a5ad96",
        "asset": {
            "votes": [
            "+03b12f99375c3b0e4f5f5c7ea74e723f0b84a6f169b47d9105ed2a179f30c82df2"
            ]
        },
        "confirmations": 182979,
        "timestamp": {
            "epoch": 43232419,
            "unix": 1533333619,
            "human": "2018-08-03T22:00:19Z"
        }
        }
    ]
    }
 */
TEST(api, test_two_wallets_transactions)
{
    Ark::V2::Client arkClient(DEVNET);

    const auto walletsTransactions = arkClient.walletsTransactions("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 2, 1);
    auto parser = Ark::Test::Utils::makeJSONString(walletsTransactions);

    const auto count = parser->valueIn("meta", "count");
    ASSERT_STREQ("2", count.c_str());

    const auto pageCount = parser->valueIn("meta", "pageCount");
    ASSERT_STREQ("2", pageCount.c_str());

    const auto totalCount = parser->valueIn("meta", "totalCount");
    ASSERT_STREQ("4", totalCount.c_str());

    for (int i = 0; i < 2; i++)
    {
        const auto id = parser->subarrayValueIn("data", i, "id");
        ASSERT_STRNE("", id.c_str());

        const auto type = parser->subarrayValueIn("data", i, "type");
        ASSERT_STRNE("", type.c_str());

        const auto amount = parser->subarrayValueIn("data", i, "amount");
        ASSERT_STRNE("", amount.c_str());

        const auto fee = parser->subarrayValueIn("data", i, "fee");
        ASSERT_STRNE("", fee.c_str());

        const auto sender = parser->subarrayValueIn("data", i, "sender");
        ASSERT_STRNE("", sender.c_str());

        const auto recipient = parser->subarrayValueIn("data", i, "recipient");
        ASSERT_STREQ("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", recipient.c_str());

        const auto signature = parser->subarrayValueIn("data", i, "signature");
        ASSERT_STRNE("", signature.c_str());

        const auto confirmations = parser->subarrayValueIn("data", i, "confirmations");
        ASSERT_STRNE("0", confirmations.c_str());
        ASSERT_STRNE("", confirmations.c_str());

        const auto epoch = parser->subarrayValueNestedIn("data", i, "timestamp", "epoch");
        ASSERT_STRNE("", epoch.c_str());

        const auto timestampUnix = parser->subarrayValueNestedIn("data", i, "timestamp", "unix");
        ASSERT_STRNE("", timestampUnix.c_str());

        const auto human = parser->subarrayValueNestedIn("data", i, "timestamp", "human");
        ASSERT_STRNE("", human.c_str());
    };
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
    Ark::V2::Client arkClient(DEVNET);

    const auto walletsTransactionsReceived = arkClient.walletsTransactionsReceived("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 2, 1);
    auto parser = Ark::Test::Utils::makeJSONString(walletsTransactionsReceived);

    const auto count = parser->valueIn("meta", "count");
    ASSERT_STREQ("0", count.c_str());

    const auto pageCount = parser->valueIn("meta", "pageCount");
    ASSERT_STREQ("0", pageCount.c_str());

    const auto totalCount = parser->valueIn("meta", "totalCount");
    ASSERT_STREQ("0", totalCount.c_str());
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
    Ark::V2::Client arkClient(DEVNET);

    const auto walletsTransactionsSent = arkClient.walletsTransactionsSent("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 2, 1);
    auto parser = Ark::Test::Utils::makeJSONString(walletsTransactionsSent);

    const auto count = parser->valueIn("meta", "count");
    ASSERT_STREQ("0", count.c_str());

    const auto pageCount = parser->valueIn("meta", "pageCount");
    ASSERT_STREQ("0", pageCount.c_str());

    const auto totalCount = parser->valueIn("meta", "totalCount");
    ASSERT_STREQ("0", totalCount.c_str());

}



/* test_two_wallets_votes
 * https://dexplorer.ark.io:8443/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/votes?limit=2&page=1
 * Expected Response:
    {
    "meta": {
        "count": 1,
        "pageCount": 1,
        "totalCount": 1,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/votes?limit=2&page=1",
        "first": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/votes?limit=2&page=1",
        "last": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/votes?limit=2&page=1"
    },
    "data": [
        {
        "id": "eae0711f7cc6ba1028996a434af62f4594c83435b5e67622d76308cd47734d09",
        "blockId": "10509273630282971045",
        "type": 3,
        "amount": 0,
        "fee": 100000000,
        "sender": "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk",
        "recipient": "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk",
        "signature": "3044022016967baa95af24e6bd8b56d880f8b3097c8632a974608b0d3970ce4ea3c5a696022074c85af7a00b2ddcee8dc76de58042c24d27256edb7c25aa7c22941772a5ad96",
        "asset": {
            "votes": [
            "+03b12f99375c3b0e4f5f5c7ea74e723f0b84a6f169b47d9105ed2a179f30c82df2"
            ]
        },
        "confirmations": 183009,
        "timestamp": {
            "epoch": 43232419,
            "unix": 1533333619,
            "human": "2018-08-03T22:00:19Z"
        }
        }
    ]
    }
 */
TEST(api, test_two_wallets_votes)
{
    Ark::V2::Client arkClient(DEVNET);

    const auto walletsVotes = arkClient.walletsVotes("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 1, 1);
    auto parser = Ark::Test::Utils::makeJSONString(walletsVotes);

    const auto count = parser->valueIn("meta", "count");
    ASSERT_STREQ("1", count.c_str());

    const auto pageCount = parser->valueIn("meta", "pageCount");
    ASSERT_STREQ("1", pageCount.c_str());

    const auto totalCount = parser->valueIn("meta", "totalCount");
    ASSERT_STREQ("1", totalCount.c_str());

    for (int i = 0; i < 1; i++)
    {
        const auto id = parser->subarrayValueIn("data", i, "id");
        ASSERT_STREQ("eae0711f7cc6ba1028996a434af62f4594c83435b5e67622d76308cd47734d09", id.c_str());

        const auto blockId = parser->subarrayValueIn("data", i, "blockId");
        ASSERT_STREQ("10509273630282971045", blockId.c_str());

        const auto type = parser->subarrayValueIn("data", i, "type");
        ASSERT_STREQ("3", type.c_str());

        const auto amount = parser->subarrayValueIn("data", i, "amount");
        ASSERT_STREQ("0", amount.c_str());

        const auto fee = parser->subarrayValueIn("data", i, "fee");
        ASSERT_STREQ("100000000", fee.c_str());

        const auto sender = parser->subarrayValueIn("data", i, "sender");
        ASSERT_STREQ("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", sender.c_str());

        const auto recipient = parser->subarrayValueIn("data", i, "recipient");
        ASSERT_STREQ("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", recipient.c_str());

        const auto signature = parser->subarrayValueIn("data", i, "signature");
        ASSERT_STREQ("3044022016967baa95af24e6bd8b56d880f8b3097c8632a974608b0d3970ce4ea3c5a696022074c85af7a00b2ddcee8dc76de58042c24d27256edb7c25aa7c22941772a5ad96", signature.c_str());
    
        const auto confirmations = parser->subarrayValueIn("data", i, "confirmations");
        ASSERT_STRNE("0", confirmations.c_str());
        ASSERT_STRNE("", confirmations.c_str());

        const auto epoch = parser->subarrayValueNestedIn("data", i, "timestamp", "epoch");
        ASSERT_STREQ("43232419", epoch.c_str());

        const auto timestampUnix = parser->subarrayValueNestedIn("data", i, "timestamp", "unix");
        ASSERT_STREQ("1533333619", timestampUnix.c_str());

        const auto human = parser->subarrayValueNestedIn("data", i, "timestamp", "human");
        ASSERT_STREQ("2018-08-03T22:00:19Z", human.c_str());
    };
}

/* test_two_wallets_search
 *
 * Expected Response:
    ??????????
 */
TEST(api, test_two_wallets_search)
{
    Ark::V2::Client arkClient(DEVNET);

    const auto walletsSearch = arkClient.walletsSearch("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 2, 1);
    auto parser = Ark::Test::Utils::makeJSONString(walletsSearch);

}

#endif
