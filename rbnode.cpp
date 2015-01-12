#include"rbnode.h"

RBNode::RBNode()
{
	setColor(BLACK);
	setFlags(ItemIsMovable|ItemIsSelectable);
}

RBNode::RBNode(const int& key):nKey(key)
{
	setColor(BLACK);
	setFlags(ItemIsMovable|ItemIsSelectable);
}

RBNode::~RBNode()
{
	foreach(RBLink* link,nodeLinks)
	{
		delete link;
	}
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

QColor RBNode::QBgColor() const
{
	return nBgColor;
}

QColor RBNode::QTextColor() const
{
	return nTextColor;
}

QColor RBNode::QOutlineColor() const
{
	return nOutlineColor;
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


void RBNode::setQOutlineColor(const QColor &color)
{
	nOutlineColor=color;
}

//Below are basic functions

void RBNode::addLink(RBLink *link)
{
	nodeLinks.insert(link);
}

void RBNode::removeLink(RBLink *link)
{
	nodeLinks.remove(link);
}

void RBNode::setText(const QString &s)
{
	prepareGeometryChange();
	nText=s;
	update();
}

void RBNode::setQBgColor(const QColor &color)
{
	nBgColor=color;
	update();
}

void RBNode::setQTextColor(const QColor &color)
{
	nTextColor=color;
	update();
}

QRectF RBNode::outlineRect() const
{
	const int Padding=8;
	QFontMetricsF metrics=qApp->fontMetrics();			//the code on this line is different than the code on the book 
	QRectF rect=metrics.boundingRect(nText);
	rect.adjust(-Padding,-Padding,+Padding,+Padding);
	rect.translate(-rect.center());
	
	return rect;
}

QRectF RBNode::boundingRect() const
{
	const int Margin=1;
	return outlineRect().adjusted(-Margin,-Margin,+Margin,+Margin);
}

QPainterPath RBNode::shape() const
{
	QRectF rect=outlineRect();
	
	QPainterPath path;
	path.addRoundedRect(rect,roundness(rect.width()),roundness(rect.height()));
	return path;
}

void RBNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	switch(nColor)
	{
	case BLACK:
		nBgColor=Qt::black;
		nOutlineColor=Qt::white;
		nTextColor=Qt::white;
		break;
	case RED:
		nBgColor=Qt::red;
		nOutlineColor=Qt::black;
		nTextColor=Qt::darkBlue;
	}
	QPen pen(nOutlineColor);
	if(option->state & QStyle::State_Selected)
	{
		pen.setStyle(Qt::DotLine);
		pen.setWidth(2);
	}
	painter->setPen(pen);
	painter->setBrush(nBgColor);
	QRectF rect=outlineRect();
	painter->drawRoundRect(rect,roundness(rect.width()),roundness(rect.height()));
	
	painter->setPen(nTextColor);
	painter->drawText(rect,Qt::AlignCenter,nText);
}

QVariant RBNode::itemChange(GraphicsItemChange change, const QVariant &value)
{
	if(change==ItemPositionHasChanged)
	{
		foreach(RBLink* link,nodeLinks)
		{
			link->trackNodes();
		}
	}
	return QGraphicsItem::itemChange(change,value);
}

int RBNode::roundness(double size) const
{
	const int Diameter=12;
	return 100* Diameter/(int) size;
}

void RBNode::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	//QMessageBox::warning(event->widget(),"He","he");
	this->setPos(QPointF(event->scenePos().rx(),event->scenePos().ry()));
	
	foreach(RBLink* link,nodeLinks)
	{
		link->trackNodes();
	}
}



