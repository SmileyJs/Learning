#-------------------------------------------------
#
# Project created by QtCreator 2016-07-18T17:38:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chapter03_userInfo
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    baseinfo.cpp \
    detail.cpp \
    contact.cpp

HEADERS  += dialog.h \
    baseinfo.h \
    detail.h \
    contact.h

DISTFILES +=

RESOURCES += \
    resource.qrc
