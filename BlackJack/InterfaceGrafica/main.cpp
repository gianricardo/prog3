#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.show();
    w.novo_jogo();

    w.mostra_maos(/*std::vector<p3::Carta> d, std::vector<p3::Carta> p*/);
    return 0;

}
