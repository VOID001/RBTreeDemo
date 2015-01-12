#include "rbtreedemowindow.h"
#include "ui_rbtreedemowindow.h"

RBTreeDemoWindow::RBTreeDemoWindow(QWidget *parent) :
    QMainWindow(parent)
{
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
	setupNode(node);
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
