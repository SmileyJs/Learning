#-------------------------------------------------
#
# Project created by QtCreator 2016-07-13T10:52:17
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chapter02_widget
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    treewidget.cpp

HEADERS  += widget.h \
    treewidget.h

FORMS    += widget.ui \
    treewidget.ui
