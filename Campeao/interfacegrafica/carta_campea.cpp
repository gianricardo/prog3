#include "carta_campea.h"
#include <iostream>

Carta_campea::Carta_campea(int numero, int naipe)
{
    //imagem.load(":/cartas/cartasimg/back.jpg");
    std::string nome = ":/cartasimg/";
    nome += ('0' + numero/10);
    nome += ('0' + numero%10);
    nome += ('0' + naipe);
    nome += ".jpg";
    std::cout << carta_imagem.load(QString::fromStdString(nome));
    carta_imagem=carta_imagem.scaled(171,247);
    setFlag( QGraphicsItem::ItemIsFocusable );
    setPos(0,0);

    std::cout << nome <<"\n";
}


QRectF Carta_campea::boundingRect() const
{
    return QRectF(x(),y(),171,247);
}


void Carta_campea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(x(),y(),carta_imagem);

}

