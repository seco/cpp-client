

#ifndef ONE_PATHS_H
#define ONE_PATHS_H

namespace ARK
{
namespace API
{
namespace V1
{
namespace Paths
{
/*************************************************
* Account
**************************************************/
namespace Accounts
{
	const auto getBalance_s = "/api/accounts/getBalance";
	const auto getPublickey_s = "/api/accounts/getPublickey";
	const auto delegatesFee_s = "/api/accounts/delegates/fee";
	const auto delegates_s = "/api/accounts/delegates";
	const auto accounts_s = "/api/accounts";
};
/*************************************************/
/**************************************************************************************************/
/*************************************************
* Blocks
**************************************************/
namespace Blocks
{
	const auto get_s = "/api/blocks/get"; //using ID
	const auto blocks_s = "/api/blocks?orderBy=height:desc&limit=20";
	const auto getEpoch_s = "/api/blocks/getEpoch";
	const auto getHeight_s = "/api/blocks/getHeight";
	const auto getNethash_s = "/api/blocks/getNethash";
	const auto getFee_s = "/api/blocks/getFee";
	const auto getFees_s = "/api/blocks/getFees";
	const auto getMilestone_s = "/api/blocks/getMilestone";
	const auto getReward_s = "/api/blocks/getReward";
	const auto getSupply_s = "/api/blocks/getSupply";
	const auto getStatus_s = "/api/blocks/getStatus";
};
/*************************************************/
/**************************************************************************************************/
/*************************************************
* Delegates
**************************************************/
namespace Delegates
{
	const auto count_s = "/api/delegates/count";
	const auto search_s = "/api/delegates/search";
	const auto voters_s = "/api/delegates/voters";
	const auto get_s = "/api/delegates/get";
	const auto delegates_s = "/api/delegates?limit=20";
	const auto fee_s = "/api/delegates/fee";
	const auto getForgedByAccount_s = "/api/delegates/forging/getForgedByAccount";
	const auto getNextForgers_s = "/api/delegates/getNextForgers";
};
/*************************************************/
/**************************************************************************************************/
/*************************************************
* Loader
**************************************************/
namespace Loader
{
	const auto status_s = "/api/loader/status";
	const auto sync_s = "/api/loader/status/sync";
	const auto autoconfigure_s = "/api/loader/autoconfigure";
};
/*************************************************/
/**************************************************************************************************/
/*************************************************
* Peers
**************************************************/
namespace Peers
{
	const auto get_s = "/api/peers/get";
	const auto peers_s = "/api/peers?limit=20";
	const auto version_s = "/api/peers/version";
};
/*************************************************/
/**************************************************************************************************/
/*************************************************
* Signatures
**************************************************/
namespace Signatures
{
	const auto fee_s = "/api/signatures/fee";
};
/*************************************************/
/**************************************************************************************************/
/*************************************************
* Transactions
**************************************************/
namespace Transactions
{
	const auto getSingle_s = "/api/transactions/get";
	const auto transactions_s = "/api/transactions?orderBy=timestamp:desc&limit=20";
	const auto getSingleUnconfirmed_s = "/api/transactions/unconfirmed/get";
	const auto unconfirmed_s = "/api/transactions/unconfirmed";
};
/*************************************************/

};
};
};
};

#endif


/**************************************************************************************************/
/*************************************************/
// /* Transport */
// namespace Transport {
//   const auto list_s = "/peer/list";
//   const auto common_s = "/peer/blocks/common";
//   const auto block_s = "/peer/block";
//   const auto blocks_s = "/peer/blocks";
//   const auto transactions_s = "/peer/transactions";
//   const auto transactionsPost_s = "/peer/transactions"; // post
//   const auto transactionsFromIds_s = "/peer/transactionsFromIds";
//   const auto height_s = "/peer/height";
//   const auto status_s = "/peer/status";
// }
/*************************************************/
/**************************************************************************************************/
