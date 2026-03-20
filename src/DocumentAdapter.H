#ifndef DOCUMENTADAPTER_H
#define DOCUMENTADAPTER_H

#include "DOMDocument.hpp"
#include "Document.H"
#include "Element.H"
#include "Text.H"
#include "Attr.H"
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

class ElementWrapper_JHU_EP : public XERCES::DOMElement
{
private:
    dom::Element* element_JHU_EP;
public: 
    ElementWrapper_JHU_EP(dom::Element* n);
};

class TextWrapper_JHU_EP : public XERCES::DOMText
{
private:
    dom::Text* text_JHU_EP;
public: 
    TextWrapper_JHU_EP(dom::Text* n);
};

class AttrWrapper_JHU_EP : public XERCES::DOMAttr
{
private:
    dom::Attr* attr_JHU_EP;
public: 
    AttrWrapper_JHU_EP(dom::Attr* n);
};



#endif