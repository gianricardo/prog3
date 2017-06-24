
#ifndef CARDS_H
#define CARDS_H

#include <QSharedPointer>

#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

#include <carta.h>

class CardImage : public QGraphicsItem {

public:

    CardImage(int num, int np);

    QRectF boundingRect() const {
        return QRectF(x(), y(), 65, 100);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

        Q_UNUSED(option);
        Q_UNUSED(widget);

        painter->drawPixmap(x(),y(), (show_front) ? _front : _back);
    }

private:

    QPixmap _front, _back;
    bool show_front;
};

class OneSuitCard : public p3::Carta{
    
public:

    static const int n_numeros = 13;
    static const int n_naipes = 1;
    
    enum class Naipe {Espadas};

    using p3::Carta::Carta;

    OneSuitCard(int num, Naipe np = Naipe::Espadas);

    void assign_to_scene(QGraphicsScene *scene);

    void assing_image(QSharedPointer<CardImage> image);

private:

    QSharedPointer<CardImage> _image;
};

#endif
