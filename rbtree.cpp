#include"rbtree.h"

Status RBTree::L_Rotate(RBNode *node)
{
	if(!isNil(node->right))
	{
		RBNode* rnode=node->right();
		node->setRight(rnode->left());
		if(!isNil(rnode->left))
		{
			rnode->left()->setParent();
		}
		rnode->setParent(node->parent());
		if(isNil(node->parent()));
		{
			root=rnode;
		}
		else if(node->parent()->left()==node)
		{
			node->parent()->setLeft(rnode);
		}
		else 
		{
			node->parent->setRight(rnode);
		}
		rnode->setLeft(node);
		node->setParent(rnode);
		return OK;
	}
	else
	{
		return TREECONSTRUCT_ERR;
	}
}

Status R_Rotate(RBNode* node)
{
	if(!isNil(node->left))
	{
		RBNode* lnode=node->left();
		node->setLeft(lnode->right());
		if(!isNil(lnode->right()))
		{
			lnode->right()->setParent(node);
		}
		lnode->setParent(node->parent());
		if(isNil(node->parent))
		{
			root=lnode;
		}
		else if(node->parent()->right()==node)
		{
			node->parent()->setRight(lnode);
		}
		else
		{
			node->parent()->setLeft(lnode);
		}
		lnode->setRight(node);
		node->setParent(lnode);
		return OK;
	}
	else
	{
		return TREECONSTRUCT_ERR;
	}
}

RBTree::RBTree()
{
	root=new RBNode;
	nil=new RBNode;
	root.setLeft(nil);
	root.setRight(nil);
	nil.setLeft(root);
	nil.setRight(root);
}


RBTree::~RBTree()
{

}
