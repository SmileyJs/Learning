#include "dialog.h"
#include "ui_dialog.h"

const static double Pi = 3.1416;

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

void Dialog::on_pushButton_calculate_clicked()
{
    int radius = ui->lineEdit_radius->text().toInt();
    double square = Pi * radius * radius;
    QString tmp;
    ui->label_showSquare->setText(tmp.setNum(square));
}
