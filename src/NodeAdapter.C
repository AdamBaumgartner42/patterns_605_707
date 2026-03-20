/**
 * @brief Adapter for JHU_EP nodes to be read as w3c nodes
 */
#include "NodeAdapter.H"

// Static Methods
// Create method for turning dom::Node* into XERCES::DOMNode*
static XERCES::DOMNode* create (Node_Impl* impl)
{
    // If impl is not valid, return 
    if(impl == nullptr)
    {
        return nullptr;
    }

    // Otherwise return a pointer to a wrapped XERCES::DOMNode*
    return new NodeAdapter_JHU_EP(impl);
}

// Node Adapter
// Construct Node Adapter  
NodeAdapter_JHU_EP :: NodeAdapter_JHU_EP(Node_Impl* n) : impl_JHU_EP (n) {}

const XERCES::XMLCh* NodeAdapter_JHU_EP::getNodeName() const 
{
    // put impl_JHU_EP's output into the buffer
    stringBuffer = impl_JHU_EP->getNodeName();

    // Convert std::string to XMLch*, which is a char *
    return (const XERCES::XMLCh*) stringBuffer.c_str();
}