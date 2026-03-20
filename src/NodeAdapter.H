#ifndef NODEADAPTER_H
#define NODEADAPTER_H

#include "DOMNode.hpp"
#include "Node.H"
#include "DOMDocument.hpp"
#include "Document.H"
#include <string>


class NodeAdapter_JHU_EP : public XERCES::DOMNode
{
private:
    Node_Impl* impl_JHU_EP;
    mutable std::string stringBuffer;

public:
    NodeAdapter_JHU_EP(Node_Impl* n);
    static XERCES::DOMNode* create(Node_Impl* impl);
    static XERCES::DOMDocument* createDocument (Document_Impl* impl);

    const XERCES::XMLCh* getNodeName() const override;

     // Level 1
    const XERCES::XMLCh* getNodeValue() const override;
    NodeType getNodeType() const override;
    XERCES::DOMNode* getParentNode() const override;
    XERCES::DOMNodeList* getChildNodes() const override;
    XERCES::DOMNode* getFirstChild() const override;
    XERCES::DOMNode* getLastChild() const override;
    XERCES::DOMNode* getPreviousSibling() const override;
    XERCES::DOMNode* getNextSibling() const override;
    XERCES::DOMNamedNodeMap* getAttributes() const override;
    XERCES::DOMDocument* getOwnerDocument() const override;
    XERCES::DOMNode* cloneNode(bool deep) const override;
    XERCES::DOMNode* insertBefore(XERCES::DOMNode* newChild, XERCES::DOMNode* refChild) override;
    XERCES::DOMNode* replaceChild(XERCES::DOMNode* newChild, XERCES::DOMNode* oldChild) override;
    XERCES::DOMNode* removeChild(XERCES::DOMNode* oldChild) override;
    XERCES::DOMNode* appendChild(XERCES::DOMNode* newChild) override;
    bool hasChildNodes() const override;
    void setNodeValue(const XERCES::XMLCh* nodeValue) override;

    // Level 2
    void normalize() override;
    bool isSupported(const XERCES::XMLCh* feature, const XERCES::XMLCh* version) const override;
    const XERCES::XMLCh* getNamespaceURI() const override;
    const XERCES::XMLCh* getPrefix() const override;
    const XERCES::XMLCh* getLocalName() const override;
    void setPrefix(const XERCES::XMLCh* prefix) override;
    bool hasAttributes() const override;

    // Level 3
    bool isSameNode(const XERCES::DOMNode* other) const override;
    bool isEqualNode(const XERCES::DOMNode* arg) const override;
    void* setUserData(const XERCES::XMLCh* key, void* data, XERCES::DOMUserDataHandler* handler) override;
    void* getUserData(const XERCES::XMLCh* key) const override;
    const XERCES::XMLCh* getBaseURI() const override;
    short compareDocumentPosition(const XERCES::DOMNode* other) const override;
    const XERCES::XMLCh* getTextContent() const override;
    void setTextContent(const XERCES::XMLCh* textContent) override;
    const XERCES::XMLCh* lookupPrefix(const XERCES::XMLCh* namespaceURI) const override;
    bool isDefaultNamespace(const XERCES::XMLCh* namespaceURI) const override;
    const XERCES::XMLCh* lookupNamespaceURI(const XERCES::XMLCh* prefix) const override;
    void* getFeature(const XERCES::XMLCh* feature, const XERCES::XMLCh* version) const override;

    // Non-standard
    void release() override;

};

#endif