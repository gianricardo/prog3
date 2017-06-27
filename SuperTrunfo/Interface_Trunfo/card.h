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

    void setShown(bool state);
    void switchShown();
    void change_card(int ind);
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
        ":/new/card_back.png",

        ":/new/trunfo_1a.jpg",  //1A
        ":/new/trunfo_2a.jpg",  //2A
        ":/new/trunfo_3a.jpg",  //3A
        ":/new/trunfo_4a.jpg",  //4A
        ":/new/trunfo_5a.jpg",  //5A
        ":/new/trunfo_6a.jpg",  //6A
        ":/new/trunfo_7a.jpg",  //7A
        ":/new/trunfo_8a.jpg",  //8A

        ":/new/trunfo_1b.jpg",  //1B
        ":/new/trunfo_2b.jpg",  //2B
        ":/new/trunfo_3b.jpg",  //3B
        ":/new/trunfo_4b.jpg",  //4B
        ":/new/trunfo_5b.jpg",  //5B
        ":/new/trunfo_6b.jpg",  //6B
        ":/new/trunfo_7b.jpg",  //7B
        ":/new/trunfo_8b.jpg",  //8B

        ":/new/trunfo_1c.jpg",  //1C
        ":/new/trunfo_2c.jpg",  //2C
        ":/new/trunfo_3c.jpg",  //3C
        ":/new/trunfo_4c.jpg",  //4C
        ":/new/trunfo_5c.jpg",  //5C
        ":/new/trunfo_6c.jpg",  //6C
        ":/new/trunfo_7c.jpg",  //7C
        ":/new/trunfo_8c.jpg",  //8C

        ":/new/trunfo_1d.jpg",  //1D
        ":/new/trunfo_2d.jpg",  //2D
        ":/new/trunfo_3d.jpg",  //3D
        ":/new/trunfo_4d.jpg",  //4D
        ":/new/trunfo_5d.jpg",  //5D
        ":/new/trunfo_6d.jpg",  //6D
        ":/new/trunfo_7d.jpg",  //7D
        ":/new/trunfo_8d.jpg",  //8D
    };
};

#endif // CARD_H
