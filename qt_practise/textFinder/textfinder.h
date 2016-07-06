#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QWidget>

namespace Ui {
class TextFinder;
}

class TextFinder : public QWidget
{
    Q_OBJECT

public:
    explicit TextFinder(QWidget *parent = 0);
    ~TextFinder();

//    QMetaObject::connectSlotsByName(TextFinder);

private slots:
    void on_pushButton_clicked();

private:
    Ui::TextFinder *ui;
    void loadFile();
};

#endif // TEXTFINDER_H
