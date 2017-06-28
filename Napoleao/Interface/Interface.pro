#-------------------------------------------------
#
# Project created by QtCreator 2017-06-22T20:05:42
#
#-------------------------------------------------

QT       += core gui

VERSION = 5.6.1
TARGET = Interface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    escreve_nome.cpp \
    escreve_nome_adversario.cpp \
    ../tela.cpp \
    ../jogadornapoleao.cpp \
    ../napoleao.cpp \
    ../napoleaoia.cpp \
    ../napoleaopessoa.cpp \
    ../../carteado/src/p3/baralho.cpp \
    ../../carteado/src/p3/carta.cpp \
    ../../carteado/src/p3/jogador.cpp \
    ../../carteado/src/p3/jogo.cpp \
    ../../carteado/src/p3/mesa.cpp \
    ../../carteado/src/p3/regra.cpp \
    escreve_rodadas.cpp \
    clickablelabel.cpp \
    fim_rodada.cpp \
    fim_de_jogo.cpp

HEADERS  += mainwindow.h \
    escreve_nome.h \
    escreve_nome_adversario.h \
    ../tela.h \
    ../jogadornapoleao.h \
    ../napoleao.h \
    ../napoleaoia.h \
    ../napoleaopessoa.h \
    ../../carteado/src/p3/baralho.h \
    ../../carteado/src/p3/carta.h \
    ../../carteado/src/p3/jogador.h \
    ../../carteado/src/p3/jogo.h \
    ../../carteado/src/p3/mesa.h \
    ../../carteado/src/p3/regra.h \
    escreve_rodadas.h \
    clickablelabel.h \
    fim_rodada.h \
    fim_de_jogo.h

FORMS    += mainwindow.ui \
    escreve_nome.ui \
    escreve_nome_adversario.ui \
    escreve_rodadas.ui \
    fim_rodada.ui \
    fim_de_jogo.ui

RESOURCES += \
    baralho.qrc

