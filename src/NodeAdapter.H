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

    const XMLCh* getNodeName() const override;

};

#endif