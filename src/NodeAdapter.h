#ifndef NODEADAPTER_H
#define NODEADAPTER_H

#include "../xerces/xercesc/dom/DOMNode.hpp"
#include "Node.H"
#include "NodeList.H"
#include <string>
 


class ListAdapter_JHU_EP : public XERCES::DOMNodeList
{
private:
    NodeList* impl_list;
    

public:
    ListAdapter_JHU_EP(NodeList* list);

    // I don't believe I have enough information. 
    // I don't know what changes between dom::NodeList and XERCES::DOMNodeList

    // This would work because when we make the new list that is a member of 
    // ListAdapter_JHU_EP, it will be wrapped as a type XERCES::DOMNodeList.
};



class NodeAdapter_JHU_EP : public XERCES::DOMNode
{
private:
    Node_Impl* impl_JHU_EP;
    mutable std::string stringBuffer;

public:
    NodeAdapter_JHU_EP(Node_Impl* n);

    const XMLCh* getNodeName() const override;

    const XMLCh* getNodeValue() const override;

    const XMLCh* getLocalName() const override;

    XERCES::DOMNode::NodeType NodeAdapter_JHU_EP::getNodeType( 
        const std::string & n) const override;   

    DOMNode* getParentNode() const override;

    DOMNodeList getChildNodes() const override;
    
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

    
};

#endif