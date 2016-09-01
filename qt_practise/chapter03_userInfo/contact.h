#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>

class QLabel;
class QTextEdit;

class Contact : public QWidget
{
    Q_OBJECT
public:
    explicit Contact(QWidget *parent = 0);

signals:

public slots:

private:
    void initContactInfo();

    // variables
    QLabel *email;
    QTextEdit *emailEdit;
    QLabel *address;
    QTextEdit *addressEdit;
    QLabel *postCode;
    QTextEdit *postCodeEdit;
    QLabel *mobilePhone;
    QTextEdit *mobilePhoneEdit;
    QLabel *telePhone;
    QTextEdit *telePhoneEdit;
};

#endif // CONTACT_H
