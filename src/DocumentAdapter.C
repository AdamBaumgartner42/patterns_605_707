/**
 * @brief Adapter for JHU_EP document nodes to be read as w3c nodes
 */
#include "DocumentAdapter.h"


// Document Adapter
DocumentAdapter_JHU_EP :: DocumentAdapter_JHU_EP(Document_Impl* n) : impl_JHU_EP (n) {}

//createElement
XERCES::DOMElement* createElement(const XMLCh *tagName)
{

}


//createTextNode
XERCES::DOMText* createTextNode(const XMLCh *data)
{
    
}


//createAttribute
virtual DOMAttr* createAttribute(const XMLCh *name)
{

}


//getDocumentElement
virtual DOMElement* getDocumentElement() const
{

}


