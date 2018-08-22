

#include "api/two/node/two_node.h"

std::string Ark::API::TWO::Node::nodeConfiguration()
{
    return connection.callback(Ark::API::TWO::Paths::Node::configuration);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Node::nodeStatus()
{
    return connection.callback(Ark::API::TWO::Paths::Node::status);
}

/**************************************************************************************************/

std::string Ark::API::TWO::Node::nodeSycing()
{
    return connection.callback(Ark::API::TWO::Paths::Node::syncing);
}
