

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#ifdef HAS_ONE_API

TEST(api, test_signature_fees)
{
    Ark::Client arkClient(DEVNET);

    const auto signaturesFeeResponse = arkClient.signaturesFee();

    auto parser = Ark::Test::Utils::JSONParser(signaturesFeeResponse);

    const auto success = parser->getRoot()["success"].as<bool>();
    ASSERT_EQ(1, success);

    const auto signaturesFee = parser->getRoot()["fee"].as<unsigned long long>();
    ASSERT_STREQ("500000000", toString(signaturesFee).c_str());
}

#endif
