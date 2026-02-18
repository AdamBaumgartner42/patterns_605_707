#include "Node.H"

Node_Impl::Node_Impl(const std::string & n, short type) : name(n), nodeType(type), parent(0), document(0)
{
}

Node_Impl::~Node_Impl()
{
}

const std::string &	Node_Impl::getNodeName(void)
{
	return name;
}

const std::string &	Node_Impl::getNodeValue(void)
{
	return value;
}

void			Node_Impl::setNodeValue(const std::string & nodeValue)
{
	value	= nodeValue;
}

short			Node_Impl::getNodeType(void)
{
	return nodeType;
}

dom::Node *		Node_Impl::getParentNode(void)
{
	return parent;
}

dom::NodeList *		Node_Impl::getChildNodes(void)
{
	return &emptyNodes;
}

dom::Node *		Node_Impl::getFirstChild(void)
{
	return 0;
}

dom::Node *		Node_Impl::getLastChild(void)
{
	return 0;
}

dom::Node *		Node_Impl::getSibling(int direction)
{
	if (parent == 0)
		return 0;

	dom::NodeList::iterator	i	= parent->getChildNodes()->find(this);

	if (direction < 0)
	{
		if (i == parent->getChildNodes()->begin())
			return 0;
		else
			return *(--i);
	}
	else
	{
		i++;

		if (i == parent->getChildNodes()->end())
			return 0;
		else
			return *i;
	}
}

dom::Node *		Node_Impl::getPreviousSibling(void)
{
	return getSibling(-1);
}

dom::Node *		Node_Impl::getNextSibling(void)
{
	return getSibling(1);
}

dom::Document *		Node_Impl::getOwnerDocument(void)
{
	return document;
}

dom::Node *		Node_Impl::insertBefore(dom::Node * newChild, dom::Node * refChild)
{
	// (void)newChild;
	// (void)refChild;
	throw dom::DOMException(
		dom::DOMException::HIERARCHY_REQUEST_ERR, 
			"This node cannot have children.");
}

dom::Node *		Node_Impl::replaceChild(dom::Node * newChild, dom::Node * oldChild)
{
	// (void)newChild;
	// (void)refChild;
	throw dom::DOMException(
		dom::DOMException::HIERARCHY_REQUEST_ERR, 
			"This node cannot have children.");
}

dom::Node *		Node_Impl::removeChild(dom::Node * oldChild)
{
	// (void)newChild;
	// (void)refChild;
	throw dom::DOMException(
		dom::DOMException::HIERARCHY_REQUEST_ERR, 
			"This node cannot have children.");
}

dom::Node *		Node_Impl::appendChild(dom::Node * newChild)
{
	// (void)newChild;
	// (void)refChild;
	throw dom::DOMException(
		dom::DOMException::HIERARCHY_REQUEST_ERR, 
			"This node cannot have children.");
}

bool			Node_Impl::hasChildNodes(void)
{
	return false;
}

const std::string &	Node_Impl::getLocalName(void)
{
	return name;
}

void Node_Impl::setParent(dom::Node * parent)
{
	this->parent	= parent;
}

CompositeNode_Impl::CompositeNode_Impl(const std::string & n, short type) :
	Node_Impl(n, type)
{
}

CompositeNode_Impl::~CompositeNode_Impl()
{
}

dom::NodeList *	CompositeNode_Impl::getChildNodes(void)
{
	return &nodes;
}

dom::Node *	CompositeNode_Impl::getFirstChild(void)
{
	if (nodes.empty())
		return 0;

	return *nodes.begin();
}

dom::Node *	CompositeNode_Impl::getLastChild(void)
{
	if (nodes.empty())
		return 0;

	return *(--nodes.end());
}

dom::Node *	CompositeNode_Impl::insertBefore(dom::Node * newChild,
	dom::Node * refChild)
{
	if (newChild->getOwnerDocument() != getOwnerDocument())
		throw dom::DOMException(dom::DOMException::WRONG_DOCUMENT_ERR, "New Child is not a part of this document.");

	if (newChild->getParentNode() != 0)
		newChild->getParentNode()->removeChild(newChild);

	if (refChild == 0)
	{
		nodes.push_back(newChild);
		(dynamic_cast<Node_Impl *>(newChild))->setParent(this);
		return newChild;
	}

	dom::NodeList::iterator	index	= nodes.find(refChild);

	if (index == nodes.end())
		throw dom::DOMException(dom::DOMException::NOT_FOUND_ERR, "Reference Child is not a child of this node.");

	nodes.insert(++index, newChild);
	(dynamic_cast<Node_Impl *>(newChild))->setParent(this);

	return newChild;
}

dom::Node *	CompositeNode_Impl::replaceChild(dom::Node * newChild, 
	dom::Node * oldChild)
{
	if (newChild->getOwnerDocument() != getOwnerDocument())
		throw dom::DOMException(dom::DOMException::WRONG_DOCUMENT_ERR, "New Child is not a part of this document.");

	if (newChild->getParentNode() != 0)
		newChild->getParentNode()->removeChild(newChild);

	dom::NodeList::iterator	index	= nodes.find(oldChild);

	if (index == nodes.end())
		throw dom::DOMException(dom::DOMException::NOT_FOUND_ERR, "Old Child is not a child of this node.");

	nodes.insert(index, newChild);
	(dynamic_cast<Node_Impl *>(newChild))->setParent(this);
	(dynamic_cast<Node_Impl *>(*index))->setParent(0);
	nodes.erase(index);

	return oldChild;
}

dom::Node *	CompositeNode_Impl::removeChild(dom::Node * oldChild)
{
	dom::NodeList::iterator	index	= nodes.find(oldChild);

	if (index == nodes.end())
		throw dom::DOMException(dom::DOMException::NOT_FOUND_ERR, "Old Child is not a child of this node.");

	(dynamic_cast<Node_Impl *>(*index))->setParent(0);
	nodes.erase(index);

	return oldChild;
}

dom::Node *	CompositeNode_Impl::appendChild(dom::Node * newChild)
{
	if (newChild->getOwnerDocument() != getOwnerDocument())
		throw dom::DOMException(
			dom::DOMException::WRONG_DOCUMENT_ERR, 
			"New Child is not a part of this document.");

	if (newChild->getParentNode() != 0)
		newChild->getParentNode()->removeChild(newChild);

	nodes.push_back(newChild);
	(dynamic_cast<Node_Impl *>(newChild))->setParent(this);

	return newChild;
}

bool CompositeNode_Impl::hasChildNodes(void)
{
	return nodes.size() > 0;
}

const std::string &	Node_Impl::getLocalName(void)
{
	return name;
}

dom::NodeIterator *	Node_Impl::createIterator(void)
{
	return new DepthFirstNodeIterator(this);
}

void Node_Impl::setParent(dom::Node * parent)
{
	this->parent	= parent;
}

dom::Node *		Node_Impl::getSibling(int direction)
{
	if (parent == 0)
		return 0;

	dom::NodeList::iterator	i	= parent->getChildNodes()->find(this);

	if (direction < 0)
	{
		if (i == parent->getChildNodes()->begin())
			return 0;
		else
			return *(--i);
	}
	else
	{
		i++;

		if (i == parent->getChildNodes()->end())
			return 0;
		else
			return *i;
	}
}

DepthFirstNodeIterator::DepthFirstNodeIterator(dom::Node * root)
{
	if (root != 0)
	{
		stack.push_back(StackEntry(root, false));
	}
}

bool DepthFirstNodeIterator::hasNext(void)
{
	return stack.size() > 0;
}

dom::TraversalStep	DepthFirstNodeIterator::next(void)
{
	StackEntry entry = stack.back();
	stack.pop_back();

	if (entry.isClosing)
	{
		return dom::TraversalStep(entry.node, false);
	}

	if (entry.node->getNodeType() == dom::Node::ELEMENT_NODE)
	{
		if (entry.node->hasChildNodes()){
			stack.push_back(StackEntry(entry.node, true));
		}

		for (dom::NodeList::reverse_iterator i = entry.node->getChildNodes()->rbegin();
		  i != entry.node->getChildNodes()->rend();
		  i++){
			stack.push_back(StackEntry(*i, false));
		  }	
	}
	
	return dom::TraversalStep(entry.node, true);
}
