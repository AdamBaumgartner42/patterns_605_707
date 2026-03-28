#include "Builder.H"
#include <iostream>

#include <ctype.h>
#include "Document.H"
#include "Element.H"
#include "Attr.H"
#include "Text.H"


// Set ChangeManager
void Builder::setChangeManager(ChangeManager* chman){
	chman_ = chman;
}

// Get Message - used with ChangeManager
std::string Builder::getMessage(void){
	return message_;
}

// Concrete Subject method
void Builder::Attach(IObserver *observer){

	if (chman_){
		// ChangeManager Implementation
		chman_->Register(this, observer);
	} 
	else {
		// Original Implementation
		list_observer_.push_back(observer);
	}
}

// Concrete Subject method
void Builder::Detach(IObserver *observer){

	if (chman_){
		chman_->Unregister(this, observer);
	} else {
		list_observer_.remove(observer);
	}
}

void Builder::Notify(){
	if (chman_){
		chman_->Notify(this);
	} else {
		std::list<IObserver *>::iterator iterator = list_observer_.begin();
		HowManyObserver();
		while (iterator != list_observer_.end()) {
			(*iterator)->Update(this);
			++iterator;
		}
	}
}

// Concrete Subject method
void Builder::CreateMessage(std::string message) {
	this->message_ = message;
	Notify();
}

// Concrete Subject method
void Builder::HowManyObserver() {
	std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
}


// Added subject update method
void Builder::addValue(const std::string & text)
{
	Builder::CreateMessage("adding value\n");
	elementStack.top()->appendChild(factory->createTextNode(trim(text)));
}

void Builder::confirmElement(const std::string & tag)
{
	// Throw an exception if trim(tag) != currentElement.getTagName()
}

// Added subject update method
void Builder::createAttribute(const std::string & attribute)
{
	Builder::CreateMessage("creating attribute\n");
	std::string	trimmed	= trim(attribute);
	currentAttr	= factory->createAttribute(std::string(trimmed, 0, trimmed.size() - 1));
}

// Added subject update method
void Builder::createElement(const std::string & tag)
{
	Builder::CreateMessage("creating element\n");
	currentElement	= factory->createElement(trim(tag));

	if (elementStack.size() == 0)	// This is the root element.
		factory->appendChild(currentElement);
	else
		elementStack.top()->appendChild(currentElement);
}

void Builder::createProlog(void)
{
	// null method in this implementation
}

void Builder::endProlog(void)
{
	// null method in this implementation
}

void Builder::identifyProlog(const std::string & id)
{
	// null method in this implementation
}

// Added subject update method
bool Builder::popElement(void)
{
	Builder::CreateMessage("popping element\n");
	currentElement	= elementStack.top();
	elementStack.pop();
	return elementStack.size() > 0;
}

// Added subject update method
void Builder::pushElement(void)
{
	if (currentElement)
	{
		Builder::CreateMessage("pushing element");
		elementStack.push(currentElement);
		currentElement	= 0;
	}
}

// Added subject update method
void Builder::valueAttribute(const std::string & value)
{
	Builder::CreateMessage("setting attribute");	
	
	std::string	trimmed	= trim(value);
	currentAttr->setValue(std::string(trimmed, 1, trimmed.size() - 2));

	if (currentElement != 0)	// Discard prolog attributes.  This implementation currently doesn't have
					// anything to do with them.
		currentElement->setAttributeNode(currentAttr);
}

const std::string Builder::trim(const std::string & s) const
{
	int	start_index;
	int	stop_index;

	for (start_index = 0; start_index < s.size() && isspace(s[start_index]); start_index++);
	for (stop_index = s.size() - 1; stop_index >= start_index && isspace(s[stop_index]); stop_index--);

	return std::string(s, start_index, stop_index - start_index + 1);
}
