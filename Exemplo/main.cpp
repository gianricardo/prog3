
#include <QApplication>
#include "window.h"

int main(int argc, char **argv){
    
    QApplication app(argc, argv);
    
    Window window;
    
    window.setFixedSize(500, 500);

    window.show();

    return app.exec();
    
}
