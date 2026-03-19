#ifndef NODEADAPTER_H
#define NODEADAPTER_H

#include "../xerces/xercesc/dom/DOMNode.hpp"
#include "Node.H"
#include <string>
 
// TODO: 34
// Done: 2

class NodeAdapter_JHU_EP : public XERCES::DOMNode
{
private:
    Node_Impl* impl_JHU_EP;
    mutable std::string stringBuffer;

public:
    NodeAdapter_JHU_EP(Node_Impl* n);

    const XMLCh* getNodeName() const override;      // done
    const XMLCh* getNodeValue() const override;     // done
    XERCES::DOMNode::NodeType NodeAdapter_JHU_EP::getNodeType( 
        const std::string & n) const override;      // not done

    DOMNode* getParentNode() const override;

    DOMNode* getChildNodes() const override;
    
    DOMNode* getFirstChild() const override;

    DOMNode* getLastChild() const override;

    DOMNode* getPreviousSibling() const override;

    DOMNode* getNextSibling() const override;

    DOMNamedNodeMap* getAttributes() const override;

    DOMDocument* getOwnerDocument() const override;

    DOMNode* cloneNode(bool deep) const override;

    DOMNode* insertBefore(DOMNode* newchild, 
        DOMNode *refChild) override;

    DOMNode* replaceChild(DOMNode *newChild, DOMNode *oldChild);

    DOMNode* appendChild(DOMNode *newChild) override;

    bool hasChildNodes() const override;

    void setNodeValue(const XMLCh* nodeValue) override;

    void normalize() override;

    bool isSupported(const XMLCh* feature, 
        const XMLCh* version) override;

    const XMLCh* getNamespaceURI() const override;

    const XMLCh* getPrefix() const override;

    const XMLCh* getLocalName() const override;

    void setPrefix(const XMLCh* prefix) override;

    bool hasAttributes() const override;

    bool isSameNode(const DOMNode* other) const override;

    bool isEqualNode(const DOMNode* arg) const override;

    void* setUserData(const XMLCh* key, void* data, 
        DOMUserDataHandler* handler) override;

    void* getUserData(const XMLCh* key) const override;

    const XMLCh* getBaseURI() const override;

    short compareDocumentPosition(const DOMNode* other) const override;

    const XMLCh* getTextContent() const override;

    void setTextContent(const XMLCh* textContent) override;

    const XMLCh* lookupPrefix(const XMLCh* namespaceURI) const override;

    bool isDefaultNamespace(const XMLCh* namespaceURI) const override;

    const XMLCh* lookupNamespaceURI(const XMLCh* prefix) const override;

    void* getFeature(const XMLCh* feature, const XMLCh* version) const override;

}

#endif