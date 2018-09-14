

#include "api/one/blocks/one_blocks.h"

/**
 * /api/blocks/get?id=_blockID
 **/
std::string Ark::API::ONE::Blocks::block(
    const char *const blockId)
{
    char uri[80] = {'\0'};
    strcpy(uri, Ark::API::ONE::Paths::Blocks::get_s);
    strcat(uri, "?id=");
    strcat(uri, blockId);
    return connection.callback(uri);
}
/**/

/***/

/**
 * /api/blocks?orderBy=height:desc&limit=10
 **/
std::string Ark::API::ONE::Blocks::blocks()
{
    return connection.callback(Ark::API::ONE::Paths::Blocks::blocks_s);
}
/**/

/***/

/**
 * /api/blocks/getEpoch
 **/
std::string Ark::API::ONE::Blocks::blockEpoch()
{
    return connection.callback(Ark::API::ONE::Paths::Blocks::getEpoch_s);
}
/**/

/***/

/**
 * /api/blocks/getFee
 **/
std::string Ark::API::ONE::Blocks::blockFee()
{
    return connection.callback(Ark::API::ONE::Paths::Blocks::getFee_s);
}
/**/

/***/

/**
 * /api/blocks/getFees
 **/
std::string Ark::API::ONE::Blocks::blockFees()
{
    return connection.callback(Ark::API::ONE::Paths::Blocks::getFees_s);
}
/**/

/***/

/**
 * /api/blocks/getHeight
 **/
std::string Ark::API::ONE::Blocks::blockHeight()
{
    return connection.callback(Ark::API::ONE::Paths::Blocks::getHeight_s);
}
/**/

/***/

/**
 * /api/blocks/getMilestone
 **/
std::string Ark::API::ONE::Blocks::blockMilestone()
{
    return connection.callback(Ark::API::ONE::Paths::Blocks::getMilestone_s);
}
/**/

/***/

/**
 * /api/blocks/getNethash
 **/
std::string Ark::API::ONE::Blocks::blockNethash()
{
    return connection.callback(Ark::API::ONE::Paths::Blocks::getNethash_s);
}
/**/

/***/

/**
 * /api/blocks/getReward
 **/
std::string Ark::API::ONE::Blocks::blockReward()
{
    return connection.callback(Ark::API::ONE::Paths::Blocks::getReward_s);
}
/**/

/***/

/**
 * /api/blocks/getSupply
 **/
std::string Ark::API::ONE::Blocks::blockSupply()
{
    return connection.callback(Ark::API::ONE::Paths::Blocks::getSupply_s);
}
/**/

/***/

/**
 * /api/blocks/getStatus
 **/
std::string Ark::API::ONE::Blocks::blockStatus()
{
    return connection.callback(Ark::API::ONE::Paths::Blocks::getStatus_s);
}
/**/
