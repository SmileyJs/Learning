#include "treewidget.h"

treeWidget::treeWidget(QWidget *parent) : QWidget(parent)
    , ui(new Ui::treeWidget)
{

}

treeWidget::~treeWidget()
{
    delete ui;
}
