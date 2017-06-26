#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QString>
#include <QGraphicsItem>

class Card : public QGraphicsItem
{
public:
    Card(int ind);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);

private:
    int index;
    QPixmap front;
    QPixmap back;
    bool shown;

    QString img_address [33] =
    {
        ":/Cartas/Cartas/back_card.png",
        ":/Cartas/Cartas/trunfo_1c.jpg",
        ":/Cartas/Cartas/trunfo_1a.jpg"
    };
};

#endif // CARD_H
