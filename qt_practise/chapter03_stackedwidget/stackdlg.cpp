#include "stackdlg.h"

#include <QListWidget>
#include <QLabel>
#include <QStackedWidget>
#include <QHBoxLayout>

StackDlg::StackDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Stack Widget");
    setMaximumSize(400, 300);
    setMinimumSize(200, 150);

    QListWidget *list = new QListWidget(this);
    list->insertItem(0, "window1");
    list->insertItem(1, "window2");
    list->insertItem(2, "window3");

    QLabel *label1 = new QLabel("window1");
    QLabel *label2 = new QLabel("window2");
    QLabel *label3 = new QLabel("window3");

    QStackedWidget *stack = new QStackedWidget(this);
    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(5);
    layout->setSpacing(5);
    layout->addWidget(list);
    layout->addWidget(stack);
    layout->setStretchFactor(stack, 3);
    layout->setStretchFactor(list, 1);

    connect(list, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));
}

StackDlg::~StackDlg()
{

}
