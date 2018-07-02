

#include "api/two_blocks/two_blocks.h"

/*************************************************
* /api/blocks/get?id=_blockID
*
{
    "data": {
        "id": "58328125061111756",
        "version": 0,
        "height": 3035362,
        "previous": "3741191868092856237",
        "forged": {
            "reward": 200000000,
            "fee": 0,
            "total": 200000000
        },
        "payload": {
            "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
            "length": 0
        },
        "generator": {
            "username": "genesis_6",
            "address": "D5e2FzTPqdEHridjzpFZCCVyepAu6Vpmk4",
            "publicKey": "023e577a7b3362e0aba70e6911d230e86d729b4cb640f0e0b25637b812a3e38b53"
        },
        "signature": "3044022047aeb0c9cfbb5709aba4c177009bfdc7804ef597073fb9ca6cb614d7e3d1af2d02207234119d02ca26600ece045c59266945081b4c8237370576aaad7c61a09fe0ad",
        "transactions": 0,
        "timestamp": {
            "epoch": 32816544,
            "unix": 1522917744,
            "human": "2018-04-05T08:42:24Z"
        }
    }
}
**************************************************/
std::string ARK::API::TWO_Blocks::block(
		const char *const blockId
) {
	char uri[80] = { '\0' };
		strcpy(uri, ARK::API::TWO_Paths::TWO_Blocks::blocks);
		strcat(uri, "?id=");
		strcat(uri, blockId);
	return netConnector.callback(uri);
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
{
    "meta": {
        "count": 2,
        "pageCount": 1517682,
        "totalCount": 3035363,
        "next": "/v2/blocks?limit=2&page=2",
        "previous": null,
        "self": "/v2/blocks?limit=2&page=1",
        "first": "/v2/blocks?limit=2&page=1",
        "last": "/v2/blocks?limit=2&page=1517682"
    },
    "data": [
        {
            "id": "6402736103893238690",
            "version": 0,
            "height": 3035363,
            "previous": "58328125061111756",
            "forged": {
                "reward": 200000000,
                "fee": 0,
                "total": 200000000
            },
            "payload": {
                "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
                "length": 0
            },
            "generator": {
                "username": "shawmishrak",
                "address": "D7P41dV7s259L3P7BVPNyqExqNDC7vdfx9",
                "publicKey": "030fa94238eb63db0247a9bd6a3fd810f690b449ee9ce4eb654b94b22875a9a612"
            },
            "signature": "304402204d0dbeb4e71a99a0f128a3480350014f0a9f250818dae908edd15bce99f49be00220257bf240c5d8578e9ffe144e7dbf0c2259d34e6571e6a83402edc01daec6228e",
            "transactions": 0,
            "timestamp": {
                "epoch": 32816552,
                "unix": 1522917752,
                "human": "2018-04-05T08:42:32Z"
            }
        }
    ]
}
*************************************************/
std::string ARK::API::TWO_Blocks::blocks()
{
    return netConnector.callback(ARK::API::TWO_Paths::TWO_Blocks::blocks);
};
/*************************************************/
