#ifndef DOCUMENTADAPTER_H
#define DOCUMENTADAPTER_H

#include "../xerces/xercesc/dom/DOMDocument.hpp"
#include "Document.H"
#include <string>

// TODO: 33
// DONE: 0

class DocumentAdapter_JHU_EP : public XERCES::DOMDocument.hpp
{
private:
    Document_Impl* impl_JHU_EP;

public:
    DocumentAdapter_JHU_EP(Document_Impl* n);

    DOMElement* createElement(const XMLCh *tagName) override;

    DOMText* createTextNode(const XMLCh *data) override;

    DOMAttr* createAttribute(const XMLCh *name) override;

    DOMElement* getDocumentElement() const override;
}

#endif