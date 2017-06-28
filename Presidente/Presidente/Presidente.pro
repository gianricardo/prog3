#-------------------------------------------------
#
# Project created by QtCreator 2017-06-24T01:05:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Presidente
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        telapresidente.cpp \
    imgcarta.cpp \
    ../../carteado/src/p3/carta.cpp \
    ../src/jogopresidente.cpp \
    ../../carteado/src/p3/regra.cpp \
    ../../carteado/src/p3/mesa.cpp \
    ../../carteado/src/p3/jogo.cpp \
    ../../carteado/src/p3/jogador.cpp \
    ../../carteado/src/p3/baralho.cpp \
    winnerwindow.cpp \
    rounds.cpp

HEADERS += \
        telapresidente.h \
    imgcarta.h \
    winnerwindow.h \
    rounds.h

FORMS += \
        telapresidente.ui \
    winnerwindow.ui \
    rounds.ui

RESOURCES += \
    resource.qrc
