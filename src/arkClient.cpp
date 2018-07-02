

#include "arkClient.h"

// namespace ARK
// {
/*************************************************
* Default: Empty Constructor - ARK::Client
**************************************************/
ARK::Client::Client() {

}
/*************************************************/

/*************************************************
* ARK::Client
*
* @param: const char *const customBaseURL
* @param: const int customBasePort
*
* @brief: Creates API Client instance using a base url and port.
**************************************************/
ARK::Client::Client(
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
ARK::Client::Client(const NetworkType netType)
{
    switch (netType)
    {
        case NetworkType::DEVNET:
            this->netConnector = {
                DEVNET_SEED_URL,
                DEVNET_SEED_PORT
            }; break;
        case NetworkType::MAINNET:
            this->netConnector = {
                MAINNET_SEED_URL,
                MAINNET_SEED_PORT
            }; break;
    }
};
/*************************************************/

// };
