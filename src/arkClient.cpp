

#include "arkClient.h"

namespace ARK
{
/*************************************************
* Default: Empty Constructor - ARK::Client
**************************************************/
Client::Client() {}
/*************************************************/

/*************************************************
* ARK::Client
*
* @param: const char *const customBaseURL
* @param: const int customBasePort
*
* @brief: Creates API Client instance using a base url and port.
**************************************************/
Client::Client(
    const char *const customBaseURL,
    const unsigned int customBasePort
) {
    this->netConnector = ARK::Utilities::Network::Connector(customBaseURL, customBasePort);
};
/*************************************************/

/*************************************************
* ARK::Client
*
* @param: const NetworkType netType 
*
* @brief: Creates API Client instance using a Network Type (Devnet, Mainnet).
**************************************************/
Client::Client(const NetworkType netType)
{
    switch (netType)
    {
        case DEVNET:
            this->netConnector = {
                DEVNET_SEED_URL,
                DEVNET_SEED_PORT
            }; break;
        case MAINNET:
            this->netConnector = {
                MAINNET_SEED_URL,
                MAINNET_SEED_PORT
            }; break;
    }
};
/*************************************************/

};
