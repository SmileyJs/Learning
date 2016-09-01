#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFrame>
#include "baseinfo.h"
#include "contact.h"
#include "detail.h"

class Dialog : public QFrame
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:

};

#endif // DIALOG_H
