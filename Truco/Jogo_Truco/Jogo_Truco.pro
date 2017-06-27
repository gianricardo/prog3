#-------------------------------------------------
#
# Project created by QtCreator 2017-06-27T13:23:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Jogo_Truco
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../jogo_truco.cpp \
    ../regratruco.cpp \
    getacao.cpp \
    help.cpp \
    jogo2.cpp \
    name.cpp \
    qcarta.cpp \
    qjogo.cpp

HEADERS  += mainwindow.h \
    ../jogo_truco.h \
    ../regratruco.h \
    getacao.h \
    help.h \
    jogo2.h \
    name.h \
    qcarta.h \
    qjogo.h

FORMS    += mainwindow.ui \
    getacao.ui \
    getcarta.ui \
    help.ui \
    jogo.ui \
    jogo2.ui \
    name.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../carteado/Lib/release/ -lcarteado
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../carteado/Lib/debug/ -lcarteado
else:unix: LIBS += -L$$PWD/../../carteado/Lib/ -lcarteado

INCLUDEPATH += $$PWD/../../carteado/Lib
DEPENDPATH += $$PWD/../../carteado/Lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../carteado/Lib/release/libcarteado.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../carteado/Lib/debug/libcarteado.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../carteado/Lib/release/carteado.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../carteado/Lib/debug/carteado.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../carteado/Lib/libcarteado.a

RESOURCES += \
    myresources.qrc
