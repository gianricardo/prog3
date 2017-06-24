#ifndef DECK_H
#define DECK_H

#include <map>

#include <baralho.h>

#include "cards.h"

template<class CARD>
class Deck : public p3::BaralhoBasico<CARD>{

public:

    using p3::BaralhoBasico<CARD>::BaralhoBasico;

    Deck() : p3::BaralhoBasico<CARD>() {}

    void assign_to_scene(QGraphicsScene *scene);

};

template<class CARD> void Deck<CARD>::assign_to_scene(QGraphicsScene *scene){

    for(auto& card : p3::BaralhoBasico<CARD>::_monte){

        card.assign_to_scene(scene);
    }
}

#endif // DECK_H
