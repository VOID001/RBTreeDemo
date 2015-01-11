#ifndef RBNODE_H
#define RBNODE_H
#include"comm.h"
#include"rblink.h"

class RBNode:public QGraphicsItem
{
private:
	int nKey;
	int nBh;
	NodeColor nColor;
	RBNode* nParent;
	RBNode* nLeft,*nRight;
	
	QColor nbgColor;
	QColor ntextColor;
	QString nText;
	QSet<Link*> nodeLinks;
	QRectF outlineRect() const;
	int roundness(double size) const;
public:
	RBNode(const int& key);
	RBNode();
	int bh() const;
	int key() const;
	NodeColor color() const;
	RBNode* left() const;
	RBNode* right() const;
	RBNode* parent() const;
	void setLeft(RBNode* node);
	void setRight(RBNode* node);
	void setParent(RBNode* node);
	void setKey(const int& key);
	void setColor(const NodeColor& color);

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void addLink(RBLink* link);
	void removeLink(RBLink* link);
	//operator Overload But now maybe not useful
	//bool operator < (const RBNode& a) const
	//{
	//	return (*this).key()<a.key();
	//}
	//bool operator > (const RBNode& a) const  {return    a<(*this); }
	//bool operator <= (const RBNode& a) const {return !((*this)>a); }
	//bool operator >= (const RBNode& a) const {return !(a<(*this)); }
	//bool operator == (const RBNode& a) const {return !(a>*this && *this>a); }
	//bool operator !=(const RBNode& a) const  {return !(a==(*this));}
protected:
	QVariant itemChange(GraphicsItemChange change, const QVariant &value);
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	
	
};

#endif // RBNODE_H
