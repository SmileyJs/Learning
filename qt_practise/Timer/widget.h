#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class QTimer;
class QLabel;
class QPushButton;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void onStartButtonClicked();
    void onEndButtonClicked();
    void onTimerTimeOut();

private:
    Ui::Widget *ui;
    QTimer *timer;
    QLabel *text;
    QPushButton *startButton;
    QPushButton *endButton;
};

#endif // WIDGET_H
