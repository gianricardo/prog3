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

    const CARD top() const {

        return this->_monte.front();
    }
    const CARD bottom() const {

        return this->_monte.back();
    }

};

#endif // DECK_H
