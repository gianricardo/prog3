#-------------------------------------------------
#
# Project created by QtCreator 2017-06-26T15:01:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Interface_Trunfo
TEMPLATE = app


SOURCES +=\
        trunfoui.cpp \
    card.cpp \
    quitdialog.cpp \
    instructions.cpp \
    ../src/trunfo.cpp \
    ../src/jogotrunfo.cpp \
    ../src/jogada.cpp \
    ../src/cartatrunfo.cpp \
    ../src/inteligenciaartificial.cpp \
    namesdialog.cpp \
    timer.cpp

HEADERS  += trunfoui.h \
    card.h \
    quitdialog.h \
    instructions.h \
    ../src/jogotrunfo.h \
    ../src/jogada.h \
    ../src/inteligenciaartificial.h \
    ../src/cartatrunfo.h \
    namesdialog.h \
    timer.h

FORMS    += trunfoui.ui \
    quitdialog.ui \
    instructions.ui \
    backdialog.ui \
    namesdialog.ui

RESOURCES += \
    card.qrc

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
