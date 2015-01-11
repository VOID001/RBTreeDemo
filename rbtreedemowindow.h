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
	RBTree rbT;
};

#endif // RBTREEDEMOWINDOW_H
