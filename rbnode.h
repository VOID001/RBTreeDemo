#ifndef RBNODE_H
#define RBNODE_H
#include"comm.h"
#include"rblink.h"

class RBNode:public QGraphicsItem
{
	Q_DECLARE_TR_FUNCTIONS(RBNode)
private:
	int nKey;
	int nBh;
	NodeColor nColor;
	RBNode* nParent;
	RBNode* nLeft,*nRight;
	
	QColor nBgColor;
	QColor nTextColor;
	QColor nOutlineColor;
	QString nText;
	QRectF outlineRect() const;
	int roundness(double size) const;
public:
	QSet<RBLink* > nodeLinks;
	
	RBNode(const int& key);
	RBNode();
	~RBNode();
	int bh() const;
	int key() const;
	NodeColor color() const;
	RBNode* left() const;
	RBNode* right() const;
	RBNode* parent() const;
	QColor QBgColor() const;
	QColor QTextColor() const;
	QColor QOutlineColor() const;
	void setLeft(RBNode* node);
	void setRight(RBNode* node);
	void setParent(RBNode* node);
	void setKey(const int& key);
	void setColor(const NodeColor& color);
	void setQBgColor(const QColor& color);
	void setQTextColor(const QColor& color);
	void setQOutlineColor(const QColor& color);
	void setText(const QString& s);

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void addLink(RBLink* link);
	void removeLink(RBLink* link);
	QRectF boundingRect() const;
	QPainterPath shape() const;
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
