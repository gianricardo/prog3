#include "card.h"

Card::Card(int ind)
{
    _width = 250;
    _height = (int)(_width * 1.53);

    index = ind + 1;
    shown = false;
    front.load(img_address[index]);
    back.load(img_address[0]);
    front = front.scaled(width(), height());
    back = back.scaled(width(),height());
}

QRectF Card::boundingRect() const
{
    return QRectF(x(),y(),_width,_height);
}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(shown)   painter->drawPixmap(x(), y(), front);
    else        painter->drawPixmap(x(), y(), back);
}

void Card::setShown(bool state)
{
    shown = state;
    this->update();
}

void Card::switchShown()
{
    shown = !shown;
    this->update();
}

void Card::change_card(int ind)
{
    index = ind + 1;
    front.load(img_address[index]);
    front = front.scaled(width(), height());
    update();
}

int Card::width()
{
    return _width;
}

int Card::height()
{
    return _height;
}
