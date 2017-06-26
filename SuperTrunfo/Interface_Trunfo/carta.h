#ifndef CARTA_H
#define CARTA_H

#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class Carta : public QGraphicsItem
{
public:
    Carta(unsigned int val=1);


    QRectF boundingRect() const;

    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget);

protected:
    // overriding mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    bool clicked;
    QPixmap verso;
    QPixmap frente;

};

#endif // CARTA_H
