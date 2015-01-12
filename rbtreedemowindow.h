#ifndef RBTREEDEMOWINDOW_H
#define RBTREEDEMOWINDOW_H

#include <QMainWindow>
#include"ui_rbtreedemowindow.h"
#include"rbtree.h"


class RBTreeDemoWindow : public QMainWindow,public Ui::RBTreeDemoWindow
{
    Q_OBJECT
    
public:
    explicit RBTreeDemoWindow(QWidget *parent = 0);
    ~RBTreeDemoWindow();
    
private:
	typedef QPair<RBNode*,RBNode*> NodePair;
	RBTree rbT;
	QGraphicsScene* scene;
	QVector<RBNode* > qvec;							//When addNode called add One Node to qvec
	int seqNumber;
	int zVal;
	void setupNode(RBNode* node);
	//void setZValue(int z);
	
private slots:
	void addNode();
	//void delNode();
	void addLink(RBNode* fromNode,RBNode* toNode);
	void on_btnAddNode_clicked();
};


#endif // RBTREEDEMOWINDOW_H
