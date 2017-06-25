#ifndef CARDIMAGE_H
#define CARDIMAGE_H

#include <iostream>

#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

class CardImageMouseEventHandler {

public:

    virtual void click_event(int n_deck, int n_position) = 0;
    virtual void release_event(int n_deck, int n_postion) = 0;
};

class CardImage : public QGraphicsItem {

public:

    CardImage() : CardImage(-1, -1) {}
    CardImage(int num, int np);

    void setCard(int num, int np){

        std::string image_name = ":/PacienciaSpyder/img/" + std::to_string(np) + '_' +
                std::to_string(num) + ".png";

        if(!_front.load(QString::fromStdString(image_name))){

            std::cout << "CardImage - No image named\""  << image_name << '\"';
        }

        _front = _front.scaled(65,100);
    }

    void setUp(bool up){

        show_front = up;
    }

    void setDeck(int deck){

        n_deck = deck;
    }

    void setDeckPosition(int deck_position){

        n_position = deck_position;
    }

    void setMouseHandler(CardImageMouseEventHandler *handler){

        _handler = handler;
    }

    QRectF boundingRect() const {
        return QRectF(x(), y(), 65, 100);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

        Q_UNUSED(option);
        Q_UNUSED(widget);

        painter->drawPixmap(x(),y(), (show_front) ? _front : _back);
    }

    void mousePressEvent(QGraphicsSceneMouseEvent *event){

        if(event->button() != Qt::LeftButton) return;

        if(_handler != nullptr) _handler->click_event(n_deck, n_position);
    }

private:

    QPixmap _front, _back;
    bool show_front;

    int n_deck, n_position;
    CardImageMouseEventHandler *_handler;
};

#endif // CARDIMAGE_H
