#-------------------------------------------------
#
# Project created by QtCreator 2017-06-23T19:36:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BlackJack
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
    base/banco_21.cpp \
    base/ia_dealer_21.cpp \
    base/interface_21.cpp \
    base/jogo_21.cpp \
    base/regra_21.cpp \
    InterfaceGrafica/bemvindo.cpp \
    InterfaceGrafica/continua.cpp \
    InterfaceGrafica/dealer.cpp \
    InterfaceGrafica/imagem_carta.cpp \
    InterfaceGrafica/mainwindow.cpp \
    InterfaceGrafica/n_aposta.cpp \
    InterfaceGrafica/nova_aposta.cpp \
    InterfaceGrafica/novo.cpp \
    InterfaceGrafica/parabens.cpp \
    ../carteado/src/p3/baralho.cpp \
    ../carteado/src/p3/carta.cpp \
    ../carteado/src/p3/jogador.cpp \
    ../carteado/src/p3/jogo.cpp \
    ../carteado/src/p3/mesa.cpp \
    ../carteado/src/p3/regra.cpp \
    main.cpp \
    InterfaceGrafica/obg.cpp

HEADERS  += \
    base/banco_21.h \
    base/ia_dealer_21.h \
    base/interface_21.h \
    base/jogo_21.h \
    base/regra_21.h \
    InterfaceGrafica/bemvindo.h \
    InterfaceGrafica/continua.h \
    InterfaceGrafica/dealer.h \
    InterfaceGrafica/imagem_carta.h \
    InterfaceGrafica/mainwindow.h \
    InterfaceGrafica/n_aposta.h \
    InterfaceGrafica/nova_aposta.h \
    InterfaceGrafica/novo.h \
    InterfaceGrafica/parabens.h \
    ../carteado/src/p3/baralho.h \
    ../carteado/src/p3/carta.h \
    ../carteado/src/p3/jogador.h \
    ../carteado/src/p3/jogo.h \
    ../carteado/src/p3/mesa.h \
    ../carteado/src/p3/regra.h \
    InterfaceGrafica/obg.h

FORMS    += \
    InterfaceGrafica/bemvindo.ui \
    InterfaceGrafica/continua.ui \
    InterfaceGrafica/dealer.ui \
    InterfaceGrafica/mainwindow.ui \
    InterfaceGrafica/n_aposta.ui \
    InterfaceGrafica/nova_aposta.ui \
    InterfaceGrafica/novo.ui \
    InterfaceGrafica/parabens.ui \
    InterfaceGrafica/obg.ui

RESOURCES += \
    InterfaceGrafica/imagens.qrc

DISTFILES += \
    InterfaceGrafica/cartasimg/00.jpg \
    InterfaceGrafica/cartasimg/01.jpg \
    InterfaceGrafica/cartasimg/010.jpg \
    InterfaceGrafica/cartasimg/011.jpg \
    InterfaceGrafica/cartasimg/012.jpg \
    InterfaceGrafica/cartasimg/013.jpg \
    InterfaceGrafica/cartasimg/02.jpg \
    InterfaceGrafica/cartasimg/03.jpg \
    InterfaceGrafica/cartasimg/04.jpg \
    InterfaceGrafica/cartasimg/05.jpg \
    InterfaceGrafica/cartasimg/06.jpg \
    InterfaceGrafica/cartasimg/07.jpg \
    InterfaceGrafica/cartasimg/08.jpg \
    InterfaceGrafica/cartasimg/09.jpg \
    InterfaceGrafica/cartasimg/11.jpg \
    InterfaceGrafica/cartasimg/110.jpg \
    InterfaceGrafica/cartasimg/111.jpg \
    InterfaceGrafica/cartasimg/112.jpg \
    InterfaceGrafica/cartasimg/113.jpg \
    InterfaceGrafica/cartasimg/12.jpg \
    InterfaceGrafica/cartasimg/13.jpg \
    InterfaceGrafica/cartasimg/14.jpg \
    InterfaceGrafica/cartasimg/15.jpg \
    InterfaceGrafica/cartasimg/16.jpg \
    InterfaceGrafica/cartasimg/17.jpg \
    InterfaceGrafica/cartasimg/18.jpg \
    InterfaceGrafica/cartasimg/19.jpg \
    InterfaceGrafica/cartasimg/2.jpg \
    InterfaceGrafica/cartasimg/21.jpg \
    InterfaceGrafica/cartasimg/210.jpg \
    InterfaceGrafica/cartasimg/211.jpg \
    InterfaceGrafica/cartasimg/212.jpg \
    InterfaceGrafica/cartasimg/213.jpg \
    InterfaceGrafica/cartasimg/22.jpg \
    InterfaceGrafica/cartasimg/23.jpg \
    InterfaceGrafica/cartasimg/24.jpg \
    InterfaceGrafica/cartasimg/25.jpg \
    InterfaceGrafica/cartasimg/26.jpg \
    InterfaceGrafica/cartasimg/27.jpg \
    InterfaceGrafica/cartasimg/28.jpg \
    InterfaceGrafica/cartasimg/29.jpg \
    InterfaceGrafica/cartasimg/31.jpg \
    InterfaceGrafica/cartasimg/310.jpg \
    InterfaceGrafica/cartasimg/311.jpg \
    InterfaceGrafica/cartasimg/312.jpg \
    InterfaceGrafica/cartasimg/313.jpg \
    InterfaceGrafica/cartasimg/32.jpg \
    InterfaceGrafica/cartasimg/33.jpg \
    InterfaceGrafica/cartasimg/34.jpg \
    InterfaceGrafica/cartasimg/35.jpg \
    InterfaceGrafica/cartasimg/36.jpg \
    InterfaceGrafica/cartasimg/37.jpg \
    InterfaceGrafica/cartasimg/38.jpg \
    InterfaceGrafica/cartasimg/39.jpg \
    InterfaceGrafica/cartasimg/90.jpg \
    InterfaceGrafica/cartasimg/91.jpg \
    InterfaceGrafica/ohterimg/dealer.png \
    InterfaceGrafica/cartasimg/base.psd

run.depends = $$TARGET
run.commands = ./$$TARGET

QMAKE_EXTRA_TARGETS = run
