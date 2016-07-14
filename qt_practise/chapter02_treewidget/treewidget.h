#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>

class QTreeWidget;
class QTreeWidgetItem;

namespace Ui {
class TreeWidget;
}

class TreeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TreeWidget(QWidget *parent = 0);
    ~TreeWidget();

private slots:
    void on_tree_itemChanged(QTreeWidgetItem *item, int column);

private:
    // Function
    void setChildItemState(QTreeWidgetItem *item, Qt::CheckState state);
    bool updateParentItem(QTreeWidgetItem *item);
    void initTree();

    // Variable
    Ui::TreeWidget *ui;
};

#endif // TREEWIDGET_H
