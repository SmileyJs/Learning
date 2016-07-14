#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_lineEdit_textChanged();
    void on_button_ok_clicked();
    void on_button_cancle_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
