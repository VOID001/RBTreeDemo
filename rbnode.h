#ifndef RBNODE_H
#define RBNODE_H

class RBNode
{
private:
	int key;
	int bh;
	int color;				//0 is black 1 is red
	RBNode* parent;
	RBNode* left,right;
public:
	RBNode(const int& key);
	int bh() const;
	int key() const;
	int color() const;
	RBNode* left() const;
	RBNode* right() const;
	RBNode* parent() const;
	void setLeft(const RBNode* node);
	void setRight(const RBNode* node);
	void setParent(const RBNode* node);
};

#endif // RBNODE_H
