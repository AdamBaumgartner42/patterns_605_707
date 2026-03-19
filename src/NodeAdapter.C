/**
 * @brief Adapter for JHU_EP nodes to be read as w3c nodes
 */
#include "NodeAdapter.h"


// Construct Node Adapter  
NodeAdapter_JHU_EP :: NodeAdapter_JHU_EP(Node_Impl* n) : impl_JHU_EP (n) {}


const XERCES::XMLCh* NodeAdapter_JHU_EP::getNodeName() const 
{
    // put impl_JHU_EP's output into the buffer
    stringBuffer = impl_JHU_EP->getNodeName();

    // Convert std::string to XMLch*, which is a char *
    return (const XERCES::XMLCh*) stringBuffer.c_str();
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::getNodeValue() const
{
    // put impl_JHU_EP's output into the buffer
    stringBuffer = impl_JHU_EP->getNodeValue();

    // typecast a c-style string to be a XMLCh* typedef
    return (const XERCES::XMLCh*) stringBuffer.c_str();
}

XERCES::DOMNode::NodeType NodeAdapter_JHU_EP::getNodeType(const std::string & n)
{
    // Here's what is expected by Xerces::DOMNode
    /*
    enum NodeType {
        ELEMENT_NODE                = 1,
        ATTRIBUTE_NODE              = 2,
        TEXT_NODE                   = 3,
        ...
    */

    // I'd like to call but this doesn't look to be implented to return anything
    short nodeType = impl_JHU_EP->getNodeType();

    // Placeholder (convert mapping between impl_JHU_EP and Xerces::DOMNode)

    return (XERCES::DOMNode::NodeType) nodeType;
}






