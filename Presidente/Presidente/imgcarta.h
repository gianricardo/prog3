#ifndef IMGCARTA_H
#define IMGCARTA_H

#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include "../../carteado/src/p3/carta.h"

class ImgCarta : public QGraphicsItem
{
public:
    ImgCarta(unsigned int val, unsigned int naipe, bool jogavel, int x, int y);

    QRectF boundingRect() const;

    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget);

protected:


private:
    unsigned int value;
    bool clicked;
    QPixmap verso;
    QPixmap frente;
};

#endif // IMGCARTA_H
