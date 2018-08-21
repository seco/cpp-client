

#ifndef ONE_ACCOUNTS_H
#define ONE_ACCOUNTS_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/one/one_paths.h"

namespace ARK
{
namespace API
{
namespace ONE
{

class Accounts : virtual ARK::Utilities::Network::Connectable
{
  public:
    std::string accountBalance(const char *const arkAddress);
    std::string accountPublickey(const char *const arkAddress);
    std::string accountDelegatesFee(const char *const arkAddress);
    std::string accountDelegates(const char *const arkAddress);
    std::string account(const char *const arkAddress);
};

}; // namespace ONE
}; // namespace API
}; // namespace ARK

#endif
