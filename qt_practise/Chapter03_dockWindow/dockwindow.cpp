#include "dockwindow.h"

#include <QDockWidget>
#include <QTextEdit>

DockWindow::DockWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMaximumSize(600, 600);
    setMinimumSize(300, 300);

    setWindowTitle("DockWindows");
    QTextEdit *MainText = new QTextEdit("MainText", this);
    setCentralWidget(MainText);

    QDockWidget *dockTop = new QDockWidget("Top Window", this);
    dockTop->setFeatures(QDockWidget::DockWidgetClosable);
    dockTop->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    QTextEdit *topText = new QTextEdit("Top");
    dockTop->setWidget(topText);
    addDockWidget(Qt::TopDockWidgetArea, dockTop);

    QDockWidget *dockCenter = new QDockWidget("Center Window", this);
    dockCenter->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    dockCenter->setAllowedAreas(Qt::AllDockWidgetAreas);
    QTextEdit *centerText = new QTextEdit("Center");
    dockCenter->setWidget(centerText);
    addDockWidget(Qt::LeftDockWidgetArea, dockCenter);

    QDockWidget *dockBottom = new QDockWidget("Bottom Window", this);
    dockBottom->setFeatures(QDockWidget::AllDockWidgetFeatures);
    dockBottom->setAllowedAreas(Qt::AllDockWidgetAreas);
    QTextEdit *bottomText = new QTextEdit("Bottom");
    dockBottom->setWidget(bottomText);
    addDockWidget(Qt::RightDockWidgetArea, dockBottom);
}

DockWindow::~DockWindow()
{

}
