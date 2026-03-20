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

    Node_Impl* parent_impl = dynamic_cast<Node_Impl*>(parent);

    return NodeAdapter_JHU_EP::create(parent_impl);
}

XERCES::DOMNodeList* NodeAdapter_JHU_EP::getChildNodes() const
{
    return nullptr;
}

XERCES::DOMNode* NodeAdapter_JHU_EP::getFirstChild() const
{
    return nullptr;
}

XERCES::DOMNode* NodeAdapter_JHU_EP::getLastChild() const
{
    return nullptr;
}

XERCES::DOMNode* NodeAdapter_JHU_EP::getPreviousSibling() const
{
    return nullptr;
}

XERCES::DOMNode* NodeAdapter_JHU_EP::getNextSibling() const
{
    return nullptr;
}

XERCES::DOMNamedNodeMap* NodeAdapter_JHU_EP::getAttributes() const
{
    return nullptr;
}

XERCES::DOMDocument* NodeAdapter_JHU_EP::getOwnerDocument() const
{
    return nullptr;
}

XERCES::DOMNode* NodeAdapter_JHU_EP::cloneNode(bool deep) const
{
    (void)deep;
    return nullptr;
}

XERCES::DOMNode* NodeAdapter_JHU_EP::insertBefore(XERCES::DOMNode* newChild, XERCES::DOMNode* refChild)
{
    (void)newChild;
    (void)refChild;
    return nullptr;
}

XERCES::DOMNode* NodeAdapter_JHU_EP::replaceChild(XERCES::DOMNode* newChild, XERCES::DOMNode* oldChild)
{
    (void)newChild;
    (void)oldChild;
    return nullptr;
}

XERCES::DOMNode* NodeAdapter_JHU_EP::removeChild(XERCES::DOMNode* oldChild)
{
    (void)oldChild;
    return nullptr;
}

XERCES::DOMNode* NodeAdapter_JHU_EP::appendChild(XERCES::DOMNode* newChild)
{
    (void)newChild;
    return nullptr;
}

bool NodeAdapter_JHU_EP::hasChildNodes() const
{
    return false;
}

void NodeAdapter_JHU_EP::setNodeValue(const XERCES::XMLCh* nodeValue)
{
    (void)nodeValue;
}

// Level 2

void NodeAdapter_JHU_EP::normalize()
{
}

bool NodeAdapter_JHU_EP::isSupported(const XERCES::XMLCh* feature, const XERCES::XMLCh* version) const
{
    (void)feature;
    (void)version;
    return false;
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::getNamespaceURI() const
{
    return nullptr;
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::getPrefix() const
{
    return nullptr;
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::getLocalName() const
{
    return nullptr;
}

void NodeAdapter_JHU_EP::setPrefix(const XERCES::XMLCh* prefix)
{
    (void)prefix;
}

bool NodeAdapter_JHU_EP::hasAttributes() const
{
    return false;
}

// Level 3

bool NodeAdapter_JHU_EP::isSameNode(const XERCES::DOMNode* other) const
{
    return this == other;
}

bool NodeAdapter_JHU_EP::isEqualNode(const XERCES::DOMNode* arg) const
{
    (void)arg;
    return false;
}

void* NodeAdapter_JHU_EP::setUserData(const XERCES::XMLCh* key, void* data, XERCES::DOMUserDataHandler* handler)
{
    (void)key;
    (void)handler;
    return data;
}

void* NodeAdapter_JHU_EP::getUserData(const XERCES::XMLCh* key) const
{
    (void)key;
    return nullptr;
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::getBaseURI() const
{
    return nullptr;
}

short NodeAdapter_JHU_EP::compareDocumentPosition(const XERCES::DOMNode* other) const
{
    (void)other;
    return 0;
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::getTextContent() const
{
    return nullptr;
}

void NodeAdapter_JHU_EP::setTextContent(const XERCES::XMLCh* textContent)
{
    (void)textContent;
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::lookupPrefix(const XERCES::XMLCh* namespaceURI) const
{
    (void)namespaceURI;
    return nullptr;
}

bool NodeAdapter_JHU_EP::isDefaultNamespace(const XERCES::XMLCh* namespaceURI) const
{
    (void)namespaceURI;
    return false;
}

const XERCES::XMLCh* NodeAdapter_JHU_EP::lookupNamespaceURI(const XERCES::XMLCh* prefix) const
{
    (void)prefix;
    return nullptr;
}

void* NodeAdapter_JHU_EP::getFeature(const XERCES::XMLCh* feature, const XERCES::XMLCh* version) const
{
    (void)feature;
    (void)version;
    return nullptr;
}

// Non-standard

void NodeAdapter_JHU_EP::release()
{
    delete this;
}