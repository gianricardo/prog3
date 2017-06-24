#include "imgcarta.h"

ImgCarta::ImgCarta(unsigned int val,unsigned int naipe,bool jogavel, int x, int y)
{
    value=val;
    clicked=!jogavel;
    verso.load(":/rec/cartas/tras-baralho.jpg");
    switch(val){
    case 12:
        switch(naipe){
        case 0:
            frente.load(":/rec/cartas/A_espadas.png");
            break;
        case 1:
            frente.load(":/rec/cartas/A_copas.png");
            break;
        case 2:
            frente.load(":/rec/cartas/A_paus.png");
            break;
        case 3:
            frente.load(":/rec/cartas/A_ouros.png");
            break;
        }
        break;
    case 13:
        switch(naipe){
        case 0:
            frente.load(":/rec/cartas/2_espadas.png");
            break;
        case 1:
            frente.load(":/rec/cartas/2_copas.png");
            break;
        case 2:
            frente.load(":/rec/cartas/2_paus.png");
            break;
        case 3:
            frente.load(":/rec/cartas/2_ouros.png");
            break;
        }
        break;
    case 1:
        switch(naipe){
        case 0:
            frente.load(":/rec/cartas/3_espadas.png");
            break;
        case 1:
            frente.load(":/rec/cartas/3_copas.png");
            break;
        case 2:
            frente.load(":/rec/cartas/3_paus.png");
            break;
        case 3:
            frente.load(":/rec/cartas/3_ouros.png");
            break;
        }
        break;
    case 2:
        switch(naipe){
        case 0:
            frente.load(":/rec/cartas/4_espadas.png");
            break;
        case 1:
            frente.load(":/rec/cartas/4_copas.png");
            break;
        case 2:
            frente.load(":/rec/cartas/4_paus.png");
            break;
        case 3:
            frente.load(":/rec/cartas/4_ouros.png");
            break;
        }
        break;
    case 3:
        switch(naipe){
        case 0:
            frente.load(":/rec/cartas/5_espadas.png");
            break;
        case 1:
            frente.load(":/rec/cartas/5_copas.png");
            break;
        case 2:
            frente.load(":/rec/cartas/5_paus.png");
            break;
        case 3:
            frente.load(":/rec/cartas/5_ouros.png");
            break;
        }
        break;
    case 4:
        switch(naipe){
        case 0:
            frente.load(":/rec/cartas/6_espadas.png");
            break;
        case 1:
            frente.load(":/rec/cartas/6_copas.png");
            break;
        case 2:
            frente.load(":/rec/cartas/6_paus.png");
            break;
        case 3:
            frente.load(":/rec/cartas/6_ouros.png");
            break;
        }
        break;
    case 5:
        switch(naipe){
        case 0:
            frente.load(":/rec/cartas/7_espadas.png");
            break;
        case 1:
            frente.load(":/rec/cartas/7_copas.png");
            break;
        case 2:
            frente.load(":/rec/cartas/7_paus.png");
            break;
        case 3:
            frente.load(":/rec/cartas/7_ouros.png");
            break;
        }
        break;
    case 6:
        switch(naipe){
        case 0:
            frente.load(":/rec/cartas/8_espadas.png");
            break;
        case 1:
            frente.load(":/rec/cartas/8_copas.png");
            break;
        case 2:
            frente.load(":/rec/cartas/8_paus.png");
            break;
        case 3:
            frente.load(":/rec/cartas/8_ouros.png");
            break;
        }
        break;
    case 7:
        switch(naipe){
        case 0:
            frente.load(":/rec/cartas/9_espadas.png");
            break;
        case 1:
            frente.load(":/rec/cartas/9_copas.png");
            break;
        case 2:
            frente.load(":/rec/cartas/9_paus.png");
            break;
        case 3:
            frente.load(":/rec/cartas/9_ouros.png");
            break;
        }
        break;
    case 8:
        switch(naipe){
        case 0:
            frente.load(":/rec/cartas/10_espadas.png");
            break;
        case 1:
            frente.load(":/rec/cartas/10_copas.png");
            break;
        case 2:
            frente.load(":/rec/cartas/10_paus.png");
            break;
        case 3:
            frente.load(":/rec/cartas/10_ouros.png");
            break;
        }
        break;
    case 9:
        switch(naipe){
        case 0:
            frente.load(":/rec/cartas/J_espadas.png");
            break;
        case 1:
            frente.load(":/rec/cartas/J_copas.png");
            break;
        case 2:
            frente.load(":/rec/cartas/J_paus.png");
            break;
        case 3:
            frente.load(":/rec/cartas/J_ouros.png");
            break;
        }
        break;
    case 10:
        switch(naipe){
        case 0:
            frente.load(":/rec/cartas/Q_espadas.png");
            break;
        case 1:
            frente.load(":/rec/cartas/Q_copas.png");
            break;
        case 2:
            frente.load(":/rec/cartas/Q_paus.png");
            break;
        case 3:
            frente.load(":/rec/cartas/Q_ouros.png");
            break;
        }
        break;
    case 11:
        switch(naipe){
        case 0:
            frente.load(":/rec/cartas/K_espadas.png");
            break;
        case 1:
            frente.load(":/rec/cartas/K_copas.png");
            break;
        case 2:
            frente.load(":/rec/cartas/K_paus.png");
            break;
        case 3:
            frente.load(":/rec/cartas/K_ouros.png");
            break;
        }
        break;
    }
    verso = verso.scaled(112,156);
    frente = frente.scaled(112,156);
    setFlag( QGraphicsItem::ItemIsSelectable );
    setPos(x,y);
}

QRectF ImgCarta::boundingRect() const
{
    return QRectF(x(),y(),112,156);
}

void ImgCarta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(clicked){
        painter->drawPixmap(x(),y(),verso);
    }else{
        painter->drawPixmap(x(),y(),frente);
    }
}
