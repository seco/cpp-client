

#include "helpers/helpers.h"
#include "connection.h"
#include <string>
#include <memory>

Ark::Utilities::Network::AbstractConnection::AbstractConnection(
        const char *const newHost,
        const int newPort,
        const char *const newFingerprint
) {
    this->connect(newHost, newPort, newFingerprint);
}

/***/

Ark::Utilities::Network::AbstractConnection& Ark::Utilities::Network::AbstractConnection::operator=(AbstractConnection&& other)
{
    if (this != &other) {
        this->connect(other.host_, other.port_, other.fingerprint_);
    };
    return *this;
}

/***/

void Ark::Utilities::Network::AbstractConnection::connect(
        const char *const newHost,
        const int newPort,
        const char *const newFingerprint
) {
    strncpy(this->host_, newHost, sizeof(this->host_) / sizeof(this->host_[0]));
    this->port_ = newPort;
    if (newFingerprint) {
        this->hasSSL = true;
        strncpy(this->fingerprint_, newFingerprint, sizeof(this->fingerprint_) / sizeof(this->fingerprint_[0]));
    };
}

/***/

void Ark::Utilities::Network::AbstractConnection::disconnect()
{
    strncpy(this->host_, "\0", sizeof(this->host_) / sizeof(this->host_[0]));
    this->port_ = 0;
    if (this->hasSSL) {
        this->hasSSL = false;
        strncpy(this->fingerprint_, "\0", sizeof(this->fingerprint_) / sizeof(this->fingerprint_[0]));
    };
}

/***/

std::string Ark::Utilities::Network::AbstractConnection::getConnection()
{
    char connectionStr[32] = { "\0" };
        std::strcpy(connectionStr, this->host_);
        std::strcat(connectionStr, ":");
        std::strcat(connectionStr, toString(this->port_).c_str());
    return connectionStr;
}

/***/

std::string Ark::Utilities::Network::AbstractConnection::getFingerprint() { return this->fingerprint_; }

/***/

std::string Ark::Utilities::Network::AbstractConnection::callback(const char *const request)
{
    if (this->hasSSL) {
        return this->http->get(this->host_, this->port_, request, this->fingerprint_);
    } else {
        return this->http->get(this->host_, this->port_, request);
    };
}

/***/

std::string Ark::Utilities::Network::AbstractConnection::send(
        const char* const endpoint,
        const char *const bodyParameters
) {
    if (this->hasSSL) {
        return this->http->post(this->host_, this->port_, endpoint, bodyParameters, this->fingerprint_);
    } else {
        return this->http->post(this->host_, this->port_, endpoint, bodyParameters);
    };
}
