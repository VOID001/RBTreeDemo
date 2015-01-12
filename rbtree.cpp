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

Status RBTree::delNode(const int &key)
{
	RBNode* p=__find(key);
	if(p==nil)
	{
		return NOTFOUND;
	}
	if(p->left()!=nil && p->right()!=nil)
	{
		RBNode* succ=inOrderSuccessor(p);
		p->setKey(succ->key());
		p=succ;
	}
	RBNode* pchild;
	if(p->right()!=nil)
	{
		pchild=p->right();
	}
	else if(p->left()!=nil)
	{
		pchild=p->left();
	}
	else
	{
		pchild=nil;
	}
	pchild->setParent(p->parent());
	if(p->parent()==nil)
	{
		root=nil;
	}
	else if(p==p->parent()->right())
	{
		p->parent()->setRight(pchild);
	}
	else
	{
		p->parent()->setLeft(pchild);
	}
	if(p->color()==BLACK && !(pchild==nil && pchild->parent()==nil))
	{
		deleteAdjustRBNode(pchild);
	}
	delete pchild;
	return OK;
	
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

Status RBTree::deleteAdjustRBNode(RBNode *node)
{
	while(node!=root && node->color()==BLACK)
	{
		if(node==node->parent()->left())
		{
			RBNode* bro=node->parent()->right();
			if(bro->color()==RED)
			{
				bro->setColor(BLACK);
				if(node!=nil) node->parent()->setColor(RED);
				L_Rotate(node->parent());
			}
			else
			{
				if(bro->left()->color()==BLACK && bro->right()->color()==BLACK)
				{
					if(bro!=nil) bro->setColor(RED);
					node=node->parent();
				}
				else if(bro->right()->color()==BLACK)
				{
					if(bro!=nil) bro->setColor(RED);
					bro->left()->setColor(BLACK);
					R_Rotate(bro);
				}
				else if(bro->right()->color()==RED)
				{
					if(bro!=nil) bro->setColor(node->parent()->color());
					node->parent()->setColor(BLACK);
					bro->right()->setColor(BLACK);
					L_Rotate(node->parent());
					node=root;
				}
			}
		}
		else
		{
			RBNode* bro=node->parent()->left();
			if(bro->color()==RED)
			{
				bro->setColor(BLACK);
				if(node!=nil) node->parent()->setColor(RED);
				R_Rotate(node->parent());
			}
			else
			{
				if(bro->left()->color()==BLACK && bro->right()->color()==BLACK)
				{
					if(bro!=nil) bro->setColor(RED);
					node=node->parent();
				}
				else if(bro->left()->color()==BLACK)
				{
					if(bro!=nil) bro->setColor(RED);
					bro->right()->setColor(BLACK);
					L_Rotate(bro);
				}
				else if(bro->left()->color()==RED)
				{
					if(bro!=nil) bro->setColor(node->parent()->color());
					node->parent()->setColor(BLACK);
					bro->left()->setColor(BLACK);
					R_Rotate(node->parent());
					node=root;
				}
			}
		}
	}
	root=node;
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

RBNode* RBTree::inOrderSuccessor(RBNode* node)
{
	if(node==nil)
	{
		return nil;
	}
	RBNode* p = node->right();
	while(p!=nil)
	{
		if(p->left()!=nil)
		{
			p=p->left();
		}
		else
		{
			break;
		}
	}
	if(p == nil)  
	{  
		RBNode* pIndex = node->parent();  
		pIndex = node;  
		while(pIndex!=nil && p == p->right())  
		{  
			p = pIndex;  
			pIndex = pIndex->parent();  
		}  
		p = pIndex;         //first parent's left or null  
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

Status RBTree::drawTree(RBTreeDemoWindow* window)
{
	__drawTree(window,root,nil,0);
	return OK;
}

Status RBTree::__drawTree(RBTreeDemoWindow* window,RBNode *node,RBNode *father,int pos)
{
	if(node==nil)
	{
		return OK;
	}
	else
	{
		RBNode* pNode;
		RBNode* pFatherNode;
		foreach(RBNode* tpNode,window->qvec)
		{
			if(tpNode->key()==node->key())
			{
				pNode=tpNode;
				pNode->setColor(node->color());
			}
			if(tpNode->key()==father->key())
			{
				pFatherNode=tpNode;
				pFatherNode->setColor(father->color());
			}
		}
		if(node==root)
		{
			node->setPos(QPoint(sceneCenterPosX,sceneHeaderPosY));
			pNode->setPos(QPoint(sceneCenterPosX,sceneHeaderPosY));
		}
		else
		{
			node->setPos(QPoint(father->pos().rx()+pos*30000*(1.0/father->pos().ry()),father->pos().ry()+40));				//waiting for more elegant way to deal with it
			pNode->setPos(QPoint(father->pos().rx()+pos*30000*(1.0/father->pos().ry()),father->pos().ry()+40));
		}
		node->setText(QString(QObject::tr("%1").arg(node->key())));
		//window->scene->addItem(node);
		if(father!=nil)
		{
			//window->addLink(father,node);
			window->addLink(pFatherNode,pNode);
		}
		__drawTree(window,node->left(),node,-1);
		__drawTree(window,node->right(),node,1);
	}
	return OK;
}

bool RBTree::empty()
{
	if(root==nil) return true;
	return false;
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
