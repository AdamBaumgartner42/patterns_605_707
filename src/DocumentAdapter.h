#ifndef DOCUMENTADAPTER_H
#define DOCUMENTADAPTER_H

#include "../xerces/xercesc/dom/DOMDocument.hpp"
#include "Document.H"
#include <string>

class DocumentAdapter_JHU_EP : public XERCES::DOMDocument.hpp
{
private:
    Document_Impl* impl_JHU_EP;

public:
    DocumentAdapter_JHU_EP(Document_Impl* n);

    DOMElement* createElement(const XMLCh *tagName) override;

    DOMDocumentFragment* createDocumentFragment() override;

    DOMText* createTextNode(const XMLCh *data) override;

    DOMComment* createComment(const XMLCh *data) override;

    DOMCDATASection* createCDATASection(const XMLCh *data) override;

    DOMProcessingInstruction *createProcessingInstruction(const XMLCh *target,
        const XMLCh *data) override;

    DOMAttr* createAttribute(const XMLCh *name) override;

    DOMEntityReference* createEntityReference(const XMLCh *name) override;

    DOMDocumentType* getDoctype() const override;

    DOMImplementation* getImplementation() const override;

    DOMElement* getDocumentElement() const override;

    DOMNodeList* getElementsByTagName(const XMLCh *tagname) const override;

    DOMNode* importNode(const DOMNode *importedNode, bool deep) override;

    DOMElement* createElementNS(const XMLCh *namespaceURI,
	    const XMLCh *qualifiedName) override;

    DOMAttr* createAttributeNS(const XMLCh *namespaceURI,
        const XMLCh *qualifiedName) = 0;

    DOMNodeList* getElementsByTagNameNS(const XMLCh *namespaceURI,
	    const XMLCh *localName) const override;

    DOMElement* getElementById(const XMLCh *elementId) const override;

    const XMLCh* getInputEncoding() const override;

    const XMLCh* getXmlEncoding() const override;

    bool getXmlStandalone() const override;

    void setXmlStandalone(bool standalone) override;

    const XMLCh* getXmlVersion() const override;

    void setXmlVersion(const XMLCh* version) override;

    const XMLCh* getDocumentURI() const override;

    void setDocumentURI(const XMLCh* documentURI) override;

    bool getStrictErrorChecking() const override;

    void setStrictErrorChecking(bool strictErrorChecking) override;

    DOMNode* renameNode(DOMNode* n, const XMLCh* namespaceURI,
        const XMLCh* qualifiedName) override;

    DOMNode* adoptNode(DOMNode* source) override;

    void normalizeDocument() override;

    DOMConfiguration* getDOMConfig() const override;

    DOMEntity* createEntity(const XMLCh *name) override;

    DOMDocumentType *createDocumentType(const XMLCh *name) override;

    DOMDocumentType* createDocumentType(const XMLCh *qName,
        const XMLCh* publicId, const XMLCh* systemId) override;

    DOMNotation *createNotation(const XMLCh *name) override;

    virtual DOMElement *createElementNS(const XMLCh *namespaceURI,
        const XMLCh *qualifiedName, const XMLFileLoc lineNum,
        const XMLFileLoc columnNum) override;

    



    
                                    













    

    











}

#endif