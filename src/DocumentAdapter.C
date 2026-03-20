/**
 * @brief Adapter for JHU_EP documents to be read as w3c documents
 */
#include "DocumentAdapter.H"


DocumentAdapter_JHU_EP::DocumentAdapter_JHU_EP(Document_Impl* n) : impl_JHU_EP (n) {}

DocumentAdapter_JHU_EP::DOMElement* createElement(const XMLCh *tagName)
{
    return nullptr;
}

DocumentAdapter_JHU_EP::DOMText* createTextNode(const XMLCh *data)
{
    return nullptr;
}

DocumentAdapter_JHU_EP::DOMAttr* createAttribute(const XMLCh *name)
{
    return nullptr;
}

DocumentAdapter_JHU_EP::DOMElement* getDocumentElement() const
{
    return nullptr;
}
