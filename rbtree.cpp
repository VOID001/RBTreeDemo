#include"rbtree.h"

Status RBTree::L_Rotate(RBNode *node)
{
	if(node->right()!=nil && node!=nil)
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
			root->setParent(nil);
			//nil->setParent(root);
			//nil->setLeft(root);
			//nil->setRight(root);
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
	if(node->left()!=nil && node!=nil)
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
			root->setParent(nil);
			//nil->setParent(root);
			//nil->setLeft(root);
			//nil->setRight(root);
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
	//t->setLeft(nil);
	//t->setRight(nil);
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
			root->setParent(nil);
			//nil->setParent(root);
			//nil->setLeft(root);
			//nil->setRight(root);
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
		insertAdjustRBNode(t);
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

//This is the adjust Code

Status RBTree::insertAdjustRBNode(RBNode *z)
{
	while(z->parent()->color()==RED)
	{
		if(z->parent()==z->parent()->parent()->left())
		{
			RBNode* y=z->parent()->parent()->right();
			if(y->color()==RED)
			{
				z->parent()->setColor(BLACK);
				y->setColor(BLACK);
				z->parent()->parent()->setColor(RED);
				z=z->parent()->parent();
			}
			else if(z==z->parent()->right())
			{
				z=z->parent();
				L_Rotate(z);
			}
			z->parent()->setColor(BLACK);
			if(z->parent()->parent()!=nil) z->parent()->parent()->setColor(RED);
			R_Rotate(z->parent()->parent());
		}
		else
		{
			RBNode* y=z->parent()->parent()->left();
			if(y->color()==RED)
			{
				z->parent()->setColor(BLACK);
				y->setColor(BLACK);
				z->parent()->parent()->setColor(RED);
				z=z->parent()->parent();
			}
			else if(z==z->parent()->left())
			{
				z=z->parent();
				R_Rotate(z);
			}
			z->parent()->setColor(BLACK);
			if(z->parent()->parent()!=nil) z->parent()->parent()->setColor(RED);
			L_Rotate(z->parent()->parent());
		}
	}
	root->setColor(BLACK);
	return OK;
}

RBNode* RBTree::__find_min(RBNode *node)
{
	RBNode* p=node;
	while(p!=nil)
	{
		p=p->left();
	}
	return p;
}

RBNode* RBTree::__find_max(RBNode *node)
{
	RBNode* p=node;
	while(p!=nil)
	{
		p=p->right();
	}
	return p;
}

Status RBTree::createTree(QVector<RBNode *> nodeContainer)
{
	foreach(RBNode* node,nodeContainer)
	{
		addNode(node->key());
	}
	return OK;
}



RBTree::RBTree()				//Initially the tree has no Node at all
{								//But here we use nil pivot instead of NULL to show the tree is empty
	nil=new RBNode;
	root=nil;
	nil->setLeft(nil);
	nil->setRight(nil);
	nil->setKey(23333);
	nil->setParent(nil);
	nil->setColor(BLACK);
	root->setParent(nil);
}


RBTree::~RBTree()
{

}
