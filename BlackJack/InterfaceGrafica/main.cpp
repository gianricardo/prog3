#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.novo_jogo();
    w.aposta();
    w.boas_vindas();
    w.naposta();
    w.jogue();
    w.vez_dealer();
    w.continuar();
    w.continuar();
    w.vencedor(true, 10, 100);
    w.vencedor(false, 10, 90);
    w.placar_rodada(100,200);
    return a.exec();

}
