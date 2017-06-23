
#ifndef CARDS_H
#define CARDS_H

#include <memory>

#include <carta.h>
#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class CardImage : public QGraphicsItem {

public:

    CardImage(std::shared_ptr<QPixmap> front, std::shared_ptr<QPixmap> back);

private:

    std::shared_ptr<QPixmap> _front, _back;
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
