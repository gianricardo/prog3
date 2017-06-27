
#include <QApplication>

#include "window.h"

int main(int argc, char **argv){

    QApplication a(argc, argv);

    GameWindow g;
    g.show();

    return a.exec();
}
