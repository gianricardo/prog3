#include "mainwindow.h"
#include "caixa.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Caixa c;

    w.show();

    c.show();

    w.jogador(c.nome());

    w.list_botton();

    w.atualiza_jogo();

    return a.exec();
}
