#ifndef RBTREE_H
#define RBTREE_H
#include "comm.h"
#include "rbnode.h"

class RBTree
{
private:
	RBNode* root;
	RBNode* nil;					//the pivot which has a useless value
	Status L_Rotate(RBNode* node);
	Status R_Rotate(RBNode* node);
	bool isNil(RBNode* node);
	RBNode* __find(const int& key);
	Status adjustRBNode(RBNode* node);
	//Status __addNode(RBNode* z);
public:
	Status addNode(const int& key);
	Status delNode(const int& key);
	Status find(const int& key);
	Status createTree(QVector<RBNode*> nodeContainer);
	
	//RBTree(QVector<RBNode*> nodeContanier);
	RBTree();
	~RBTree();
	
};

#endif // RBTREE_H
