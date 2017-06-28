#include "campeao.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Campeao w;
    w.show();
   // qApp->setStyleSheet("QWidget {background-image: url(./image.png) }");
   // QWidget {background-image: url(./image.png) }
    return a.exec();
}
