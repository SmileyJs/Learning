// System header.
#include <iostream>

#include <QFile>
#include <QTextStream>
#include <QTextEdit>

#include "textfinder.h"
#include "ui_textfinder.h"

using std::cout;
using std::cin;
using std::endl;

#define debug(out) cout << out << endl;

TextFinder::TextFinder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    loadFile();
}

TextFinder::~TextFinder()
{
    delete ui;
}

void
TextFinder::on_pushButton_clicked()
{
    debug("TextFinder::on_pushButton_clicked");

    QString searchText = ui->lineEdit->text();
    ui->textEdit->find(searchText, QTextDocument::FindWholeWords);
}

void
TextFinder::loadFile()
{
    debug("TextFinder::loadFile");

    QFile input(":/input.txt");
    input.open(QIODevice::ReadOnly);

    QTextStream in(&input);
    QString string = in.readAll();
    input.close();

    ui->textEdit->setPlainText(string);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}
