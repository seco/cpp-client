

#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "platform/platform.h"
#include "utils/http.h"

namespace ARK
{
namespace Utilities
{
namespace Network
{
/*************************************************
* ARK::Utilities::Network::Connectable
* @brief: Forward Declaration.
**************************************************/
class Connectable; 
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::Utilities::Network::Connector
**************************************************/
class Connector :
		virtual HTTPConnectable
{
	private:
		char ip_[20+1] = { '\0' };
		int port_;

	public:
		Connector();
		Connector(const char *const newIP, const int newPort);

		std::string callback(const char* const request);
};
/*************************************************/

};
};
};

/**************************************************
* ARK::Utilities::Network::Connectable
* Inheritable Connector object
**************************************************/
class ARK::Utilities::Network::Connectable
{
	public:
		ARK::Utilities::Network::Connector netConnector;
};
/*************************************************/

#endif
