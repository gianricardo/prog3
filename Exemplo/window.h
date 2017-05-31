
#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>

#include "jogo.h"
#include "cartaimagem.h"


class Window : public QWidget {
    
    Q_OBJECT

public:

    explicit Window(QWidget *parent = nullptr) ;
        
    
private:
    
    p3::CartaImagem *img;
    p3::CartaImagem *ims[5];

};

#endif
