#ifndef NODEADAPTER_H
#define NODEADAPTER_H

#include "../xerces/xercesc/dom/DOMNode.hpp"
#include "Node.H"
#include <string>



class NodeAdapter_JHU_EP : public XERCES::DOMNode
{
private:
    Node_Impl* impl_JHU_EP;
    mutable std::string stringBuffer;

public:
    NodeAdapter_JHU_EP(Node_Impl* n);

    virtual const XMLCh* getNodeName() const override;      // done
    virtual const XMLCh* getNodeValue() const override;     // done
    virtual XERCES::DOMNode::NodeType NodeAdapter_JHU_EP::getNodeType( 
        const std::string & n) const override;              // not done

    virtual DOMNode* getParentNode() const override;

    virtual DOMNode* getChildNodes() const override;
    
    virtual DOMNode* getFirstChild() const override;

    virtual DOMNode* getLastChild() const override;

    virtual DOMNode* getPreviousSibling() const override;

    virtual DOMNode* getNextSibling() const override;

    virtual DOMNamedNodeMap* getAttributes() const override;

    virtual DOMDocument* getOwnerDocument() const override;

    virtual DOMNode* cloneNode(bool deep) const override;

    virtual DOMNode* insertBefore(DOMNode* newchild, 
        DOMNode *refChild) override;

    virtual DOMNode* replaceChild(DOMNode *newChild,
        DOMNode *oldChild);

    virtual DOMNode* appendChild(DOMNode *newChild) override;

    virtual bool hasChildNodes() const override;

    virtual void setNodeValue(const XMLCh* nodeValue) override;

    virtual void normalize() override;

    virtual bool isSupported(const XMLCh* feature, 
        const XMLCh* version) override;

    virtual const XMLCh* getNamespaceURI() const override;

    virtual const XMLCh* getPrefix() const override;

    virtual const XMLCh* getLocalName() const override;

    virtual void setPrefix(const XMLCh* prefix) override;

    virtual bool hasAttributes() const override;

    virtual bool isSameNode(const DOMNode* other) const override;

    virtual bool isEqualNode(const DOMNode* arg) const override;

    virtual void* setUserData(const XMLCh* key, void* data, 
        DOMUserDataHandler* handler) override;

    virtual void* getUserData(const XMLCh* key) const override;

    virtual const XMLCh* getBaseURI() const override;

    virtual short compareDocumentPosition(const DOMNode* other) const override;

    virtual const XMLCh* getTextContent() const override;

    virtual void setTextContent(const XMLCh* textContent) override;

    virtual const XMLCh* lookupPrefix(const XMLCh* namespaceURI) const override;

    virtual bool isDefaultNamespace(const XMLCh* namespaceURI) const override;

    virtual const XMLCh* lookupNamespaceURI(const XMLCh* prefix) const override;

    virtual void* getFeature(const XMLCh* feature, const XMLCh* version) const override;

}

#endif