#include "treewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TreeWidget w;

    w.setGeometry(400, 250, 300, 300);
    w.setWindowTitle("tree widget");

    w.show();

    return a.exec();
}
