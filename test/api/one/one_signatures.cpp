

#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json/json.h"

#if defined(HAS_ONE_API) && !defined(HAS_TWO_API)

TEST(api, test_signature_fees)
{
    ARK::Client arkClient(DEVNET);

    const auto signaturesFeeResponse = arkClient.signaturesFee();
	auto parser = ARK::Test::Utils::makeJSONString(signaturesFeeResponse);

    const auto success = parser->valueFor("success");
	ASSERT_STREQ("true", success.c_str());

	const auto signaturesFee = parser->valueFor("fee");
	ASSERT_STREQ("500000000", signaturesFee.c_str());
	ASSERT_STRNE("", signaturesFee.c_str());
}

#endif