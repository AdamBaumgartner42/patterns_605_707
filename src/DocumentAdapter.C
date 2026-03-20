/**
 * @brief Adapter for JHU_EP documents to be read as w3c documents
 */
#include "DocumentAdapter.H"

#include <string>

// --- Needed but not present ---
// #include "DOMElement"
// #include "DOMText"
// #include "DOMAttr"


// Cpnstructors

DocumentAdapter_JHU_EP::DocumentAdapter_JHU_EP(Document_Impl* n) : doc_impl_JHU_EP (n) {}

ElementWrapper_JHU_EP::ElementWrapper_JHU_EP(dom::Element* e) : element_JHU_EP (e) {}
TextWrapper_JHU_EP::TextWrapper_JHU_EP(dom::Text* t) : text_JHU_EP (t) {}
AttrWrapper_JHU_EP::AttrWrapper_JHU_EP(dom::Attr* a) : attr_JHU_EP (a) {}

XERCES::DOMElement* DocumentAdapter_JHU_EP::createElement(const XERCES::XMLCh *tagName)
{
    // Pass the value to our composed class of Document_Impl 
    dom::Element* createdElement = doc_impl_JHU_EP->createElement(std::string(tagName));

    // Wrap value for XERCES::DOMElement return type
    return new ElementWrapper_JHU_EP(createdElement);
}

XERCES::DOMText* DocumentAdapter_JHU_EP::createTextNode(const XERCES::XMLCh *data)
{   
    dom::Text* createdText = doc_impl_JHU_EP->createTextNode(std::string(data));
    return new TextWrapper_JHU_EP(createdText);
}

XERCES::DOMAttr* DocumentAdapter_JHU_EP::createAttribute(const XERCES::XMLCh *name)
{   
    dom::Attr* createdAttribute = doc_impl_JHU_EP->createAttribute(std::string(name));
    return new AttrWrapper_JHU_EP(createdAttribute);
}

XERCES::DOMElement* DocumentAdapter_JHU_EP::getDocumentElement() const
{
    dom::Element* createdElement = doc_impl_JHU_EP->getDocumentElement();
    return new ElementWrapper_JHU_EP(createdElement);
}
