#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QLabel>
#include <QDateTime>
#include <QDebug>
#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QTableView>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlDatabase>
#include <QStandardItemModel>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setMaximumSize(300, 300);
    setMinimumSize(150, 100);

/****************QPushButton******************
    QPushButton *quit = new QPushButton("Quit", this);

    quit->setGeometry(20, 30, 100, 40);
    quit->setFont(QFont("Times", 17, QFont::Bold, true));

    connect(quit, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
*/

/******************QDateTime******************
    QLabel *date = new QLabel(this);
    date->setGeometry(20, 20, 200, 20);
    date->setTextFormat(Qt::AutoText);
    QDateTime *dateTime = new QDateTime(QDateTime::currentDateTime());

    date->setText(dateTime->date().toString() + " " + dateTime->time().toString());
    date->show();
*/

/*****************QTimer*******************
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->start(5000);
    connect(timer, SIGNAL(timeout()), qApp, SLOT(quit()));

    QLabel *label_caution = new QLabel("Window will close after 5 seconds", this, Qt::Window);

    label_caution->setWordWrap(true);
    label_caution->show();
*/

/**************************************
    QWidget *window = new QWidget();
    window->resize(400, 300);
    window->show();

    // tr is used to translate language.
    QPushButton *button = new QPushButton(tr("Press me!"), window);
    button->move(100, 100);
    button->show();
*/

/***************************************
    QLabel *label = new QLabel("label1");
    QLineEdit *lineEdit = new QLineEdit();
    label->show();
    lineEdit->show();

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(lineEdit);

//    window()->setLayout(layout);
*/

/******************QTableView*******************/
//    QSqlTableModel *model = new QSqlTableModel();
//    model->setTable("Employee");
//    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    model->select();
//    model->setHeaderData(0, Qt::Horizontal, "Name");
//    model->setHeaderData(1, Qt::Horizontal, "Salary");
//    model->setData(model->index(0, 0, QModelIndex()), QVariant(11));


    int tableRow = 4;
    int tableColumn = 2;
    QStandardItemModel *model = new QStandardItemModel(tableRow, tableColumn);
    model->setHeaderData(0, Qt::Horizontal, "Name");
    model->setHeaderData(1, Qt::Horizontal, "Salary");
    for (int i = 0; i < tableRow; ++i) {
        for (int j = 0; j < tableColumn; ++j) {
            model->setData(model->index(i, j, QModelIndex()), QVariant((i+1)*(j+1)));
        }
    }

    QTableView *view = new QTableView(this);
    view->move(20, 20);
    view->setModel(model);
//    view->hideColumn(0);
    view->show();
}

Widget::~Widget()
{
    delete ui;
}
