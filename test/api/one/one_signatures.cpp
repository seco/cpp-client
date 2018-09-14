

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

#ifdef HAS_ONE_API

TEST(api, test_signature_fees)
{
    Ark::Client arkClient(DEVNET);

    const auto signaturesFeeResponse = arkClient.signaturesFee();

    DynamicJsonBuffer jsonBuffer(signaturesFeeResponse.size());
    JsonObject& root = jsonBuffer.parseObject(signaturesFeeResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const auto signaturesFee = root["fee"].as<unsigned long long>();
    ASSERT_STREQ("500000000", toString(signaturesFee).c_str());
}

#endif
