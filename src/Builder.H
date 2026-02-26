#ifndef BUILDER_H
#define BUILDER_H

#include <string> 
#include <vector>

#include "Document.H"
#include "Element.H"

class Builder
{
public:
    virtual ~Builder() {};

    virtual void startDocument() = 0;
    virtual void startElement(const std::string &name) = 0;
    virtual void addAttribute(const std::string &name, const std::string &value) = 0;
    virtual void addText(const std::string &value) = 0;
    virtual void endElement(const std::string &name) = 0;
    virtual dom::Document * getResult() = 0;

};

class ConcreteBuilder : public Builder
{
private:
    dom::Document * document;
    std::vector<dom::Element *> elementStack;

public:
    ConcreteBuilder();
    virtual ~ConcreteBuilder();

    virtual void startDocument();
    virtual void startElement(const std::string &name);
    virtual void addAttribute(const std::string &name, const std::string &value);
    virtual void addText(const std::string &value);
    virtual void endElement(const std::string &name);
    virtual dom::Document * getResult();
};

class Director
{
private:
    Builder * builder;

public:
    Director(Builder * newBuilder) : builder(newBuilder) {}
    
    virtual dom::Document * construct(const std::string & filename);
};

#endif // BUILDER_H