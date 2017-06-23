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

    void set_images(std::map<OneSuitCard, std::string> front_images , std::string back_image);

};

#endif // DECK_H
