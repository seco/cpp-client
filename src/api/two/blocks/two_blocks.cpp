

#include "api/two/blocks/two_blocks.h"

std::string ARK::API::TWO::Blocks::block(
		const char *const blockId
) {
	char uri[80] = { '\0' };
		strcpy(uri, ARK::API::TWO::Paths::Blocks::base);
		strcat(uri, "/");
		strcat(uri, blockId);
	return netConnector.callback(uri);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Blocks::blocks(
        const unsigned int limit,
        const unsigned int page
) {
    char parameters[2][1];
		sprintf(parameters[0], "%d", limit);
		sprintf(parameters[1], "%d", page);
    char uri[80] = { '\0' };
    	strcpy(uri, ARK::API::TWO::Paths::Blocks::base);
        strcat(uri, "?limit=");
		strcat(uri, parameters[0]);
        strcat(uri, "&page=");
		strcat(uri, parameters[1]);
    return netConnector.callback(uri);
};


