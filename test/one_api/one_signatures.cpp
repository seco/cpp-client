

#include "gtest/gtest.h"
#include "arkClient.h"

#ifdef USE_IOT
	#include "utils/json/json.h"
#else
	#include "test/utils/json/json.h"
#endif

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