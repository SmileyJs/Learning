 #include "splitter.h"
#include <QApplication>

#include <QSplitter>
#include <QTextEdit>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Splitter w;
//    w.show();

//    w.setMaximumSize(400, 300);
//    w.setMinimumSize(200, 100);

    QFont font("ZYSong18030", 12);
    a.setFont(font);

    QSplitter *splitterMain = new QSplitter(Qt::Horizontal);
    QTextEdit *textEditLeft = new QTextEdit("left text edit", splitterMain);
    textEditLeft->setAlignment(Qt::AlignCenter);

    QSplitter *splitterRight = new QSplitter(Qt::Vertical, splitterMain);
    QTextEdit *textTop = new QTextEdit("top text edit", splitterRight);
    textTop->setAlignment(Qt::AlignRight);

    QTextEdit *textBottom = new QTextEdit("bottom text edit", splitterRight);
    textBottom->setAlignment(Qt::AlignLeft);

    splitterRight->setOpaqueResize(false);
    splitterMain->setStretchFactor(0, 1);
//    splitterMain->setStretchFactor(1, 1);

    splitterMain->setWindowTitle("Splitter");
    splitterMain->show();

    return a.exec();
}
