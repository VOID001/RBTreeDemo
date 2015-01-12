#include "rbtreedemowindow.h"
#include"rbtree.h"
#include <QApplication>

using namespace std;

//#define DEBUG;

int main(int argc, char *argv[])
{
	#ifndef DEBUG
	QApplication a(argc, argv);
	RBTreeDemoWindow w;
	w.show();

	return a.exec();
	
	#endif
	//Core DEBUG Version
	#ifdef DEBUG
	QVector<RBNode*> qvec;
	qvec.clear();
	cout<<"*************DEBUG MODE***************"<<endl;
	int n;
	cout<<"Input the number of nodes you want to put"<<endl;
	scanf("%d",&n);
	cout<<"Now input the "<< n <<" number(s)"<<endl;
	while(n--)
	{
		int t;
		scanf("%d",&t);
		RBNode* tmp=new RBNode(t);
		qvec.push_back(tmp);
	}
	RBTree rbT;
	rbT.createTree(qvec);
	cout<<"Now input the node you want to delete"<<endl;
	int a;
	cin>>a;
	rbT.delNode(a);
	cin>>a;
	#endif
}
