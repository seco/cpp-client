

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#if defined(HAS_TWO_API) && !defined(HAS_ONE_API)

/* test_two_transactions_transaction
 * https://dexplorer.ark.io:8443/api/v2/transactions/26394cc3d609edec346151a21cce24e6aea09ecc95812dd1a86fff46732466fa
 * Expected Response:
    {
    "data": {
        "id": "26394cc3d609edec346151a21cce24e6aea09ecc95812dd1a86fff46732466fa",
        "blockId": "127299823224199004",
        "type": 0,
        "amount": 100000000,
        "fee": 10000000,
        "sender": "DFyUhQW52sNB5PZdS7VD9HknwYrSNHPQDq",
        "recipient": "DFyUhQW52sNB5PZdS7VD9HknwYrSNHPQDq",
        "signature": "304402207536fe55d98fda006739596527fd3016238e27bcbea3e708456071e6d71ec54102202adea25988f3159b00d1a19290817a306d6162c0beb7bac9707cc1139309677e",
        "confirmations": 1743,
        "timestamp": {
            "epoch": 44678050,
            "unix": 1534779250,
            "human": "2018-08-20T15:34:10Z"
        }
    }
    }
 */
TEST(api, test_two_transactions_transaction)
{
    ARK::Client arkClient(DEVNET);

    const auto transaction = arkClient.transaction("26394cc3d609edec346151a21cce24e6aea09ecc95812dd1a86fff46732466fa");
    auto parser = ARK::Test::Utils::makeJSONString(transaction);

    const auto id = parser->valueIn("data", "id");
    ASSERT_STREQ("26394cc3d609edec346151a21cce24e6aea09ecc95812dd1a86fff46732466fa", id.c_str());

    const auto blockId = parser->valueIn("data", "blockId");
    ASSERT_STREQ("127299823224199004", blockId.c_str());

    const auto type = parser->valueIn("data", "type");
    ASSERT_STREQ("0", type.c_str());

    const auto amount = parser->valueIn("data", "amount");
    ASSERT_STREQ("100000000", amount.c_str());

    const auto fee = parser->valueIn("data", "fee");
    ASSERT_STREQ("10000000", fee.c_str());

    const auto sender = parser->valueIn("data", "sender");
    ASSERT_STREQ("DFyUhQW52sNB5PZdS7VD9HknwYrSNHPQDq", sender.c_str());

    const auto recipient = parser->valueIn("data", "recipient");
    ASSERT_STREQ("DFyUhQW52sNB5PZdS7VD9HknwYrSNHPQDq", recipient.c_str());

    const auto signature = parser->valueIn("data", "signature");
    ASSERT_STREQ("304402207536fe55d98fda006739596527fd3016238e27bcbea3e708456071e6d71ec54102202adea25988f3159b00d1a19290817a306d6162c0beb7bac9707cc1139309677e", signature.c_str());

    const auto confirmations = parser->valueIn("data", "confirmations");
    ASSERT_STRNE("0", confirmations.c_str());
    ASSERT_STRNE("", confirmations.c_str());

    const auto epoch = parser->subvalueNestedIn("data", "timestamp", "epoch");
    ASSERT_STREQ("44678050", epoch.c_str());

    const auto timestampUnix = parser->subvalueNestedIn("data", "timestamp", "unix");
    ASSERT_STREQ("1534779250", timestampUnix.c_str());

    const auto human = parser->subvalueNestedIn("data", "timestamp", "human");
    ASSERT_STREQ("2018-08-20T15:34:10Z", human.c_str());
}

/* test_two_transactions_transaction_unconfirmed
 * https://dexplorer.ark.io:8443/api/v2/transactions/unconfirmed?id=4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48
 * Expected Response (if unconfirmed tx is not found):
    {
    "meta": {
        "count": 0,
        "pageCount": 0,
        "totalCount": 0,
        "next": null,
        "previous": null,
        "self": "/api/v2/transactions/unconfirmed?id=4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48&page=1&limit=100",
        "first": "/api/v2/transactions/unconfirmed?id=4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48&page=1&limit=100",
        "last": null
    },
    "data": [
        
    ]
    }
 */
TEST(api, test_two_transactions_transaction_unconfirmed)
{
    ARK::Client arkClient(DEVNET);

    const auto transactionUnconfirmed = arkClient.transactionUnconfirmed("4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48");
    auto parser = ARK::Test::Utils::makeJSONString(transactionUnconfirmed);

    const auto count = parser->valueIn("meta", "count");
    ASSERT_STREQ("0", count.c_str());

    const auto pageCount = parser->valueIn("meta", "pageCount");
    ASSERT_STREQ("0", pageCount.c_str());

    const auto totalCount = parser->valueIn("meta", "totalCount");
    ASSERT_STREQ("0", totalCount.c_str());
}

/* test_two_transactions_transactions
 * https://dexplorer.ark.io:8443/api/v2/transactions?limit=2&page=1
 * Expected Response:
    {
    "meta": {
        "count": 2,
        "pageCount": 1,
        "totalCount": 2,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/transactions?limit=2&page=1",
        "first": "\/api\/v2\/transactions?limit=2&page=1",
        "last": "\/api\/v2\/transactions?limit=2&page=1"
    },
    "data": [
        {
        "id": "9a9b426dd2235c40308c8c38e16efc6a2061c2ddb2f7829137644f862f23c90d",
        "blockId": "9434878319695212490",
        "type": 0,
        "amount": 1000,
        "fee": 10000000,
        "sender": "DRgh1n8oyGHDE6xXVq4yhh3sSajAr7uHJY",
        "recipient": "D5rHMAmTXVbG7HVF3NvTN3ghpWGEii5mH2",
        "signature": "304402203dda39ea5ffee599f44863b24c507c8c5e7e4c939a09aae87818f7b8beaa965202207ce34dfcb6e7d5626957b34539a213cc50f5b129b48d3708b1d69ecc996489ee",
        "vendorField": "ahoy",
        "confirmations": 31,
        "timestamp": {
            "epoch": 44692077,
            "unix": 1534793277,
            "human": "2018-08-20T19:27:57Z"
        }
        },
        {
        "id": "7256f578aae1a1b4c403924ff7ad5d7e077b070be063c48363b4ff7bc654683e",
        "blockId": "3243674192852730252",
        "type": 0,
        "amount": 100000000,
        "fee": 10000000,
        "sender": "DFyUhQW52sNB5PZdS7VD9HknwYrSNHPQDq",
        "recipient": "DFyUhQW52sNB5PZdS7VD9HknwYrSNHPQDq",
        "signature": "304402207a8f4fe0d00f381071a3280a12c5fa9bd0b674d7ec0e19ba448c676a865eb5a70220040c1cd31daf45a46b53e0d56ca8a6ffbf706c50d8302f693b097968e30c9bd1",
        "confirmations": 1781,
        "timestamp": {
            "epoch": 44678100,
            "unix": 1534779300,
            "human": "2018-08-20T15:35:00Z"
        }
        }
    ]
    }
 */
TEST(api, test_two_transactions_transactions)
{
    ARK::Client arkClient(DEVNET);

    const auto transactions = arkClient.transactions(2, 1);
    auto parser = ARK::Test::Utils::makeJSONString(transactions);

    const auto count = parser->valueIn("meta", "count");
    ASSERT_STREQ("2", count.c_str());

    const auto pageCount = parser->valueIn("meta", "pageCount");
    ASSERT_STREQ("1", pageCount.c_str());

    const auto totalCount = parser->valueIn("meta", "totalCount");
    ASSERT_STREQ("2", totalCount.c_str());

    for (int i = 0; i < 2; i++)
    {
        const auto type = parser->subarrayValueIn("data", i, "type");
        ASSERT_STREQ("0", type.c_str());

        const auto fee = parser->subarrayValueIn("data", i, "fee");
        ASSERT_STRNE("", fee.c_str());

        const auto confirmations = parser->subarrayValueIn("data", i, "confirmations");
        ASSERT_STRNE("0", confirmations.c_str());
        ASSERT_STRNE("", confirmations.c_str());
    };
}

/* test_two_transactions_transactions_unconfirmed
 * https://dexplorer.ark.io:8443/api/v2/transactions/unconfirmed?limit=2&page=1
 * Expected Response (if unconfirmed tx is not found):
    {
    "meta": {
        "count": 0,
        "pageCount": 0,
        "totalCount": 0,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/transactions\/unconfirmed?limit=2&page=1",
        "first": "\/api\/v2\/transactions\/unconfirmed?limit=2&page=1",
        "last": null
    },
    "data": [
        
    ]
    }
 */
TEST(api, test_two_transactions_transactions_unconfirmed)
{
    ARK::Client arkClient(DEVNET);

    const auto transactionsUnconfirmed = arkClient.transactionsUnconfirmed(5, 1);
    auto parser = ARK::Test::Utils::makeJSONString(transactionsUnconfirmed);

    const auto count = parser->valueIn("meta", "count");
    ASSERT_STREQ("0", count.c_str());

    const auto pageCount = parser->valueIn("meta", "pageCount");
    ASSERT_STREQ("0", pageCount.c_str());

    const auto totalCount = parser->valueIn("meta", "totalCount");
    ASSERT_STREQ("0", totalCount.c_str());

}

/* test_two_transactions_transactions_search
 * 
 * Expected Response:
    ??????????
 */
TEST(api, test_two_transactions_transactions_search)
{
    ARK::Client arkClient(DEVNET);

    const auto transactions = arkClient.transactions("4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48", 5, 1);
    auto parser = ARK::Test::Utils::makeJSONString(transactions);

}

/* test_two_transactions_transaction_types
 * https://dexplorer.ark.io:8443/api/v2/transactions/types
 * Expected Response:
    {
        "data": {
            "TRANSFER": 0,
            "SECOND_SIGNATURE": 1,
            "DELEGATE_REGISTRATION": 2,
            "VOTE": 3,
            "MULTI_SIGNATURE": 4,
            "IPFS": 5,
            "TIMELOCK_TRANSFER": 6,
            "MULTI_PAYMENT": 7,
            "DELEGATE_RESIGNATION": 8
        }
    }
 */
TEST(api, test_two_transactions_transaction_types)
{
    ARK::Client arkClient(DEVNET);

    const auto types = arkClient.transactionTypes();
    auto parser = ARK::Test::Utils::makeJSONString(types);

    const auto TRANSFER = parser->valueIn("data", "TRANSFER");
    ASSERT_STREQ("0", TRANSFER.c_str());

    const auto SECOND_SIGNATURE = parser->valueIn("data", "SECOND_SIGNATURE");
    ASSERT_STREQ("1", SECOND_SIGNATURE.c_str());

    const auto DELEGATE_REGISTRATION = parser->valueIn("data", "DELEGATE_REGISTRATION");
    ASSERT_STREQ("2", DELEGATE_REGISTRATION.c_str());

    const auto VOTE = parser->valueIn("data", "VOTE");
    ASSERT_STREQ("3", VOTE.c_str());

    const auto MULTI_SIGNATURE = parser->valueIn("data", "MULTI_SIGNATURE");
    ASSERT_STREQ("4", MULTI_SIGNATURE.c_str());

    const auto IPFS = parser->valueIn("data", "IPFS");
    ASSERT_STREQ("5", IPFS.c_str());

    const auto TIMELOCK_TRANSFER = parser->valueIn("data", "TIMELOCK_TRANSFER");
    ASSERT_STREQ("6", TIMELOCK_TRANSFER.c_str());

    const auto MULTI_PAYMENT = parser->valueIn("data", "MULTI_PAYMENT");
    ASSERT_STREQ("7", MULTI_PAYMENT.c_str());

    const auto DELEGATE_RESIGNATION = parser->valueIn("data", "DELEGATE_RESIGNATION");
    ASSERT_STREQ("8", DELEGATE_RESIGNATION.c_str());
}

#endif
