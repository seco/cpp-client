

#ifndef NETWORK_H
#define NETWORK_H

#include "platform/platform.h"

#include <cstdio>
#include <cstring>

namespace ARK
{
/*************************************************
* ARK::NetworkType
**************************************************/
enum NetworkType
{
	INVALID = -1,
	DEV = 0,
	MAIN = 1,
	CUSTOM = 2
};
/*************************************************/

/**************************************************************************************************/

/********************************************************************************
* ARK::Network
*
* EXAMPLE: 
*
* 578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23
* DARK
* DѦ
* https://dexplorer.ark.io/
* 30
********************************************************************************/
struct Network :
		public Printable
{
	protected:
		char nethash_[64 + 1];
		char token_[5];
		char symbol_[5];
		char explorer_[40];
		int version_;

	public:
		/*************************************************
		* Default: Empty Constructor
		**************************************************/
		Network() = default;
		/*************************************************/

		/*************************************************
		* Constructor
		**************************************************/
		Network(
				const char *const	newNethash,
				const char *const	newToken,
				const char *const	newSymbol,
				const char *const 	newExplorer,
				int	newVersion
		);
		/*************************************************/

		/*************************************************
		* Accessors
		**************************************************/
		const char *nethash() const noexcept { return this->nethash_; }
		const char *token() const noexcept { return this->token_; }
		const char *symbol() const noexcept { return this->symbol_; }
		const char *explorer() const noexcept { return this->explorer_; }
		int version() const noexcept { return this->version_; }
		/*************************************************/

		/*************************************************
		* ARK::Network::Network::operator==
		*
		* @brief: Comparison of two Network Models for equality.
		**************************************************/
		bool operator==(const Network &rhs) const;
		/*************************************************/

		/*************************************************
		* ARK::Network::Network::operator!=
		*
		* @brief: Comparison of two Network Models for inequality.
		**************************************************/
		bool operator!=(const Network &rhs) const;
		/*************************************************/

		/*************************************************
		* @brief: Prints network model.
		**************************************************/
		virtual size_t printTo(Print &p) const;
		/*************************************************/

};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::Network_ADV
**************************************************/
namespace Network_ADV
{
	struct bip32_t
	{
		long pub;	// base58 will have a prefix 'apub'
		long priv; // base58Priv will have a prefix 'apriv'
	};
	/*************************************************/
	struct network_t
	{
		const char *messagePrefix;
		bip32_t bip32;
		uint8_t pubKeyHash;	// Addresses will begin with 'A'
		uint8_t wif;		// Network prefix for wif generation
	};
};
/*************************************************/

};

#endif
