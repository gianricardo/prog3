#-------------------------------------------------
#
# Project created by QtCreator 2017-06-28T01:01:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Interface
TEMPLATE = app
INCLUDEPATH += ../../carteado/src/p3

SOURCES += main.cpp\
        mainwindow.cpp \
    ../Paciencia/estadojogo.cpp \
    ../Paciencia/paciencia.cpp \
    ../Paciencia/r_paciencia.cpp \
    ../Paciencia/tela.cpp \
    ../../carteado/src/p3/baralho.cpp \
    ../../carteado/src/p3/carta.cpp \
    ../../carteado/src/p3/jogador.cpp \
    ../../carteado/src/p3/jogo.cpp \
    ../../carteado/src/p3/mesa.cpp \
    ../../carteado/src/p3/regra.cpp \
    caixa.cpp

HEADERS  += mainwindow.h \
    ../Paciencia/estadojogo.h \
    ../Paciencia/paciencia.h \
    ../Paciencia/r_paciencia.h \
    ../Paciencia/tela.h \
    ../../carteado/src/p3/baralho.h \
    ../../carteado/src/p3/carta.h \
    ../../carteado/src/p3/jogador.h \
    ../../carteado/src/p3/jogo.h \
    ../../carteado/src/p3/mesa.h \
    ../../carteado/src/p3/regra.h \
    caixa.h

FORMS    += mainwindow.ui \
    caixa.ui

RESOURCES += baralho.qrc

DISTFILES += \
    ../Paciencia/Debug/objects.mk \
    ../Paciencia/Debug/sources.mk \
    ../Paciencia/Debug/subdir.mk \
    baralho/back.jpg \
    baralho/backx.jpg \
    baralho/01.png \
    baralho/010.png \
    baralho/011.png \
    baralho/012.png \
    baralho/013.png \
    baralho/02.png \
    baralho/03.png \
    baralho/04.png \
    baralho/05.png \
    baralho/06.png \
    baralho/07.png \
    baralho/08.png \
    baralho/09.png \
    baralho/11.png \
    baralho/110.png \
    baralho/111.png \
    baralho/112.png \
    baralho/113.png \
    baralho/12.png \
    baralho/13.png \
    baralho/14.png \
    baralho/15.png \
    baralho/16.png \
    baralho/17.png \
    baralho/18.png \
    baralho/19.png \
    baralho/21.png \
    baralho/210.png \
    baralho/211.png \
    baralho/212.png \
    baralho/213.png \
    baralho/22.png \
    baralho/23.png \
    baralho/24.png \
    baralho/25.png \
    baralho/26.png \
    baralho/27.png \
    baralho/28.png \
    baralho/29.png \
    baralho/31.png \
    baralho/310.png \
    baralho/311.png \
    baralho/312.png \
    baralho/313.png \
    baralho/32.png \
    baralho/33.png \
    baralho/34.png \
    baralho/35.png \
    baralho/36.png \
    baralho/37.png \
    baralho/38.png \
    baralho/39.png \
    ../../carteado/Debug/src/p3/baralho.d \
    ../../carteado/Debug/src/p3/carta.d \
    ../../carteado/Debug/src/p3/jogador.d \
    ../../carteado/Debug/src/p3/jogo.d \
    ../../carteado/Debug/src/p3/mesa.d \
    ../../carteado/Debug/src/p3/regra.d \
    ../../carteado/Debug/src/p3/subdir.mk \
    ../../carteado/Debug/objects.mk \
    ../../carteado/Debug/sources.mk
