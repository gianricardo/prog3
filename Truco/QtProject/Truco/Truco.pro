#-------------------------------------------------
#
# Project created by QtCreator 2017-06-21T09:35:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Truco
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    name.cpp \
    help.cpp \
    jogo2.cpp \
    qcarta.cpp \
    qjogo.cpp \
    ../../regratruco.cpp \
    ../../jogo_truco.cpp \
    getacao.cpp

HEADERS  += mainwindow.h \
    name.h \
    help.h \
    jogo2.h \
    qcarta.h \
    qjogo.h \
    ../../regratruco.h \
    ../../jogo_truco.h \
    getacao.h

FORMS    += mainwindow.ui \
    name.ui \
    jogo.ui \
    help.ui \
    jogo2.ui \
    getacao.ui

RESOURCES += \
    myresources.qrc


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../carteado/Lib/release/ -lcarteado
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../carteado/Lib/debug/ -lcarteado
else:unix: LIBS += -L$$PWD/../../../carteado/Lib/ -lcarteado

INCLUDEPATH += $$PWD/../../../carteado/Lib
DEPENDPATH += $$PWD/../../../carteado/Lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../carteado/Lib/release/libcarteado.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../carteado/Lib/debug/libcarteado.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../carteado/Lib/release/carteado.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../carteado/Lib/debug/carteado.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../carteado/Lib/libcarteado.a
