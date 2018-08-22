

#include "utils/helpers.h"
#include "connector.h"
#include <string>
#include <memory>

Ark::Utilities::Network::Connector::Connector(
        const char *const newHost,
        const int newPort,
        const char *const newFingerprint
) {
    this->connect(newHost, newPort, newFingerprint);
}

/**************************************************************************************************/

Ark::Utilities::Network::Connector& Ark::Utilities::Network::Connector::operator=(Connector&& other)
{
    if (this != &other)
    {
        this->connect(other.host_, other.port_, other.fingerprint_);
    };
    return *this;
}

/**************************************************************************************************/

std::string Ark::Utilities::Network::Connector::callback(const char *const request)
{
    if (this->hasSSL) {
        return this->http->getHTTPS(this->host_, this->port_, this->fingerprint_, request);
    } else {
        return this->http->get(this->host_, this->port_, request);
    };
}

/**************************************************************************************************/

void Ark::Utilities::Network::Connector::connect(
        const char *const newHost,
        const int newPort,
        const char *const newFingerprint = ""
) {
    strncpy(this->host_, newHost, sizeof(this->host_) / sizeof(this->host_[0]));
    this->port_ = newPort;
    if (strcmp(newFingerprint, ""))
    {
        this->hasSSL = true;
        strncpy(this->fingerprint_, newFingerprint, sizeof(this->fingerprint_) / sizeof(this->fingerprint_[0]));
    };
}

/**************************************************************************************************/

void Ark::Utilities::Network::Connector::disconnect()
{
    strncpy(this->host_, "\0", sizeof(this->host_) / sizeof(this->host_[0]));
    this->port_ = 0;
    if (this->hasSSL)
    {
        this->hasSSL = false;
        strncpy(this->fingerprint_, "\0", sizeof(this->fingerprint_) / sizeof(this->fingerprint_[0]));
    };
}

/**************************************************************************************************/

std::string Ark::Utilities::Network::Connector::getConnection()
{
    char connectionStr[32] = { "\0" };
        std::strcpy(connectionStr, this->host_);
        std::strcat(connectionStr, ":");
        std::strcat(connectionStr, toString(this->port_).c_str());
    return connectionStr;
}

/**************************************************************************************************/

std::string Ark::Utilities::Network::Connector::getFingerprint() { return this->fingerprint_; }

/**************************************************************************************************/
