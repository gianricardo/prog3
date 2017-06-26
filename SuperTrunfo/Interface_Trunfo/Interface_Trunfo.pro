#-------------------------------------------------
#
# Project created by QtCreator 2017-06-26T15:01:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Interface_Trunfo
TEMPLATE = app


SOURCES += main.cpp\
        trunfoui.cpp \
    card.cpp \
    quitdialog.cpp \
    instructions.cpp

HEADERS  += trunfoui.h \
    card.h \
    quitdialog.h \
    instructions.h

FORMS    += trunfoui.ui \
    quitdialog.ui \
    instructions.ui

RESOURCES += \
    card.qrc
