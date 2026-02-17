#include "XMLSerializer.H"

#include "Document.H"
#include "Element.H"
#include "Attr.H"
#include "Text.H"

void XMLSerializer::prettyIndentation()
{
	for (int i = 0; i < indentationLevel; i++)
		file << "\t";
}

void XMLSerializer::serializePretty(dom::Node * node)
{
	dom::Node *	root = node;

	if (dynamic_cast<dom::Document *>(node) != 0)
	{
		file << "<? xml version=\"1.0\" encoding=\"UTF-8\"?>";
		file << "\n";
		root = dynamic_cast<dom::Document *>(node)->getDocumentElement();
	}

	if (root == 0)
	{
		return;
	}

	dom::NodeIterator * iterator = root->createIterator();

	while(iterator->hasNext())
	{
		dom::TraversalStep step = iterator->next();
		dom::Node * current = step.node;

		if (dynamic_cast<dom::Element *>(current) != 0)
		{
			dom::Element * element = dynamic_cast<dom::Element *>(current);
			if (step.isOpening)
			{
				prettyIndentation();
				file << "<" << element->getTagName();
				for (dom::NamedNodeMap::iterator i = dynamic_cast<dom::Element *>(node)->getAttributes()->begin();
					i != dynamic_cast<dom::Element *>(node)->getAttributes()->end();
					i++)
				{
					file << " " << dynamic_cast<dom::Attr *>(*i)->getName() <<"=\"" << dynamic_cast<dom::Attr *>(*i)->getValue() << "\"";

					if (element->hasChildNodes())
					{
						file << ">";
						file << "\n";
					}
					else
					{
						file << "/>";
						file << "\n";
						indentationLevel++;
					}
				}	
			}
			else
			{
				indentationLevel--;
				prettyIndentation();
				file << "</" << element->getTagName() << ">";
				file << "\n";
			}
		}
		else if (step.isOpening && dynamic_cast<dom::Text *>(current) != 0)
		{
			prettyIndentation();
			file << dynamic_cast<dom::Text *>(current)->getData();
			file << "\n";
		}
	}

	delete iterator;
}

void XMLSerializer::serializeMinimal(dom::Node * node)
{
	dom::Node *	root = node;

	if (dynamic_cast<dom::Document *>(node) != 0)
	{
		file << "<? xml version=\"1.0\" encoding=\"UTF-8\"?>";
		root = dynamic_cast<dom::Document *>(node)->getDocumentElement();
	}

	if (root == 0)
	{
		return;
	}

	dom::NodeIterator * iterator = root->createIterator();

	while(iterator->hasNext())
	{
		dom::TraversalStep step = iterator->next();
		dom::Node * current = step.node;

		if (dynamic_cast<dom::Element *>(current) != 0)
		{
			dom::Element * element = dynamic_cast<dom::Element *>(current);
			if (step.isOpening)
			{
				file << "<" << element->getTagName();
				for (dom::NamedNodeMap::iterator i = dynamic_cast<dom::Element *>(node)->getAttributes()->begin();
					i != dynamic_cast<dom::Element *>(node)->getAttributes()->end();
					i++)
				{
					file << " " << dynamic_cast<dom::Attr *>(*i)->getName() <<"=\"" << dynamic_cast<dom::Attr *>(*i)->getValue() << "\"";

					if (element->hasChildNodes())
					{
						file << ">";
					}
					else
					{
						file << "/>";
					}
				}	
			}
			else
			{
				file << "</" << element->getTagName() << ">";
			}
		}
		else if (step.isOpening && dynamic_cast<dom::Text *>(current) != 0)
		{
			file << dynamic_cast<dom::Text *>(current)->getData();
		}
	}

	delete iterator;
}
