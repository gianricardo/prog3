
#include <QApplication>

#include "InterfaceGrafica/mainwindow.h"
#include "base/jogo_21.h"
#include "base/regra_21.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.show();
    Regra21 *rules = new Regra21();
    BlackJack game(rules, w.novo_jogo());
    game.play(w);
    a.quit();
    return 0;

}
