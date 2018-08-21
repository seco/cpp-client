

#ifndef ONE_DELEGATES_H
#define ONE_DELEGATES_H

#include "platform/platform.h"
#include "connection/connector.h"
#include "api/one/one_paths.h"

namespace ARK
{
namespace API
{
namespace ONE
{

class Delegates : virtual ARK::Utilities::Network::Connectable
{
  public:
    std::string delegate(const char *const parameter);
    std::string delegates();
    std::string delegatesCount();
    std::string delegateSearch(const char *const username);
    std::string delegateFee();
    std::string delegateForgedByAccount(const char *const generatorPublicKey);
    std::string delegateNextForgers();
    std::string delegateVoters(const char *const publicKey);
};

}; // namespace ONE
}; // namespace API
}; // namespace ARK

#endif
