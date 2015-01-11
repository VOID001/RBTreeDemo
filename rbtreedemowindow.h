#ifndef RBTREEDEMOWINDOW_H
#define RBTREEDEMOWINDOW_H

#include <QMainWindow>
#include"ui_rbtreedemowindow.h"

class RBTreeDemoWindow : public QMainWindow,public Ui::RBTreeDemoWindow
{
    Q_OBJECT
    
public:
    explicit RBTreeDemoWindow(QWidget *parent = 0);
    ~RBTreeDemoWindow();
    
private:
};

#endif // RBTREEDEMOWINDOW_H
