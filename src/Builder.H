#ifndef BUILDER_H
#define BUILDER_H

#include <memory>
#include <stack>
#include <string>
#include <list>

#include "ISubject.h"

namespace dom
{
	class Document;
	class Element;
	class Attr;
};

class Builder : public ISubject
{
private:
	std::shared_ptr<dom::Document>			factory;
	std::stack<std::shared_ptr<dom::Element>>	elementStack;
	std::shared_ptr<dom::Element>			currentElement;
	std::shared_ptr<dom::Attr>			currentAttr;

	std::list<IObserver *> list_observer_;
  	std::string message_;

	virtual const std::string	trim(const std::string & s) const;
public:
	Builder(std::shared_ptr<dom::Document> _factory) : factory(_factory), currentElement(0), currentAttr(0) {}

	virtual std::shared_ptr<dom::Document>	getDocument(void)	{ return factory; }	// aka getResult

	virtual void		addValue(const std::string & text);
	virtual void		confirmElement(const std::string & tag);
	virtual void		createAttribute(const std::string & attribute);
	virtual void		createElement(const std::string & tag);
	virtual void		createProlog(void);
	virtual void		endProlog(void);
	virtual void		identifyProlog(const std::string & id);
	virtual bool		popElement(void);
	virtual void		pushElement(void);
	virtual void		valueAttribute(const std::string & value);

	virtual void 		Attach(IObserver *observer) override;
	virtual void 		Detach(IObserver *observer) override;
	virtual void 		Notify() override;
	virtual void 		CreateMessage(std::string message);
	virtual void 		HowManyObservers();
};

#endif // BUILDER_H
