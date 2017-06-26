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
    virtual void release_event(int n_deck, int n_postion) = 0;
};

class CardImage : public QGraphicsItem {

public:

    static const std::size_t x_size = 65;
    static const std::size_t y_size = 100;

    CardImage() : CardImage(-1, -1) {}
    CardImage(int num, int np);

    void setCard(int num, int np){

        std::string image_name = ":/PacienciaSpyder/img/" + std::to_string(np) + '_' +
                std::to_string(num) + ".png";

        if(!_front.load(QString::fromStdString(image_name))){

            std::cout << "CardImage - No image named\""  << image_name << '\"';
        }

        _front = _front.scaled(x_size, y_size);
    }

    void setUp(bool up){

        show_front = up;
    }

    void setDeck(int deck){

        n_deck = deck;
    }

    int deck(){

        return n_deck;
    }

    void setDeckPosition(int deck_position){

        n_position = deck_position;
    }

    int deckPosition(){

        return n_position;
    }

    void setMouseHandler(CardImageMouseEventHandler *handler){

        _handler = handler;
    }

    void setTransparent(bool op){

        if(op){

            opacityeffect->setOpacity(0.8);
        }
        else{

            opacityeffect->setOpacity(1);
        }
    }

    QRectF boundingRect() const {
        return QRectF(x(), y(), x_size, y_size);
    }

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

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
    QGraphicsOpacityEffect *opacityeffect;
};

class BlankCardImage : public CardImage {

public:

    BlankCardImage(){

        blank_image.load(":/PacienciaSpyder/img/blank.png");

        blank_image = blank_image.scaled(x_size, y_size);
    }

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {

        Q_UNUSED(option);
        Q_UNUSED(widget);

        painter->drawPixmap(x(),y(), blank_image);
    }

private:

    QPixmap blank_image;
};


#endif // CARDIMAGE_H
