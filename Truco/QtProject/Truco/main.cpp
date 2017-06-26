#include "mainwindow.h"
#include <QApplication>
#include "../../Truco/jogo_truco.h"
#include "../../Truco/regratruco.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();


    return a.exec();
}
