#include "widget.h"
#include "treewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    treeWidget t;

    t.setGeometry(600, 250, 300, 300);
    t.setWindowTitle("tree widget");

    t.show();

    // 设置窗口的x,y,width,size，width和size又手widget中设置的maxsize和minsize影响
    w.setGeometry(400, 250, 300, 300);
    w.setWindowTitle("Chapter02_widget");

    w.show();

    return a.exec();
}
