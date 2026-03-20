#ifndef DOCUMENTADAPTER_H
#define DOCUMENTADAPTER_H

#include "DOMDocument.hpp"
#include "Document.H"
#include <string>

class DocumentAdapter_JHU_EP : public XERCES::DOMDocument
{
private:
    Document_Impl* doc_impl_JHU_EP;

public:
    DocumentAdapter_JHU_EP(Document_Impl* n);

    XERCES::DOMElement* createElement(const XERCES::XMLCh *tagName);
    XERCES::DOMText* createTextNode(const XERCES::XMLCh *data);
    XERCES::DOMAttr* createAttribute(const XERCES::XMLCh *name);
    XERCES::DOMElement* getDocumentElement() const;
};



#endif