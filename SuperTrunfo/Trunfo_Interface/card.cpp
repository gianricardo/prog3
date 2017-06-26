#include "card.h"

Card::Card(int ind)
{
    index = ind;
    shown = true;
    front.load(img_address[index]);
    back.load(img_address[0]);
}

QRectF Card::boundingRect() const
{
    return QRectF(x(),y(),200,307);
}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(shown)   painter->drawPixmap(boundingRect().x(),boundingRect().y(), boundingRect().width(),
                                    boundingRect().height(), front);
    else        painter->drawPixmap(boundingRect().x(),boundingRect().y(), boundingRect().width(),
                                    boundingRect().height(), back);
}

int Card::width()
{
    return boundingRect().width();
}

int Card::height()
{
    return boundingRect().height();
}
