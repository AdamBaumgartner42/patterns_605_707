#include <string>
#include <fstream>
#include <ios>

#include "Node.H"

class Base
{
private:
	bool isDocument(dom::Node * node);

protected:
	// These are the primitive methods
	virtual void onDocumentStart() = 0;
	virtual void onDocumentRecurse(dom::Node * node) = 0;

public:
	// This is the template
	void serializeDocumentNode(dom::Node * node);

};

class XMLSerializer
{
private:
	std::fstream		file;
	int			indentationLevel;

	virtual void		prettyIndentation();
public:
	XMLSerializer(const std::string & filename) : indentationLevel(0), file(filename.c_str(), std::ios_base::out)	{}
	~XMLSerializer() {}

	virtual void		serializePretty(dom::Node * node);
	virtual void		serializeMinimal(dom::Node * node);
};

class Pretty : public Base
{
private:
	std::fstream		file;
	int			indentationLevel;

	virtual void		prettyIndentation();

protected:
	void onDocumentStart();
	void onDocumentRecurse(dom::Node * node);

public:
	Pretty(const std::string & filename) : indentationLevel(0), file(filename.c_str(), std::ios_base::out)	{}
	~Pretty() {}

	virtual void		serialize(dom::Node * node);
};


class Minimal : public Base
{
private:
	std::fstream		file;
	int			indentationLevel;

protected:
	void onDocumentStart();
	void onDocumentRecurse(dom::Node * node);

public:
	Minimal(const std::string & filename) : indentationLevel(0), file(filename.c_str(), std::ios_base::out)	{}
	~Minimal() {}

	virtual void		serialize(dom::Node * node);
};