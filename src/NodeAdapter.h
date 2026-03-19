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

    DOMDocument* getOwnerDocument() const override;

    DOMNode* insertBefore(DOMNode* newchild, 
        DOMNode *refChild) override;

    DOMNode* replaceChild(DOMNode *newChild, DOMNode *oldChild);

    DOMNode* appendChild(DOMNode *newChild) override;

    bool hasChildNodes() const override;

    const XMLCh* getLocalName() const override;
}

#endif