#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QLabel;
class QTextEdit;
class QComboBox;
class QGridLayout;
class QVBoxLayout;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    void initUserInfo();

    // variables
    QLabel *userName;
    QTextEdit *userNameEdit;
    QLabel *name;
    QTextEdit *nameEdit;
    QLabel *sex;
    QComboBox *sexBox;
    QLabel *department;
    QTextEdit *departmentEdit;
    QLabel *age;
    QTextEdit *ageEdit;
    QLabel *remark;
    QGridLayout *leftLayout;
    QLabel *head;
    QLabel *headIcon;
    QPushButton *updateButton;
    QLabel *description;
    QTextEdit *descriptionEdit;
    QVBoxLayout *rightLayout;
    QGridLayout *mainLayout;
};

#endif // DIALOG_H
