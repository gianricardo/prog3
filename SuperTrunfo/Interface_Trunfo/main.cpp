#include "trunfoui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TrunfoUI w;
    w.show();

    return a.exec();
}
