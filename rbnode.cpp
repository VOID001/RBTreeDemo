#include"rbnode.h"

RBNode::RBNode()
{

}

RBNode::RBNode(const int& key):nKey(key)
{
	
}

int RBNode::bh() const
{
	return nBh;
}

int RBNode::key() const
{
	return nKey;
}

NodeColor RBNode::color() const
{
	return nColor;
}

RBNode* RBNode::left() const
{
	return nLeft;
}

RBNode* RBNode::right() const
{
	return nRight;
}

RBNode* RBNode::parent() const
{
	return nParent;
}

void RBNode::setColor(const NodeColor &color)
{
	nColor=color;
}

void RBNode::setKey(const int &key)
{
	nKey=key;
}

void RBNode::setLeft(RBNode *node)
{
	nLeft=node;
}

void RBNode::setRight(RBNode *node)
{
	nRight=node;
}

void RBNode::setParent(RBNode *node)
{
	nParent=node;
}
