

#include "api/two/node/two_node.h"

std::string ARK::API::TWO::Node::nodeConfiguration()
{
    return netConnector.callback(ARK::API::TWO::Paths::Node::configuration);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Node::nodeStatus()
{
    return netConnector.callback(ARK::API::TWO::Paths::Node::status);
}

/**************************************************************************************************/

std::string ARK::API::TWO::Node::nodeSycing()
{
    return netConnector.callback(ARK::API::TWO::Paths::Node::syncing);
}