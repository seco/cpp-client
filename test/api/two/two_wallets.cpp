

#include "gtest/gtest.h"
#include "arkClient.h"
#include "../test/utils/json/json.h"
#include "utils/helpers.h"

#ifdef HAS_TWO_API

/* test_two_vote_identifier
 * https://dexplorer.ark.io:8443/api/v2/wallets/DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu
 * Expected Response:
    {
    "data": {
        "address": "string",
        "publicKey": "string",
        "secondPublicKey": "string",
        "balance": unsigned long,
        "isDelegate": bool
    }
    }
 */
TEST(api, test_two_wallet)
{
    Ark::Client arkClient(DEVNET);

    const auto wallet = arkClient.wallet("DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu");

    auto parser = Ark::Test::Utils::JSONParser(wallet);

    const auto address = parser->getRoot()["data"]["address"].as<const char*>();
    ASSERT_STREQ("DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu", address);

    const auto publicKey = parser->getRoot()["data"]["publicKey"].as<const char*>();
    ASSERT_STREQ("023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359", publicKey);

    const auto balance = parser->getRoot()["data"]["balance"].as<unsigned long long>();
    ASSERT_STRNE("0", toString(balance).c_str());

    const auto isDelegate = parser->getRoot()["data"]["isDelegate"].as<bool>();
    ASSERT_EQ(1, isDelegate);
}

/* test_two_wallets
 * https://dexplorer.ark.io:8443/api/v2/wallets?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "/api/v2/wallets?limit=5&page=2",
        "previous": "string",
        "self": "/api/v2/wallets?limit=5&page=1",
        "first": "/api/v2/wallets?limit=5&page=1",
        "last": "/api/v2/wallets?limit=5&page=19"
    },
    "data": [
        {
        "address": "string",
        "publicKey": "string",
        "secondPublicKey": "string",
        "balance": unsigned long,
        "isDelegate": bool
        }
    ]
    }
 */
TEST(api, test_two_wallets)
{
    Ark::Client arkClient(DEVNET);

    const auto wallets = arkClient.wallets(5, 1);

    auto parser = Ark::Test::Utils::JSONParser(wallets);

    const auto address = parser->getRoot()["data"][0]["address"].as<const char*>();
    ASSERT_STRNE("", address);

    const auto publicKey = parser->getRoot()["data"][0]["publicKey"].as<const char*>();
    ASSERT_STRNE("", publicKey);

    const auto balance = parser->getRoot()["data"][0]["balance"].as<unsigned long long>();
    ASSERT_STRNE("0", toString(balance).c_str());

    const auto isDelegate = parser->getRoot()["data"][0]["isDelegate"].as<bool>();
    ASSERT_STRNE("", toString(isDelegate).c_str());
}

/* test_two_wallets_search
 *
 * Expected Response:
    ??????????
 */
TEST(api, test_two_wallets_search)
{
    Ark::Client arkClient(DEVNET);

    const auto walletsSearch = arkClient.walletsSearch("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 2, 1);

    auto parser = Ark::Test::Utils::JSONParser(walletsSearch);
}

/* test_two_wallets_top_limit_page
 * https://dexplorer.ark.io:8443/api/v2/wallets/top?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "/api/v2/wallets/top?limit=5&page=2",
        "previous": "string",
        "self": "/api/v2/wallets/top?limit=5&page=1",
        "first": "/api/v2/wallets/top?limit=5&page=1",
        "last": "/api/v2/wallets/top?limit=5&page=19"
    },
    "data": [
        {
        "address": "string",
        "publicKey": "string",
        "secondPublicKey": "string",
        "balance": unsigned long,
        "isDelegate": bool
        }
    ]
    }
 */
TEST(api, test_two_wallets_top)
{
    Ark::Client arkClient(DEVNET);

    const auto walletsTop = arkClient.walletsTop(5, 1);

    auto parser = Ark::Test::Utils::JSONParser(walletsTop);

    const auto count = parser->getRoot()["meta"]["count"].as<int>();
    ASSERT_EQ(5, count);

    const auto pageCount = parser->getRoot()["meta"]["pageCount"].as<int>();
    ASSERT_NE(0, pageCount);

    const auto totalCount = parser->getRoot()["meta"]["totalCount"].as<int>();
    ASSERT_NE(0, totalCount);

    const auto address = parser->getRoot()["data"][0]["address"].as<const char*>();
    ASSERT_STRNE("", address);

    const auto balance = parser->getRoot()["data"][0]["balance"].as<unsigned long long>();
    ASSERT_STRNE("", toString(balance).c_str());

    const auto isDelegate = parser->getRoot()["data"][0]["isDelegate"].as<bool>();
    ASSERT_STRNE("", toString(isDelegate).c_str());
}

/* test_two_wallets_transactions
 * https://dexplorer.ark.io:8443/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions?limit=2&page=1
 * Expected Response:
  {
    "meta": {
      "count": int,
      "pageCount": int,
      "totalCount": "string",
      "next": "/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions?limit=2&page=2",
      "previous": "string",
      "self": "/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions?limit=2&page=1",
      "first": "/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions?limit=2&page=1",
      "last": "/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\transactions?limit=2&page=3"
    },
    "data": [
      {
        "id": "string",
        "blockId": "string",
        "type": int,
        "amount": unsigned long,
        "fee": unsigned long,
        "sender": "string",
        "recipient": "string",
        "signature": "string",
        "confirmations": int,
        "timestamp": {
          "epoch": int,
          "unix": int,
          "human": "string"
        }
      }
    ]
  }
 */
TEST(api, test_two_wallets_transactions)
{
    Ark::Client arkClient(DEVNET);

    const auto walletsTransactions = arkClient.walletsTransactions("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 2, 1);

    auto parser = Ark::Test::Utils::JSONParser(walletsTransactions);

    const auto count = parser->getRoot()["meta"]["count"].as<int>();
    ASSERT_EQ(2, count);
}

/* test_two_wallets_transactions_received
 * https://dexplorer.ark.io:8443/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions/received?limit=2&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions/received?limit=2&page=1",
        "first": "/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions/received?limit=2&page=1",
        "last": "string"
    },
    "data": [

    ]
    }
 */
TEST(api, test_two_wallets_transactions_received)
{
    Ark::Client arkClient(DEVNET);

    const auto walletsTransactionsReceived = arkClient.walletsTransactionsReceived("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 2, 1);

    auto parser = Ark::Test::Utils::JSONParser(walletsTransactionsReceived);

    const auto count = parser->getRoot()["meta"]["count"].as<int>();
    ASSERT_EQ(0, count);

    const auto pageCount = parser->getRoot()["meta"]["pageCount"].as<int>();
    ASSERT_EQ(0, pageCount);

    const auto totalCount = parser->getRoot()["meta"]["totalCount"].as<int>();
    ASSERT_EQ(0, totalCount);
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

    auto parser = Ark::Test::Utils::JSONParser(walletsTransactionsSent);

    const auto count = parser->getRoot()["meta"]["count"].as<int>();
    ASSERT_EQ(0, count);

    const auto pageCount = parser->getRoot()["meta"]["pageCount"].as<int>();
    ASSERT_EQ(0, pageCount);

    const auto totalCount = parser->getRoot()["meta"]["totalCount"].as<int>();
    ASSERT_EQ(0, totalCount);
}

/* test_two_wallets_votes
 * https://dexplorer.ark.io:8443/api/v2/wallets/DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9/votes?limit=1&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/wallets/DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9/votes?limit=2&page=1",
        "first": "/api/v2/wallets/DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9/votes?limit=2&page=1",
        "last": "/api/v2/wallets/DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9/votes?limit=2&page=1"
    },
    "data": [
        {
        "id": "string",
        "blockId": "string",
        "type": int,
        "amount": unsigned long,
        "fee": unsigned long,
        "sender": "string",
        "recipient": "string",
        "signature": "string",
        "asset": {
            "votes": [
            "string"
            ]
        },
        "confirmations": int,
        "timestamp": {
            "epoch": int,
            "unix": int,
            "human": "string"
        }
        }
    ]
    }
 */
TEST(api, test_two_wallets_votes)
{
    Ark::Client arkClient(DEVNET);

    const auto walletsVotes = arkClient.walletsVotes("DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9", 1, 1);
    auto parser = Ark::Test::Utils::JSONParser(walletsVotes);

    const auto count = parser->getRoot()["meta"]["count"].as<int>();
    ASSERT_STRNE("", toString(count).c_str());

    const auto sender = parser->getRoot()["data"][0]["sender"].as<const char*>();
    ASSERT_STRNE("", sender);
}

#endif
