#-------------------------------------------------
#
# Project created by QtCreator 2017-06-23T19:24:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Trunfo_Interface
TEMPLATE = app


SOURCES += main.cpp\
        trunfoui.cpp \
    card.cpp \
    welcome.cpp

HEADERS  += trunfoui.h \
    card.h \
    welcome.h

FORMS    += trunfoui.ui \
    welcome.ui

RESOURCES += \
    cards.qrc
