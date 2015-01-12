#include "rbtreedemowindow.h"
#include "ui_rbtreedemowindow.h"

RBTreeDemoWindow::RBTreeDemoWindow(QWidget *parent) :
    QMainWindow(parent)
{
	//this->setFixedSize(this->sizeHint().width(),this->sizeHint().height());
	setupUi(this);
	scene=new QGraphicsScene(0,0,1000,1000);
	gviewRBTree->setScene(scene);
	gviewRBTree->setDragMode(QGraphicsView::RubberBandDrag);
	gviewRBTree->setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);
	seqNumber=0;
	rbT=new RBTree();
}


RBTreeDemoWindow::~RBTreeDemoWindow()
{

}

void RBTreeDemoWindow::addNode()
{
	bool ok=false;
	int addNum=txtAddNodeVal->text().toInt(&ok);
	if(!ok)
	{
		QMessageBox::warning(this,"Warning","You should input a integer");
		return ;
	}
	foreach(RBNode* node,qvec)
	{
		if((node->key())==addNum)
		{
			QMessageBox::warning(this,"Warning","The key has already exsist!");
			return ;
		}
	}
	RBNode* node=new RBNode;
	node->setKey(txtAddNodeVal->text().toInt());
	node->setText(txtAddNodeVal->text());
	qvec.push_back(node);
	rbT->addNode(node->key());
	//rbT->addNode(node->key());				//Unstable
	foreach(RBNode* node,qvec)				//Unstable			remove All Drawed Links and regenerate the Graph
	{
		foreach(RBLink* link,node->nodeLinks)
		{
			node->removeLink(link);
			scene->removeItem(link);
		}
	}

	setupNode(node);
	rbT->drawTree(this);				//Unstable
	scene->update();
}


void RBTreeDemoWindow::delNode()
{
	bool ok=false;
	int delNum=txtDelNodeVal->text().toInt(&ok);
	if(!ok)
	{
		QMessageBox::warning(this,"Warning","You should input a integer");
		return ;
	}
	int index=0;
	foreach(RBNode* node,qvec)
	{
		if((node->key())==delNum)
		{
			foreach(RBNode* node,qvec)				//Unstable			remove All Drawed Links and regenerate the Graph
			{
				foreach(RBLink* link,node->nodeLinks)
				{
					node->removeLink(link);
					scene->removeItem(link);
				}
			}
			qvec.remove(index);
			scene->removeItem(node);
			rbT->delNode(node->key());
			rbT->drawTree(this);
			scene->update();
			return ;
		}
		index++;
	}
	QMessageBox::warning(this,"Warning","The key has not been found!");
}

void RBTreeDemoWindow::setupNode(RBNode *node)
{
	node->setPos(QPoint(80+(100*(seqNumber%5)),80+(50*((seqNumber/5)%7))));
	scene->addItem(node);
	seqNumber++;

	scene->clearSelection();
	node->setSelected(true);
	//bringToFront();
}

void RBTreeDemoWindow::addLink(RBNode *fromNode, RBNode *toNode)
{
	foreach(RBNode* node,qvec)
	{
		foreach(RBLink* link,node->nodeLinks)
		{
			if(link->fromNode()==fromNode && link->toNode()==toNode) 
				return;
		}
	}

	RBLink* link=new RBLink(fromNode,toNode);
	scene->addItem(link);
}


void RBTreeDemoWindow::on_btnAddNode_clicked()
{
	addNode();
}

void RBTreeDemoWindow::on_btnGenRBTree_clicked()
{
	rbT->createTree(qvec);
	rbT->drawTree(this);
}

void RBTreeDemoWindow::on_btnDelNode_clicked()
{
	delNode();
}
