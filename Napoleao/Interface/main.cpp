#include "../tela.h"
#include "mainwindow.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Tela tela;
    tela.define(&w);
    w.set_tela(&tela);
    return a.exec();
}
