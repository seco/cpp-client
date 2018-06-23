

#ifndef PEERABLE_H
#define PEERABLE_H

#include "platform/platform.h"
#include "utils/connector.h"
#include "api/paths.h"

#include <cstring>
#include <cstdio>

namespace ARK
{
namespace API
{
/*************************************************
*	PUBLIC: ARK::API::Peerable
*	virtual ARK::Utilities::Network::Connectable
*    
*	API's Peer Model
**************************************************/
class Peerable :
    virtual ARK::Utilities::Network::Connectable
{
  public:
		/*************************************************
		*	/api/peers/get?ip=167.114.29.55&port=4002
		*
    *	@param:	const char *const ip
		*	@param:	const unsigned int port
		*	@return: std::string
		*
		*	@brief:	Gets Ark Network Peer from a Node via API.
		**************************************************/
    std::string peer(const char *const ip, const unsigned int port);
    /*************************************************/

		/**************************************************************************************************/
		
    /*************************************************
		*	/api/peers?limit=20
		*
		*	@return: std::string
		*
		*	@brief:	Gets Ark Network Peers list, limited to 20 for MCU.
		**************************************************/
    std::string peers();
    /*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/peers/version
		*
		*	@return: std::string
		*
		*	@brief: Gets Ark Network Peer Version from a Node via API.
		**************************************************/
    std::string peerVersion();
    /*************************************************/

};
/*************************************************/

};
};

#endif
