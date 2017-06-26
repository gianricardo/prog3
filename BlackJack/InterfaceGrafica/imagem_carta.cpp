#include "imagem_carta.h"

imagem_carta::imagem_carta(int naipe, int numero)
{
    //imagem.load(":/cartas/cartasimg/back.jpg");
    QString nome = ":/cartas/cartasimg/";
    nome.append(QStringLiteral("%1%2").arg(naipe).arg(numero));
    nome.append(".jpg");
    imagem.load(nome);
    imagem=imagem.scaled(190,275);
    setFlag( QGraphicsItem::ItemIsFocusable );
    setPos(0,0);

}

void imagem_carta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(x(),y(),imagem);

}

QRectF imagem_carta::boundingRect() const
{
    return QRectF(x(),y(),150,225);
}
