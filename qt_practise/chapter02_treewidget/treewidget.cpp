#include "treewidget.h"
#include "ui_treewidget.h"

#include <QDebug>
#include <QTreeWidget>
#include <QTreeWidgetItem>

TreeWidget::TreeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreeWidget)
{
    ui->setupUi(this);

    setMaximumSize(500, 500);
    setMinimumSize(200, 200);

    initTree();
}

TreeWidget::~TreeWidget()
{
    delete ui;
}

void
TreeWidget::initTree()
{
    qDebug() << "TreeWidget::initTree";

    ui->tree->clear();

    QTreeWidgetItem *group1 = new QTreeWidgetItem(ui->tree);
    group1->setText(0, "item1");
    group1->setCheckState(0, Qt::Unchecked);
    group1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QTreeWidgetItem *subItem1_1 = new QTreeWidgetItem(group1);
    subItem1_1->setText(0, "subItem1_1");
    subItem1_1->setCheckState(0, Qt::Unchecked);
    subItem1_1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);

    QTreeWidgetItem *subItem1_2 = new QTreeWidgetItem(group1);
    subItem1_2->setText(0, "subItem1_2");
    subItem1_2->setCheckState(0, Qt::Unchecked);
    subItem1_2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);

    QTreeWidgetItem *subItem1_3 = new QTreeWidgetItem(group1);
    subItem1_3->setText(0, "subItem1_3");
    subItem1_3->setCheckState(0, Qt::Unchecked);
    subItem1_3->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);

    QTreeWidgetItem *subItem1_4 = new QTreeWidgetItem(group1);
    subItem1_4->setText(0, "subItem1_4");
    subItem1_4->setCheckState(0, Qt::Unchecked);
    subItem1_4->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);

    QTreeWidgetItem *group2 = new QTreeWidgetItem(ui->tree);
    group2->setText(0, "item2");
    group2->setCheckState(0, Qt::Unchecked);
    group2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QTreeWidgetItem *subItem2_1 = new QTreeWidgetItem(group2);
    subItem2_1->setText(0, "subItem2_1");
    subItem2_1->setCheckState(0, Qt::Unchecked);
    subItem2_1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QTreeWidgetItem *subItem2_2 = new QTreeWidgetItem(group2);
    subItem2_2->setText(0, "subItem2_2");
    subItem2_2->setCheckState(0, Qt::Unchecked);
    subItem2_2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QTreeWidgetItem *subItem2_3 = new QTreeWidgetItem(group2);
    subItem2_3->setText(0, "subItem2_3");
    subItem2_3->setCheckState(0, Qt::Unchecked);
    subItem2_3->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QTreeWidgetItem *subItem2_4 = new QTreeWidgetItem(group2);
    subItem2_4->setText(0, "subItem2_4");
    subItem2_4->setCheckState(0, Qt::Unchecked);
    subItem2_4->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
}

bool
TreeWidget::updateParentItem(QTreeWidgetItem *item)
{
    qDebug() << "TreeWidget::updateParentItem";

    QTreeWidgetItem *parent = item->parent();

    if (NULL == parent) {
        qDebug() << "TreeWidget::updateParentItem--parent is NULL";
        return false;
    }

    int chindCount = parent->childCount();
    int selectCount = 0;

    for (int i = 0; i < chindCount; ++i) {
        QTreeWidgetItem *child = parent->child(i);
        if (Qt::Checked == child->checkState(0)) {
            ++selectCount;
        }
    }

    if (0 == selectCount) {
        parent->setCheckState(0, Qt::Unchecked);
    }
    else if (0 < selectCount && chindCount > selectCount) {
        parent->setCheckState(0, Qt::PartiallyChecked);
    }
    else if (chindCount == selectCount) {
        parent->setCheckState(0, Qt::Checked);
    }

    return true;
}

void TreeWidget::setChildItemState(QTreeWidgetItem *item, Qt::CheckState state)
{
    qDebug() << "TreeWidget::setChildItemState";

    for (int i = 0; i < 4; ++i) {
        item->child(i)->setCheckState(0, state);
    }
}

void TreeWidget::on_tree_itemChanged(QTreeWidgetItem *item, int column)
{
    qDebug() << "TreeWidget::on_tree_itemChanged" << item << column;

    int count = item->childCount();

    if (0 < count) {
        if (Qt::Checked == item->checkState(column)) {
            setChildItemState(item, Qt::Checked);
        }
        else if (Qt::Unchecked == item->checkState(column)) {
            setChildItemState(item, Qt::Unchecked);
        }
    }
    else {
        updateParentItem(item);
    }
}
