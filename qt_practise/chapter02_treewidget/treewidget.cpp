#include "treewidget.h"
#include "ui_treewidget.h"

TreeWidget::TreeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreeWidget)
{
    ui->setupUi(this);

    setMaximumSize(500, 500);
    setMinimumSize(200, 200);
}

TreeWidget::~TreeWidget()
{
    delete ui;
}
