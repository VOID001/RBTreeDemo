#include"rbtree.h"

Status RBTree::L_Rotate(RBNode *node)
{
	if(node->right()!=nil)
	{
		RBNode* rnode=node->right();
		node->setRight(rnode->left());
		if(rnode->left()!=nil)
		{
			rnode->left()->setParent(node);
		}
		rnode->setParent(node->parent());
		if(node->parent()==nil)
		{
			root=rnode;
		}
		else if(node->parent()->left()==node)
		{
			node->parent()->setLeft(rnode);
		}
		else 
		{
			node->parent()->setRight(rnode);
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

Status RBTree::R_Rotate(RBNode* node)
{
	if(node->left()!=nil)
	{
		RBNode* lnode=node->left();
		node->setLeft(lnode->right());
		if(lnode->right()!=nil)
		{
			lnode->right()->setParent(node);
		}
		lnode->setParent(node->parent());
		if(node->parent()==nil)
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

Status RBTree::addNode(const int &mykey)
{
	RBNode* p=nil;
	RBNode* pre=nil;
	RBNode* t=new RBNode;
	t->setKey(mykey);
	p=__find(mykey);
	if(p==nil)
	{
		p=root;
		while(p!=nil)
		{
			pre=p;
			if(mykey<p->key())
			{
				p=p->left();
			}
			else
			{
				p=p->right();
			}
		}
		t->setParent(pre);
		if(pre==nil)				//The pointer dosen't move at all means the tree is empty
		{
			root=t;
		}
		else if(t->key()<pre->key())
		{
			pre->setLeft(t);
		}
		else
		{
			pre->setRight(t);
		}
		t->setLeft(nil);
		t->setRight(nil);
		t->setColor(RED);
		//adjustRBNode(t);
	}
	else
	{
		return NODE_ALREADY_EXIST;
	}
}

RBNode* RBTree::__find(const int &mykey)
{
	RBNode* p=root;
	while(p!=nil)
	{
		if(p->key()==mykey) return p;
		if(mykey<p->key())
		{
			p=p->left();
		}
		else
		{
			p=p->right();
		}
	}
	return nil;
}



RBTree::RBTree()				//Initially the tree has no Node at all
{								//But here we use nil pivot instead of NULL to show the tree is empty
	nil=new RBNode;
	nil->setLeft(root);
	nil->setRight(root);
	root=nil;
}


RBTree::~RBTree()
{

}
