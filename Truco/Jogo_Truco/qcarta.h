#ifndef CARTA_H
#define CARTA_H

#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsEffect>
#include "../../carteado/src/p3/carta.h"



class QCarta : public QGraphicsItem
{
public:
    QCarta(p3::Carta c1);

    QRectF boundingRect() const;

    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget);

    void setClickable();
    bool getClickable();
    void setSelectable();
    bool getSelectable();
    void setSelected(bool status);
    bool getSelected();
    bool getClicked();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    bool clicked;
    bool selected;
    bool clickable;
    bool selectable;
    QPixmap verso;
    QPixmap frente;
};

#endif // CARTA_H
