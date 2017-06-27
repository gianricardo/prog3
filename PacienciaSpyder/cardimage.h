#ifndef CARDIMAGE_H
#define CARDIMAGE_H

#include <iostream>

#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsEffect>

class CardImageMouseEventHandler {

public:

    virtual void click_event(int n_deck, int n_position) = 0;
};

class CardImage : public QGraphicsItem {

public:

    static const std::size_t x_size = 65;
    static const std::size_t y_size = 100;

    CardImage() : CardImage(-1, -1) {}
    CardImage(int num, int np);

    void setCard(int num, int np);

    void setUp(bool up);

    void setDeck(int deck);

    int deck() const ;

    void setDeckPosition(int deck_position);

    int deckPosition() const ;

    void setMouseHandler(CardImageMouseEventHandler *handler);

    void setTransparent(bool op);

    QRectF boundingRect() const ;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:

    QPixmap _front, _back;
    bool show_front;

    int n_deck, n_position;
    CardImageMouseEventHandler *_handler;
    QGraphicsOpacityEffect *opacityeffect;
};

class BlankCardImage : public CardImage {

public:

    BlankCardImage();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override ;

private:

    QPixmap blank_image;
};


#endif // CARDIMAGE_H
