/***************************************
* Ark-Cpp-Client - for the Ark Ecosystem (ark.io)
* https://github.com/Ark-IoT/Ark-Cpp
*
* sleepdeficit(simon@ark.io)
* MIT | Copyright S. Downey 2017-2018
***************************************/

#ifndef ONE_API_H
#define ONE_API_H

#include "api/one_accounts/one_accounts.h"
#include "api/one_blocks/one_blocks.h"
#include "api/one_delegates/one_delegates.h"
#include "api/one_loader/one_loader.h"
#include "api/one_peers/one_peers.h"
#include "api/one_signatures/one_signatures.h"
#include "api/one_transactions/one_transactions.h"

class ONE_API :
		public ARK::API::ONE_Accounts,
		public ARK::API::ONE_Blocks,
		public ARK::API::ONE_Delegates,
		public ARK::API::ONE_Loader,
		public ARK::API::ONE_Peers,
		public ARK::API::ONE_Signatures,
		public ARK::API::ONE_Transactions {};

#endif
