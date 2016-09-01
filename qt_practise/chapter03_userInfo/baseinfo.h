#ifndef BASEINFO_H
#define BASEINFO_H

#include <QWidget>

class QLabel;
class QTextEdit;
class QComboBox;
class QGridLayout;
class QVBoxLayout;
class QHBoxLayout;
class QPushButton;

class BaseInfo : public QWidget
{
    Q_OBJECT
public:
    explicit BaseInfo(QWidget *parent = 0);

signals:

public slots:

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
    QHBoxLayout *topRightLayout;
    QPushButton *okButton;
    QPushButton *cancleButton;
    QHBoxLayout *bottomLayout;
    QGridLayout *mainLayout;
};

#endif // BASEINFO_H
