#-------------------------------------------------
#
# Project created by QtCreator 2017-06-21T12:02:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = interfacegrafica
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
        campeao.cpp \
    janela.cpp \
    ../campeao_jogo.cpp \
    ../campeao_regra.cpp \
    ../build-interfacegrafica-Desktop_Qt_5_8_0_GCC_64bit-Debug/moc_campeao.cpp \
    ../build-interfacegrafica-Desktop_Qt_5_8_0_GCC_64bit-Debug/moc_janela.cpp \
    ../cartaimagem.cpp \
    ../imagem.cpp \
    ../window.cpp \
    ../../carteado/src/p3/baralho.cpp \
    ../../carteado/src/p3/carta.cpp \
    ../../carteado/src/p3/jogador.cpp \
    ../../carteado/src/p3/jogo.cpp \
    ../../carteado/src/p3/mesa.cpp \
    ../../carteado/src/p3/regra.cpp \
    carta_campea.cpp

HEADERS  += campeao.h \
    janela.h \
    ../campeao_regra.h \
    ../campeao_jogo.h \
    ../build-interfacegrafica-Desktop_Qt_5_8_0_GCC_64bit-Debug/moc_predefs.h \
    ../build-interfacegrafica-Desktop_Qt_5_8_0_GCC_64bit-Debug/ui_campeao.h \
    ../build-interfacegrafica-Desktop_Qt_5_8_0_GCC_64bit-Debug/ui_janela.h \
    ../cartaimagem.h \
    ../imagem.h \
    ../window.h \
    ../../carteado/src/p3/baralho.h \
    ../../carteado/src/p3/carta.h \
    ../../carteado/src/p3/jogador.h \
    ../../carteado/src/p3/jogo.h \
    ../../carteado/src/p3/mesa.h \
    ../../carteado/src/p3/regra.h \
    carta_campea.h

FORMS    += campeao.ui \
    janela.ui

RESOURCES += \
    imagens.qrc \
    ../cartas_fontes/imagens.qrc

DISTFILES += \
    ../../../../Imagens/quero.png
