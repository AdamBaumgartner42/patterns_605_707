/**
 * @brief Adapter for JHU_EP nodes to be read as w3c nodes
 */
#include "NodeAdapter.H"

// Create method for turning dom::Node* into XERCES::DOMNode*
XERCES::DOMNode* NodeAdapter_JHU_EP::create (Node_Impl* impl)
{
    // If impl is not valid, return 
    if(impl == nullptr)
    {
        return nullptr;
    }

    // Otherwise return a pointer to a wrapped XERCES::DOMNode*
    return new NodeAdapter_JHU_EP(impl);
}

XERCES::DOMDocument* NodeAdapter_JHU_EP::createDocument (Document_Impl* impl)
{
    if(impl == nullptr)
    {
        return nullptr;
    }

    // Currently not implemented
    return nullptr;
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

const XERCES::XMLCh* NodeAdapter_JHU_EP::getNodeValue() const
{
    // Using the same method as getNodeName
    stringBuffer = impl_JHU_EP->getNodeValue();
    return (const XERCES::XMLCh*) stringBuffer.c_str();
}

XERCES::DOMNode::NodeType NodeAdapter_JHU_EP::getNodeType() const
{
    // switch statement using getNodeType
    switch(impl_JHU_EP->getNodeType()) {
        case ATTRIBUTE_NODE :
            return XERCES::DOMNode::NodeType::ATTRIBUTE_NODE;
        case DOCUMENT_NODE :
            return XERCES::DOMNode::NodeType::DOCUMENT_NODE;
        case ELEMENT_NODE :
            return XERCES::DOMNode::NodeType::ELEMENT_NODE;
        case TEXT_NODE :
            return XERCES::DOMNode::NodeType::TEXT_NODE;
        default:
            return XERCES::DOMNode::NodeType::ELEMENT_NODE;
            // Element is generic so a good choice for fall through
    }
}

XERCES::DOMNode* NodeAdapter_JHU_EP::getParentNode() const
{
    // Pull the matching expression from Node_Impl
    dom::Node* parent = impl_JHU_EP->getParentNode();

    // I don't like this, but I really want to create the 
    Node_Impl* parent_impl = dynamic_cast<Node_Impl*>(parent);

    // I create a return a NodeAdapter_JHU_EP object, 
    // which is inherits from DOMNOde.
    return NodeAdapter_JHU_EP::create(parent_impl);
}

XERCES::DOMNodeList* NodeAdapter_JHU_EP::getChildNodes() const
{
    // Oof, this one with the NodeList is confusing
    return nullptr;
}

XERCES::DOMNode* NodeAdapter_JHU_EP::getFirstChild() const
{
    // Ok back to the syle same as getParentNode
    dom::Node* firstChild = impl_JHU_EP->getFirstChild();
    Node_Impl* firstChild_impl = dynamic_cast<Node_Impl*>(firstChild);
    return NodeAdapter_JHU_EP::create(firstChild_impl);
}

XERCES::DOMNode* NodeAdapter_JHU_EP::getLastChild() const
{
    // Using create style as in getParentNode
    dom::Node* lastChild = impl_JHU_EP->getLastChild();
    Node_Impl* lastChild_impl = dynamic_cast<Node_Impl*>(lastChild);
    return NodeAdapter_JHU_EP::create(lastChild_impl);
}

XERCES::DOMNode* NodeAdapter_JHU_EP::getPreviousSibling() const
{
    // Using create style as in getParentNode
    dom::Node* prevSibling = impl_JHU_EP->getPreviousSibling();
    Node_Impl* prevSibling_impl = dynamic_cast<Node_Impl*>(prevSibling);
    return NodeAdapter_JHU_EP::create(prevSibling_impl);
}

XERCES::DOMNode* NodeAdapter_JHU_EP::getNextSibling() const
{
    // Using create style as in getParentNode
    dom::Node* getNextSibling = impl_JHU_EP->getNextSibling();
    Node_Impl* prevSibling_impl = dynamic_cast<Node_Impl*>(getNextSibling);
    return NodeAdapter_JHU_EP::create(prevSibling_impl);
}

XERCES::DOMDocument* NodeAdapter_JHU_EP::getOwnerDocument() const
{
    //  We need a Document, but we only have a Node to work with
    // TODO
    return nullptr;
}

XERCES::DOMNode* NodeAdapter_JHU_EP::insertBefore(XERCES::DOMNode* newChild, XERCES::DOMNode* refChild)
{
    // TODO
    (void)newChild;
    (void)refChild;
    return nullptr;
}

XERCES::DOMNode* NodeAdapter_JHU_EP::replaceChild(XERCES::DOMNode* newChild, XERCES::DOMNode* oldChild)
{
    // TODO
    (void)newChild;
    (void)oldChild;
    return nullptr;
}

XERCES::DOMNode* NodeAdapter_JHU_EP::removeChild(XERCES::DOMNode* oldChild)
{
    // TODO
    (void)oldChild;
    return nullptr;
}

XERCES::DOMNode* NodeAdapter_JHU_EP::appendChild(XERCES::DOMNode* newChild)
{
    // TODO

    // Change DOMNode* to dom::Node*


    // impl_JHU_EP->appendChild();

    return nullptr;



}

bool NodeAdapter_JHU_EP::hasChildNodes() const
{
    // Adapter should directly return the result to the caller
    return impl_JHU_EP->hasChildNodes();
}

void NodeAdapter_JHU_EP::setNodeValue(const XERCES::XMLCh* nodeValue)
{
    // Send data from the Target to the Adaptee
    impl_JHU_EP->setNodeValue(nodeValue);
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::getLocalName() const
{
    // put impl_JHU_EP's output into the buffer
    stringBuffer = impl_JHU_EP->getLocalName();

    // Convert std::string to XMLch*, which is a char *
    return (const XERCES::XMLCh*) stringBuffer.c_str();
}

XERCES::DOMNode* NodeAdapter_JHU_EP::cloneNode(bool deep) const
{
    // NO MATCHING FUNCTION
    (void)deep;
    return nullptr;
}

void NodeAdapter_JHU_EP::normalize()
{
    // NO MATCHING FUNCTION
}

XERCES::DOMNamedNodeMap* NodeAdapter_JHU_EP::getAttributes() const
{
    // NO MATCHING FUNCTION
    return nullptr;
}

bool NodeAdapter_JHU_EP::isSupported(const XERCES::XMLCh* feature, const XERCES::XMLCh* version) const
{
    // NO MATCHING FUNCTION
    (void)feature;
    (void)version;
    return false;
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::getNamespaceURI() const
{
    // NO MATCHING FUNCTION
    return nullptr;
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::getPrefix() const
{
    // NO MATCHING FUNCTION
    return nullptr;
}

void NodeAdapter_JHU_EP::setPrefix(const XERCES::XMLCh* prefix)
{
    // NO MATCHING FUNCTION
    (void)prefix;
}

bool NodeAdapter_JHU_EP::hasAttributes() const
{
    // NO MATCHING FUNCTION
    return false;
}

bool NodeAdapter_JHU_EP::isSameNode(const XERCES::DOMNode* other) const
{
    // NO MATCHING FUNCTION
    return this == other;
}

bool NodeAdapter_JHU_EP::isEqualNode(const XERCES::DOMNode* arg) const
{
    // NO MATCHING FUNCTION
    (void)arg;
    return false;
}

void* NodeAdapter_JHU_EP::setUserData(const XERCES::XMLCh* key, void* data, XERCES::DOMUserDataHandler* handler)
{
    // NO MATCHING FUNCTION
    (void)key;
    (void)handler;
    return data;
}

void* NodeAdapter_JHU_EP::getUserData(const XERCES::XMLCh* key) const
{
    // NO MATCHING FUNCTION
    (void)key;
    return nullptr;
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::getBaseURI() const
{
    // NO MATCHING FUNCTION
    return nullptr;
}

short NodeAdapter_JHU_EP::compareDocumentPosition(const XERCES::DOMNode* other) const
{
    // NO MATCHING FUNCTION
    (void)other;
    return 0;
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::getTextContent() const
{
    // NO MATCHING FUNCTION
    return nullptr;
}

void NodeAdapter_JHU_EP::setTextContent(const XERCES::XMLCh* textContent)
{
    // NO MATCHING FUNCTION
    (void)textContent;
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::lookupPrefix(const XERCES::XMLCh* namespaceURI) const
{
    // NO MATCHING FUNCTION
    (void)namespaceURI;
    return nullptr;
}

bool NodeAdapter_JHU_EP::isDefaultNamespace(const XERCES::XMLCh* namespaceURI) const
{
    // NO MATCHING FUNCTION
    (void)namespaceURI;
    return false;
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::lookupNamespaceURI(const XERCES::XMLCh* prefix) const
{
    // NO MATCHING FUNCTION
    (void)prefix;
    return nullptr;
}

void* NodeAdapter_JHU_EP::getFeature(const XERCES::XMLCh* feature, const XERCES::XMLCh* version) const
{
    // NO MATCHING FUNCTION
    (void)feature;
    (void)version;
    return nullptr;
}

void NodeAdapter_JHU_EP::release()
{
    // NO MATCHING FUNCTION
    delete this;
}