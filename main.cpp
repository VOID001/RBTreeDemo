#include "rbtreedemowindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RBTreeDemoWindow w;
    w.show();
    
    return a.exec();
}
