#include "widget.h"
#include "ui_widget.h"

#include <QLabel>
#include <QTimer>
#include <QPushButton>
#include <QDebug>
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , timer(NULL)
    , text(NULL)
    , startButton(NULL)
    , endButton(NULL)
{
    ui->setupUi(this);

    text = new QLabel(this);
    text->setText("Timer");

    startButton = new QPushButton(this);
    startButton->setText("Start timer");
    connect(startButton, SIGNAL(clicked(bool)), this, SLOT(onStartButtonClicked()));

    endButton = new QPushButton(this);
    endButton->setText("End timer");
    connect(endButton, SIGNAL(clicked(bool)), this, SLOT(onEndButtonClicked()));

    timer = new QTimer();
    timer->setInterval(5000);
    timer->setSingleShot(true);

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTimeOut()));

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(text, 0, 0);
    mainLayout->addWidget(startButton, 1, 0);
    mainLayout->addWidget(endButton, 1, 1);
    setLayout(mainLayout);
}

Widget::~Widget()
{
    delete timer;
    delete text;
    delete startButton;
    delete endButton;
    delete ui;
}

void
Widget::onStartButtonClicked()
{
    qDebug("onStartButtonClicked");

    timer->start();
}

void
Widget::onEndButtonClicked()
{
    qDebug("onEndButtonClicked");

    timer->stop();
}

void
Widget::onTimerTimeOut()
{
    qDebug("onTimerTimeOut");

    QFont ft;
    ft.setPointSize(text->font().pointSize() + 5);
    text->setFont(ft);
}
