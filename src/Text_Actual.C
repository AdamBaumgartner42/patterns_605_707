#include "Text_Actual.H"
#include <stdexcept>


Text_Actual::Text_Actual(const std::string value, dom::Document * document) : Node_Impl("", dom::Node::TEXT_NODE)
{
	setNodeValue(value);
	Node_Impl::document	= document;
}

Text_Actual::~Text_Actual()
{
}

const std::string &	Text_Actual::getName(void)
{
	return getNodeName();
}

const std::string &	Text_Actual::getData(void)
{
	return getNodeValue();
}

const std::string &	Text_Actual::getValue(void)
{
	return getData();
}

void			Text_Actual::setData(const std::string & value)
{
	setNodeValue(value);
}

void			Text_Actual::setValue(const std::string & value)
{
	setNodeValue(value);
}

int			Text_Actual::getLength(void)
{
	return getValue().size();
}

const std::string &	Text_Actual::substringData(int offset, int count)
{
	try
	{
		//
		// This is not thread-safe, of course.
		//
		static std::string	value;
		value	= getValue().substr(offset, count);

		return value;
	}
	catch (std::out_of_range &)
	{
		throw dom::DOMException(dom::DOMException::INDEX_SIZE_ERR, "Index larger than Text node's value.");
	}
}

void			Text_Actual::appendData(const std::string & arg)
{
	std::string	value	= getValue();

	setValue(value.append(arg));
}

void			Text_Actual::insertData(int offset, const std::string & arg)
{
	std::string	value	= getValue();

	setValue(value.insert(offset, arg));
}

void			Text_Actual::deleteData(int offset, int count)
{
	std::string	value	= getValue();

	setValue(value.erase(offset, count));
}

void			Text_Actual::replaceData(int offset, int count, const std::string & arg)
{
	std::string	value	= getValue();

	setValue(value.erase(offset, count).insert(offset, arg));
}

dom::Text *		Text_Actual::splitText(int offset)
{
	try
	{
		dom::Text *	text	= new Text_Actual(substringData(offset, getLength() - offset), document);

		setValue(substringData(0, offset));

		if (getParentNode() != 0)
			insertBefore(text, getNextSibling());

		return text;
	}
	catch (std::out_of_range &)
	{
		throw dom::DOMException(dom::DOMException::INDEX_SIZE_ERR, "Index larget than Text node's value.");
	}
}