#ifndef RBTREEDEMOWINDOW_H
#define RBTREEDEMOWINDOW_H

#include <QMainWindow>
#include"ui_rbtreedemowindow.h"
#include"rbtree.h"
#include"comm.h"


class RBTreeDemoWindow : public QMainWindow,public Ui::RBTreeDemoWindow
{
    Q_OBJECT
    
public:
    explicit RBTreeDemoWindow(QWidget *parent = 0);
    ~RBTreeDemoWindow();
    
	QGraphicsScene* scene;
	void addLink(RBNode* fromNode,RBNode* toNode);
	QVector<RBNode* > qvec;							//When addNode called add One Node to qvec
private:
	typedef QPair<RBNode*,RBNode*> NodePair;
	RBTree* rbT;
	int seqNumber;
	int zVal;
	void setupNode(RBNode* node);
	//void setZValue(int z);
	
private slots:
	void addNode();
	void delNode();
	//void delNode();
	void on_btnAddNode_clicked();
    void on_btnGenRBTree_clicked();
    void on_btnDelNode_clicked();
};


#endif // RBTREEDEMOWINDOW_H
