#ifndef TEXT_ACTUAL_H
#define TEXT_ACTUAL_H

#include <string>

#include "Node.H"


class Text_Actual : public virtual dom::Text, Node_Impl
{
protected:
	Text_Actual(const std::string value, dom::Document * document);
public:
	friend class Text_Impl;

	virtual ~Text_Actual();

	virtual const std::string &	getName(void);
	virtual const std::string &	getData(void);
	virtual const std::string &	getValue(void);
	virtual void			setData(const std::string & value);
	virtual void			setValue(const std::string & value);
	virtual int			getLength(void);
	virtual const std::string &	substringData(int offset, int count);
	virtual void			appendData(const std::string & arg);
	virtual void			insertData(int offset, const std::string & arg);
	virtual void			deleteData(int offset, int count);
	virtual void			replaceData(int offset, int count, const std::string & arg);
	virtual dom::Text *		splitText(int offset);
};

#endif // TEXT_ACTUAL

