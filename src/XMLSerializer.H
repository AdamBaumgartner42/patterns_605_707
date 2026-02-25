#include <string>
#include <fstream>
#include <ios>

#include "Node.H"

class Base
{
public:
	void serializeDocumentNode();

protected:
	virtual void onDocumentStart();

private:
	bool isDocument();

};

class XMLSerializer : public Base
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
