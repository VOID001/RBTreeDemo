#include "rbtreedemowindow.h"
#include"rbtree.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
	//QApplication a(argc, argv);
	//RBTreeDemoWindow w;
	//w.show();

	//return a.exec();
	
	//Core DEBUG Version
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
}
