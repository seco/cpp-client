

#ifndef ONE_SIGNATURES_H
#define ONE_SIGNATURES_H

#include "connection/connector.h"
#include "api/one/one_paths.h"

namespace ARK
{
namespace API
{
namespace ONE
{

class Signatures : virtual ARK::Utilities::Network::Connectable
{
  public:
    std::string signaturesFee();
};

}; // namespace ONE
}; // namespace API
}; // namespace ARK

#endif
