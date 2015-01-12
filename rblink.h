#ifndef RBLINK_H
#define RBLINK_H
#include "comm.h"
#include "rbnode.h"

class RBLink:public QGraphicsLineItem
{
public:
	RBLink(RBNode* fromNode,RBNode* toNode);
	~RBLink();
	RBNode* toNode() const;
	RBNode* fromNode() const;
	void setColor(const QColor& color);
	QColor color() const;
	
	void trackNodes();
private:
	RBNode* myFromNode;
	RBNode* myToNode;
};


#endif // RBLINK_H
