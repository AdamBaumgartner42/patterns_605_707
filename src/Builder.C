/**
 * @brief Builder Pattern to create DOM tree from XML files
 */

#include "Builder.H"
#include "XMLTokenizer.H"
#include "Text.H"

ConcreteBuilder::ConcreteBuilder() : document(0) {}

ConcreteBuilder::~ConcreteBuilder() {}

void ConcreteBuilder::startDocument()
{
    document = new Document_Impl();
    elementStack.clear();
}

void ConcreteBuilder::startElement(const std::string &name)
{
    if (document == 0)
        startDocument();

    dom::Element * element = document->createElement(name);

    if (elementStack.empty())
        document->appendChild(dynamic_cast<dom::Node *>(element));
    else 
        elementStack.back()->appendChild(dynamic_cast<dom::Node *>(element));

    elementStack.push_back(element);
}

void ConcreteBuilder::addAttribute(const std::string &name, const std::string &value)
{
    if (elementStack.empty())
        return;

    elementStack.back()->setAttribute(name, value);
}

void ConcreteBuilder::addText(const std::string &value)
{
    if (elementStack.empty() || value.size() == 0)
        return;
    
    elementStack.back()->appendChild(dynamic_cast<dom::Node *> (document->createTextNode(value)));
}

void ConcreteBuilder::endElement(const std::string &name)
{
    if (elementStack.empty())
        return;

    if (name.size() == 0 || elementStack.back()->getTagName().compare(name) == 0)
        elementStack.pop_back();
}

dom::Document * ConcreteBuilder::getResult()
{
    return document;
}

dom::Document * Director::construct(const std::string &filename)
{
    builder->startDocument();
    XMLTokenizer tokenizer(filename);
    XMLTokenizer::XMLToken * token = 0;
    std::string pendingAttribute;
    bool insideClosingTag = false;

    do
    {
        delete token;
        token = tokenizer.getNextToken();

        switch (token->getTokenType())
        {
        case XMLTokenizer::XMLToken::TAG_CLOSE_START:
            insideClosingTag = true;
            break;
        case XMLTokenizer::XMLToken::TAG_START:
            insideClosingTag = true;
            break;
        case XMLTokenizer::XMLToken::ELEMENT:
        {   
            std::string elementName = token->getToken();
            if(elementName.size() == 0)
                break;
            
            if (insideClosingTag)
                builder->startElement(elementName);
            else 
                builder->startElement(elementName);
            break;
        }
        case XMLTokenizer::XMLToken::ATTRIBUTE:
            pendingAttribute = parseAttributeName(token->getToken());
            break;
        case XMLTokenizer::XMLToken::ATTRIBUTE_VALUE:
            if (pendingAttribute.size() > 0)
                builder->addAttribute(pendingAttribute, parseAttributeValue(token->getToken()));
            pendingAttribute.clear();
            break;
        case XMLTokenizer::XMLToken::VALUE:
        {
            std::string text = token->getToken();
            if (text.size() > 0)
                builder->addText(text);
            break;
        }
        case XMLTokenizer::XMLToken::NULL_TAG_END:
            builder->endElement("");
            insideClosingTag = false;
            break;
        case XMLTokenizer::XMLToken::TAG_END:
            insideClosingTag = false;
            break;
        default: 
            break;
        }
    } while (token->getTokenType() != XMLTokenizer::XMLToken::NULL_TOKEN);

    delete token;

    return builder->getResult();
}


