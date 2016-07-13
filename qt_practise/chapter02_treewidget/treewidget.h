#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>

namespace Ui {
class TreeWidget;
}

class TreeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TreeWidget(QWidget *parent = 0);
    ~TreeWidget();

private:
    Ui::TreeWidget *ui;
};

#endif // TREEWIDGET_H
