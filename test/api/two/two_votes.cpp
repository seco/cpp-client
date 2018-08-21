

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#if defined(HAS_TWO_API) && !defined(HAS_ONE_API)

/* test_two_vote
 * https://dexplorer.ark.io:8443/api/v2/votes/18226518e7bba7feaf242c1210b868bdd41173e37238a3bb9d78f0462bc760d6
 * Expected Response:
    {
    "data": {
        "id": "18226518e7bba7feaf242c1210b868bdd41173e37238a3bb9d78f0462bc760d6",
        "blockId": "4390658755829814317",
        "type": 3,
        "amount": 0,
        "fee": 100000000,
        "sender": "DFyUhQW52sNB5PZdS7VD9HknwYrSNHPQDq",
        "recipient": "DFyUhQW52sNB5PZdS7VD9HknwYrSNHPQDq",
        "signature": "304402204d5ea100e82177e80bee7745c39f33acdd8fd19a72f3c06952b6d6480a1325c202201b45dce79ab6a1cd4fc121bb5f504718488665fcfd5d1f9c5ed7b557a8508c1d",
        "asset": {
        "votes": [
            "+03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d"
        ]
        },
        "confirmations": 666,
        "timestamp": {
            "epoch": 44693296,
            "unix": 1534794496,
            "human": "2018-08-20T19:48:16Z"
        }
    }
    }
 */
TEST(api, test_two_vote)
{
    ARK::Client arkClient(DEVNET);

    const auto vote = arkClient.vote("18226518e7bba7feaf242c1210b868bdd41173e37238a3bb9d78f0462bc760d6");
    auto parser = ARK::Test::Utils::makeJSONString(vote);

    const auto id = parser->valueIn("data", "id");
    ASSERT_STREQ("18226518e7bba7feaf242c1210b868bdd41173e37238a3bb9d78f0462bc760d6", id.c_str());

    const auto blockId = parser->valueIn("data", "blockId");
    ASSERT_STREQ("4390658755829814317", blockId.c_str());

    const auto type = parser->valueIn("data", "type");
    ASSERT_STREQ("3", type.c_str());

    const auto amount = parser->valueIn("data", "amount");
    ASSERT_STREQ("0", amount.c_str());

    const auto fee = parser->valueIn("data", "fee");
    ASSERT_STREQ("100000000", fee.c_str());

    const auto sender = parser->valueIn("data", "sender");
    ASSERT_STREQ("DFyUhQW52sNB5PZdS7VD9HknwYrSNHPQDq", sender.c_str());

    const auto recipient = parser->valueIn("data", "recipient");
    ASSERT_STREQ("DFyUhQW52sNB5PZdS7VD9HknwYrSNHPQDq", recipient.c_str());

    const auto signature = parser->valueIn("data", "signature");
    ASSERT_STREQ("304402204d5ea100e82177e80bee7745c39f33acdd8fd19a72f3c06952b6d6480a1325c202201b45dce79ab6a1cd4fc121bb5f504718488665fcfd5d1f9c5ed7b557a8508c1d", signature.c_str());


    const auto confirmations = parser->valueIn("data", "confirmations");
    ASSERT_STRNE("0", confirmations.c_str());
    ASSERT_STRNE("", confirmations.c_str());

    const auto epoch = parser->subvalueNestedIn("data", "timestamp", "epoch");
    ASSERT_STREQ("44693296", epoch.c_str());

    const auto unix = parser->subvalueNestedIn("data", "timestamp", "unix");
    ASSERT_STREQ("1534794496", unix.c_str());

    const auto human = parser->subvalueNestedIn("data", "timestamp", "human");
    ASSERT_STREQ("2018-08-20T19:48:16Z", human.c_str());
}

/* test_two_votes
 * https://dexplorer.ark.io:8443/api/v2/votes?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": 5,
        "pageCount": 1,
        "totalCount": 5,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/votes?limit=5&page=1",
        "first": "\/api\/v2\/votes?limit=5&page=1",
        "last": "\/api\/v2\/votes?limit=5&page=1"
    },
    "data": [
        {
        "id": "18226518e7bba7feaf242c1210b868bdd41173e37238a3bb9d78f0462bc760d6",
        "blockId": "4390658755829814317",
        "type": 3,
        "amount": 0,
        "fee": 100000000,
        "sender": "DFyUhQW52sNB5PZdS7VD9HknwYrSNHPQDq",
        "recipient": "DFyUhQW52sNB5PZdS7VD9HknwYrSNHPQDq",
        "signature": "304402204d5ea100e82177e80bee7745c39f33acdd8fd19a72f3c06952b6d6480a1325c202201b45dce79ab6a1cd4fc121bb5f504718488665fcfd5d1f9c5ed7b557a8508c1d",
        "asset": {
            "votes": [
            "+03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d"
            ]
        },
        "confirmations": 623,
        "timestamp": {
            "epoch": 44693296,
            "unix": 1534794496,
            "human": "2018-08-20T19:48:16Z"
        }
        },
        {
        "id": "6ad345a0b9af2f66104a67c679748b0ca23cea334f1ec47336f023cc6140a521",
        "blockId": "12564037700220000953",
        "type": 3,
        "amount": 0,
        "fee": 100000000,
        "sender": "D5vPv4EyVTNw5Ac8Hk31UhZoZPXT4RNGm8",
        "recipient": "D5vPv4EyVTNw5Ac8Hk31UhZoZPXT4RNGm8",
        "signature": "304402201ddedc6e95e50418b8a363166a24ab760c4e4fb0c9cb5ad184269e0b5e3ff0f202205cca60142df9373365a2a525bd804b7832cc15de354b259f1162dc8b84e70053",
        "asset": {
            "votes": [
            "+023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359"
            ]
        },
        "confirmations": 3184,
        "timestamp": {
            "epoch": 44672771,
            "unix": 1534773971,
            "human": "2018-08-20T14:06:11Z"
        }
        },
        {
        "id": "2f7681674b18967505bb0352f75b49ab032ad6013e4543e8acae5d8d07af515f",
        "blockId": "17504991996268691172",
        "type": 3,
        "amount": 0,
        "fee": 100000000,
        "sender": "DPEGnyKEpHfFL7vtbFNFsTgJSk9WoDRvV8",
        "recipient": "DPEGnyKEpHfFL7vtbFNFsTgJSk9WoDRvV8",
        "signature": "3045022100c9de0a702603b065d8e9268d4d4983a559888cbea8654f9c58ef927c6e97dabe02200f950473a0275daca8eafa10eb9da2a06204d3ca10f3496452a0274d0b6a5be9",
        "asset": {
            "votes": [
            "+03120f521f7025f76341a09112f88a6c072411c549e4bfa8c92946fcf1c57cdf1e"
            ]
        },
        "confirmations": 3522,
        "timestamp": {
            "epoch": 44670072,
            "unix": 1534771272,
            "human": "2018-08-20T13:21:12Z"
        }
        },
        {
        "id": "0e42b089d8bfd5a7b8dbc3dc9e5f5654d05ded49e14f7ee58954ffbffc17726f",
        "blockId": "15320581875213568178",
        "type": 3,
        "amount": 0,
        "fee": 100000000,
        "sender": "DJYCDccLefLqmx2faZTo8pXkL6LZFdLnqT",
        "recipient": "DJYCDccLefLqmx2faZTo8pXkL6LZFdLnqT",
        "signature": "3045022100dec90f24627e7bc13aa102b26eacf57d04318bd8765c2a00b484e288302c6abb0220792764033a6ff1dae3012f010d524dec9ae9d574f965edbce489525b9ce16765",
        "asset": {
            "votes": [
            "-023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359"
            ]
        },
        "confirmations": 3701,
        "timestamp": {
            "epoch": 44668637,
            "unix": 1534769837,
            "human": "2018-08-20T12:57:17Z"
        }
        },
        {
        "id": "325a2955c0048f7d5b002604bdd6c93626c30064dc30436d2280800834a93cc1",
        "blockId": "5284762717669130515",
        "type": 3,
        "amount": 0,
        "fee": 100000000,
        "sender": "DEAvUAi8oZzhd6XC4pUV5XSvoxVXSiLDfY",
        "recipient": "DEAvUAi8oZzhd6XC4pUV5XSvoxVXSiLDfY",
        "signature": "304502210096de7bad48bbb89bf323a353fcae51b34a3d4bcc493238d4cdf8747710d107c6022013e50c040957bc03dc4514f95d5ef79b021c9803a79bd4c629763177ae77a1d6",
        "asset": {
            "votes": [
            "+0368dac68e5d9f00244e33aab7b59c36acdecc5eb79ce2ce208f4675970c88ebf8"
            ]
        },
        "confirmations": 11340,
        "timestamp": {
            "epoch": 44607011,
            "unix": 1534708211,
            "human": "2018-08-19T19:50:11Z"
        }
        }
    ]
    }
 */
TEST(api, test_two_votes)
{
    ARK::Client arkClient(DEVNET);

    const auto transactionUnconfirmed = arkClient.votes(5, 1);
    auto parser = ARK::Test::Utils::makeJSONString(transactionUnconfirmed);

    const auto count = parser->valueIn("meta", "count");
    ASSERT_STREQ("5", count.c_str());

    const auto pageCount = parser->valueIn("meta", "pageCount");
    ASSERT_STREQ("1", pageCount.c_str());

    const auto totalCount = parser->valueIn("meta", "totalCount");
    ASSERT_STREQ("5", totalCount.c_str());

    std::stringstream countStream;
    countStream << count;
    int countAsInt = 0;
    countStream >> countAsInt;

    for (int i = 0; i < countAsInt; i++)
    {
        const auto type = parser->subarrayValueIn("data", i, "type");
        ASSERT_STREQ("3", type.c_str());

        const auto fee = parser->subarrayValueIn("data", i, "fee");
        ASSERT_STREQ("100000000", fee.c_str());

        const auto confirmations = parser->subarrayValueIn("data", i, "confirmations");
        ASSERT_STRNE("0", confirmations.c_str());
        ASSERT_STRNE("", confirmations.c_str());
    };
}

#endif
