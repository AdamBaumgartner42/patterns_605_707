/**
 * @brief Adapter for JHU_EP nodes to be read as w3c nodes
 */
#include "NodeAdapter.h"

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
    return new NodeAdapter_JHU_EDU(impl);
}

static XERCES::DOMNodeList* createList (NodeList* list)
{
    // If its not valid return
    if (list == nullptr)
    {
        return nullptr;
    }

    return new ListAdapter_JHU_EP(list);
}


// Node List Adapter 
ListAdapter_JHU_EP :: ListAdapter_JHU_EP(NodeList* list) : impl_list (list) {}

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

const XERCES::XMLCh* NodeAdapter_JHU_EP::getNodeValue() const
{
    // put impl_JHU_EP's output into the buffer
    stringBuffer = impl_JHU_EP->getNodeValue();

    // typecast a c-style string to be a XMLCh* typedef
    return (const XERCES::XMLCh*) stringBuffer.c_str();
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::getLocalName() const
{
    // put impl_JHU_EP's output into the buffer
    stringBuffer = impl_JHU_EP->getLocalName();

    // typecast a c-style string to be a XMLCh* typedef
    return (const XERCES::XMLCh*) stringBuffer.c_str();
}

XERCES::DOMNode::NodeType NodeAdapter_JHU_EP::getNodeType(const std::string & n)
{
    // switch statement using getNodeType
    switch(impl_JHU_EP->getNodeType()) {
        case ATTRIBUTE_NODE:
            return XERCES::DOMNode::NodeType::ATTRIBUTE_NODE;
        case DOCUMENT_NODE:
            return XERCES::DOMNode::NodeType::DOCUMENT_NODE;
        case ELEMENT_NODE:
            return XERCES::DOMNode::NodeType::ELEMENT_NODE;
        case TEXT_NODE:
            return XERCES::DOMNode::NodeType::TEXT_NODE;
        default:
            return XERCES::DOMNode::NodeType::ELEMENT_NODE;
            // Element is generic so a good choice to be the default
    }
}

XERCES::DOMNode NodeAdapter_JHU_EP::getParentNode()
{
    // Here I am going to utilize a create method
    // to change the class to match XERCES::DOMNode*

    dom::Node* parent = impl_JHU_EP->getParentNode();

    return NodeAdapter_JHU_EP::create(parent);
}


XERCES::DOMNodeList NodeAdapter_JHU_EP::getChildNodes()
{
    dom::NodeList* childList = impl_JHU_EP->getChildNodes();

    // I do not see information on class DOMNodeList
    
    // I'm going to leverage the same create command I'm
    // using with other nodes. I don't think its correct though

    return NodeAdapter_JHU_EP::createList(childList);
}

XERCES::DOMNode NodeAdapter_JHU_EP::getFirstChild()
{
    // get the object from the Adaptee class
    dom::Node* child = impl_JHU_EDU->getFirstChild();

    // Use the same static factory to convert types
    retrun NodeAdapter_JHU_EP::create(child);
}

XERCES::DOMNode NodeAdapter_JHU_EP::getLastChild()
{
    dom::Node* child = impl_JHU_EDU->getLastChild();
    return NodeAdapter_JHUEP::create(child);
}

XERCES::DOMNode NodeAdapter_JHU_EP::getPreviousSibling()
{
    dom::Node* child = impl_JHU_EDU->getPreviousSibling();
    return NodeAdapter_JHUEP::create(child);
}

XERCES::DOMNode NodeAdapter_JHU_EP::getNextSibling()
{
    dom::Node* child = impl_JHU_EDU->getNextSibling();
    return NodeAdapter_JHUEP::create(child);
}

XERCES::DOMDocument* getOwnerDocument()
{
    dom::Document* ownerDocument = impl_JHU_EDU->getOwnerDocument();
    return NodeAdapter_JHUEP::create(ownerDocument);
}



























