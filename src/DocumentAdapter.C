/**
 * @brief Adapter for JHU_EP documents to be read as w3c documents
 */
#include "DocumentAdapter.H"
#include "Element.H"


DocumentAdapter_JHU_EP::DocumentAdapter_JHU_EP(Document_Impl* n) : doc_impl_JHU_EP (n) {}



XERCES::DOMElement* DocumentAdapter_JHU_EP::createElement(const XERCES::XMLCh *tagName)
{
    // Pass the value to our composed class of Document_Impl
    doc_impl_JHU_EP->createElement(tagName);
    
    
    return nullptr;
}

XERCES::DOMText* DocumentAdapter_JHU_EP::createTextNode(const XERCES::XMLCh *data)
{
    return nullptr;
}

XERCES::DOMAttr* DocumentAdapter_JHU_EP::createAttribute(const XERCES::XMLCh *name)
{
    return nullptr;
}

XERCES::DOMElement* DocumentAdapter_JHU_EP::getDocumentElement() const
{
    return nullptr;
}
