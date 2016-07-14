#include "dialog.h"
#include "ui_dialog.h"
#include "QDebug"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void
Dialog::on_lineEdit_textChanged()
{
    qDebug() << "Dialog::on_lineEdit_changed";

}

void
Dialog::on_button_ok_clicked()
{
    qDebug() << "Dialog::on_button_ok_clicked";
}

void
Dialog::on_button_cancle_clicked()
{
    qDebug() << "Dialog::on_button_cancle_clicked";
}
