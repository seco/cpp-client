

#ifndef TWO_BLOCKS_H
#define TWO_BLOCKS_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/two/two_paths.h"

namespace ARK
{
namespace API
{
namespace V2
{
/*************************************************
* PUBLIC: ARK::API::V2::Blocks
* virtual ARK::Utilities::Network::Connectable
*    
* API's Blocks Model
**************************************************/
class Blocks :
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		* /api/blocks/58328125061111756
		*
		* @param: const char *const blockId
		* @return: std::string
		*
		* @brief: Uses Block ID to get that Blocks information from a Node via API.
		**************************************************/
		std::string block(const char *const blockId);
		/*************************************************/

		/**************************************************************************************************/
		
		/*************************************************
		* /api/blocks?limit=20&page=1
		*
		* @return: std::string
		*
		* @brief: `/api/blocks` is too large for MCU's, so lets limit to the most recent 20
		**************************************************/
		std::string blocks();
		/*************************************************/

		/**************************************************************************************************/
		
		/*************************************************
		* /api/blocks?limit=20&page=1
		*
		* @return: std::string
		*
		* @brief: `/api/blocks` is too large for MCU's, so lets limit to the most recent 20
		**************************************************/
		std::string blocks(const char *const limit, const char *const page);
		/*************************************************/
};
/*************************************************/
};
};
};

#endif


// https://node1.arknet.cloud/api//blocks/search

// QUERY PARAMS

// page int32 1
// limit int32 100

// BODY PARAMS	

// id string
// version string
// previousBlock string
// payloadHash string
// generatorPublicKey string
// blockSignature string
// timestamp object
// timestamp.from integer 0
// timestamp.to integer 0
// height object
// height.from integer 0
// height.to integer 0
// numberOfTransactions object
// numberOfTransactions.from integer 0
// numberOfTransactions.to integer 0
// totalAmount object
// totalAmount.from integer 0
// totalAmount.to integer 0
// totalFee object
// totalFee.from integer 0
// totalFee.to integer 0
// reward object
// reward.from integer 0
// reward.to integer 0
// payloadLength object
// payloadLength.from integer 0
// payloadLength.to integer 0


// {
//     "meta": {
//         "count": 1,
//         "pageCount": 1,
//         "totalCount": 1,
//         "next": null,
//         "previous": null,
//         "self": "/v2/blocks/14126007750611341900/transactions/search?page=1",
//         "first": "/v2/blocks/14126007750611341900/transactions/search?page=1",
//         "last": "/v2/blocks/14126007750611341900/transactions/search?page=1"
//     },
//     "data": [
//         {
//             "id": "57415c61e6e7f10a6f9820d5124b3916f3c3a036b360f4802f0eb484f86f3369",
//             "blockId": "14126007750611341900",
//             "type": 0,
//             "amount": 1000000000000000,
//             "fee": 10000000,
//             "sender": "DGihocTkwDygiFvmg6aG8jThYTic47GzU9",
//             "recipient": "DRac35wghMcmUSe5jDMLBDLWkVVjyKZFxK",
//             "signature": "3045022100878335a71ab6769f3c1e2895041ad24d6c58cdcfe1151c639e65289e5287b0a8022010800bcfdc3223a9c59a6b014e8adf72f1c34df8a46afe655b021930b03e214e",
//             "vendorField": "yo",
//             "confirmations": 3034848,
//             "timestamp": {
//                 "epoch": 3909196,
//                 "unix": 1494010396,
//                 "human": "2017-05-05T18:53:16Z"
//             }
//         }
//     ]
// }