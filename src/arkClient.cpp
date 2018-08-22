
#include "arkClient.h"

/*************************************************
* Default: Empty Constructor - Ark::Client
**************************************************/
#ifdef HAS_ONE_API
    Ark::V1::Client::Client() {}
#endif
#ifdef HAS_TWO_API
    Ark::V2::Client::Client() {}
#endif
/*************************************************/

/*************************************************
* Ark::Client
*
* @param: const char *const customBaseURL
* @param: const int customBasePort
*
* @brief: Creates API Client instance using a base url and port.
**************************************************/
#ifdef HAS_ONE_API
    Ark::V1::Client::Client(const char *const customBaseURL, const int customBasePort)
    {
        this->connection = Ark::Utilities::Network::AbstractConnection(customBaseURL, customBasePort, "");
    };
#endif
#ifdef HAS_TWO_API
    Ark::V2::Client::Client(const char *const customBaseURL, const int customBasePort)
    {
        this->connection = Ark::Utilities::Network::AbstractConnection(customBaseURL, customBasePort, "");
    };
#endif
/*************************************************/

/*************************************************
* Ark::Client
*
* @param: const NetworkType netType 
*
* @brief: Creates API Client instance using a Network Type (Devnet, Mainnet).
**************************************************/
#ifdef HAS_ONE_API
    Ark::V1::Client::Client(const NetworkType netType)
    {
        switch (netType)
        {
            case NetworkType::DEVNET:
                this->connection = {
                    DEVNET_EXPLORER_URL,
                    DEFAULT_EXPLORER_API_PORT,
                    DEFAULT_EXPLORER_SSL_FINGERPRINT
                }; break;
            case NetworkType::MAINNET:
                this->connection = {
                    MAINNET_EXPLORER_URL,
                    DEFAULT_EXPLORER_API_PORT,
                    DEFAULT_EXPLORER_SSL_FINGERPRINT
                }; break;
        }
    };
#endif
#ifdef HAS_TWO_API
    Ark::V2::Client::Client(const NetworkType netType)
    {
        switch (netType)
        {
            case NetworkType::DEVNET:
                this->connection = {
                    DEVNET_EXPLORER_URL,
                    DEFAULT_EXPLORER_API_PORT,
                    DEFAULT_EXPLORER_SSL_FINGERPRINT
                }; break;
            case NetworkType::MAINNET:
                this->connection = {
                    MAINNET_EXPLORER_URL,
                    DEFAULT_EXPLORER_API_PORT,
                    DEFAULT_EXPLORER_SSL_FINGERPRINT
                }; break;
        }
    };
#endif
/*************************************************/
