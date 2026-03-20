#ifndef DOCUMENTADAPTER_H
#define DOCUMENTADAPTER_H

#include "DOMDocument.hpp"
#include "Document.H"
#include <string>

class DocumentAdapter_JHU_EP : public XERCES::DOMDocument
{
private:
    Document_Impl* impl_JHU_EP;

public:
    DocumentAdapter_JHU_EP(Document_Impl* n);

    DOMElement* createElement(const XMLCh *tagName);
    DOMText* createTextNode(const XMLCh *data);
    DOMAttr* createAttribute(const XMLCh *name);
    DOMElement* getDocumentElement() const;


};



#endif