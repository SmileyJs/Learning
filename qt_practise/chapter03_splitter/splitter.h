#ifndef SPLITTER_H
#define SPLITTER_H

#include <QMainWindow>

class Splitter : public QMainWindow
{
    Q_OBJECT

public:
    Splitter(QWidget *parent = 0);
    ~Splitter();
};

#endif // SPLITTER_H
