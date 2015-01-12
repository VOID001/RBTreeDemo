#ifndef RBTREE_H
#define RBTREE_H
#include "comm.h"
#include "rbnode.h"
#include "rbtreedemowindow.h"


class RBTree
{
private:
	RBNode* root;
	RBNode* nil;					//the pivot which has a useless value
	Status L_Rotate(RBNode* node);
	Status R_Rotate(RBNode* node);
	bool isNil(RBNode* node);
	RBNode* __find(const int& key);
	RBNode* __find_min(RBNode* node);
	RBNode* __find_max(RBNode* node);
	Status insertAdjustRBNode(RBNode* node);
	Status __drawTree(RBTreeDemoWindow* window,RBNode* node, RBNode* father, int pos);			//this is a very important step!
	//Status __addNode(RBNode* z);
public:
	Status addNode(const int& key);
	Status delNode(const int& key);
	Status find(const int& key);
	Status createTree(QVector<RBNode*> nodeContainer);
	Status drawTree(RBTreeDemoWindow *window);
	//RBTree(QVector<RBNode*> nodeContanier);
	bool empty();
	RBTree();
	~RBTree();
	
};

#endif // RBTREE_H
