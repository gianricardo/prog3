
#ifndef CARDS_H
#define CARDS_H

#include <QSharedPointer>

#include <carta.h>
#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class CardImage : public QGraphicsItem {

public:

    CardImage();
    CardImage(QSharedPointer<QPixmap> front, QSharedPointer<QPixmap> back);



private:

    QSharedPointer<QPixmap> _front, _back;
};

class OneSuitCard : public p3::Carta {
    
public:

    static const int n_numeros = 13;
    static const int n_naipes = 1;
    
    enum class Naipe {Espadas};
    
    using p3::Carta::Carta;
    
    OneSuitCard(int num, Naipe np = Naipe::Espadas);
    
};


class TwoSuitsCard : public p3::Carta {
    
public:

    static const int n_numeros = 13;
    static const int n_naipes = 2;
    
    enum class Naipe {Espadas, Copas};
    
    using p3::Carta::Carta;
    
    TwoSuitsCard(int num, Naipe np);
};

class FourSuitsCard : public p3::Carta {
    
public:

    static const int n_numeros = 13;
    static const int n_naipes = 4;
    
    using p3::Carta::Naipe;
    
    FourSuitsCard(int num, Naipe np);
};

#endif
