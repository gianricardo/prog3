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

    int width();
    int height();

private:
    int _width;
    int _height;
    int index;
    QPixmap front;
    QPixmap back;
    bool shown;

    QString img_address [33] =
    {
        ":/new/back_card.png",
        ":/new/trunfo_1c.jpg",
        ":/new/trunfo_1a.jpg"
    };
};

#endif // CARD_H
