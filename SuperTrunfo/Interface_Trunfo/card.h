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
        ":/img/Cards/card_back.png",

        ":/img/Cards/trunfo_1a.jpg",  //1A
        ":/img/Cards/trunfo_2a.jpg",  //2A
        ":/img/Cards/trunfo_3a.jpg",  //3A
        ":/img/Cards/trunfo_4a.jpg",  //4A
        ":/img/Cards/trunfo_5a.jpg",  //5A
        ":/img/Cards/trunfo_6a.jpg",  //6A
        ":/img/Cards/trunfo_7a.jpg",  //7A
        ":/img/Cards/trunfo_8a.jpg",  //8A

        ":/img/Cards/trunfo_1b.jpg",  //1B
        ":/img/Cards/trunfo_2b.jpg",  //2B
        ":/img/Cards/trunfo_3b.jpg",  //3B
        ":/img/Cards/trunfo_4b.jpg",  //4B
        ":/img/Cards/trunfo_5b.jpg",  //5B
        ":/img/Cards/trunfo_6b.jpg",  //6B
        ":/img/Cards/trunfo_7b.jpg",  //7B
        ":/img/Cards/trunfo_8b.jpg",  //8B

        ":/img/Cards/trunfo_1c.jpg",  //1C
        ":/img/Cards/trunfo_2c.jpg",  //2C
        ":/img/Cards/trunfo_3c.jpg",  //3C
        ":/img/Cards/trunfo_4c.jpg",  //4C
        ":/img/Cards/trunfo_5c.jpg",  //5C
        ":/img/Cards/trunfo_6c.jpg",  //6C
        ":/img/Cards/trunfo_7c.jpg",  //7C
        ":/img/Cards/trunfo_8c.jpg",  //8C

        ":/img/Cards/trunfo_1d.jpg",  //1D
        ":/img/Cards/trunfo_2d.jpg",  //2D
        ":/img/Cards/trunfo_3d.jpg",  //3D
        ":/img/Cards/trunfo_4d.jpg",  //4D
        ":/img/Cards/trunfo_5d.jpg",  //5D
        ":/img/Cards/trunfo_6d.jpg",  //6D
        ":/img/Cards/trunfo_7d.jpg",  //7D
        ":/img/Cards/trunfo_8d.jpg",  //8D
    };
};

#endif // CARD_H
