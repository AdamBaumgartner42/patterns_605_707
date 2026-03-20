#ifndef DOCUMENTADAPTER_H
#define DOCUMENTADAPTER_H

#include "../xerces/dom/DOMNode.hpp"
#include "Document.H"
#include <string>

class DocumentAdapter_JHU_EP : public XERCES::DOMDocument
{
private:
    Document_Impl* impl_JHU_EP;

public:
    DocumentAdapter_JHU_EP(Document_Impl* n);
}



#endif