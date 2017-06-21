#-------------------------------------------------
#
# Project created by QtCreator 2017-06-17T19:31:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InterfaceGrafica
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


SOURCES += main.cpp\
    ../banco_21.cpp \
    ../ia_dealer_21.cpp \
    ../interface_21.cpp \
    ../jogo_21.cpp \
    ../regra_21.cpp \
    ../../carteado/src/p3/baralho.cpp \
    ../../carteado/src/p3/carta.cpp \
    ../../carteado/src/p3/jogador.cpp \
    ../../carteado/src/p3/jogo.cpp \
    ../../carteado/src/p3/mesa.cpp \
    ../../carteado/src/p3/regra.cpp \
    mainwindow.cpp \
    nova_aposta.cpp \
    novo.cpp \
    bemvindo.cpp \
    n_aposta.cpp \
    dealer.cpp \
    continua.cpp \
    parabens.cpp

HEADERS  += \
    ../banco_21.h \
    ../ia_dealer_21.h \
    ../interface_21.h \
    ../jogo_21.h \
    ../regra_21.h \
    ../../carteado/src/p3/baralho.h \
    ../../carteado/src/p3/carta.h \
    ../../carteado/src/p3/jogador.h \
    ../../carteado/src/p3/jogo.h \
    ../../carteado/src/p3/mesa.h \
    ../../carteado/src/p3/regra.h \
    mainwindow.h \
    nova_aposta.h \
    novo.h \
    bemvindo.h \
    n_aposta.h \
    dealer.h \
    continua.h \
    parabens.h

FORMS    += \
    mainwindow.ui \
    nova_aposta.ui \
    novo.ui \
    bemvindo.ui \
    n_aposta.ui \
    dealer.ui \
    continua.ui \
    parabens.ui

RESOURCES +=
