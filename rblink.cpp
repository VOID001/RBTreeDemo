#include"rblink.h"

RBLink::RBLink(RBNode *fromNode, RBNode *toNode)
{
	myFromNode=fromNode;
	myToNode=toNode;
	myFromNode->addLink(this);
	myToNode->addLink(this);
	setFlags(QGraphicsItem::ItemIsSelectable);
	setZValue(-1);
	setColor(Qt::black);
	trackNodes();
}

RBLink::~RBLink()
{
	myFromNode->removeLink(this);
	myToNode->removeLink(this);
}

void RBLink::setColor(const QColor &color)
{
	setPen(QPen(color,1.0));
}

QColor RBLink::color() const
{
	return this->pen().color();
}

void RBLink::trackNodes()
{
	setLine(QLineF(myFromNode->pos(),myToNode->pos()));			//Use Coordinate to set a line
}

