#include "dialog.h"
#include "ui_dialog.h"
#include "QDebug"

#include <QRegExp>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->button_ok, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->button_cancle, SIGNAL(clicked()), this, SLOT(reject()));

    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));
}

Dialog::~Dialog()
{
    delete ui;
}

void
Dialog::on_lineEdit_textChanged()
{
    qDebug() << "Dialog::on_lineEdit_changed";
    ui->button_ok->setEnabled(ui->lineEdit->hasAcceptableInput());
}
