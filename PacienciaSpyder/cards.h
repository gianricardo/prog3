
#ifndef CARDS_H
#define CARDS_H

#include <carta.h>

class OneSuitCard : public p3::Carta {
    
public:
    
    static const int n_numbers = 13;
    static const int n_naipes = 1;
    
    enum class Naipe {Espadas};
    
    using p3::Carta::Carta;
    
    OneSuitCard(int num, Naipe np);
    
};


class TwoSuitsCard : public p3::Carta {
    
public:

    static const int n_numbers = 13;
    static const int n_naipes = 2;
    
    enum class Naipe {Espadas, Copas};
    
    using p3::Carta::Carta;
    
    TwoSuitsCard(int num, Naipe np);
};

class FourSuitsCard : public p3::Carta {
    
public:

    static const int n_numbers = 13;
    static const int n_naipes = 4;
    
    using p3::Carta::Naipe;
    
    FourSuitsCard(int num, Naipe np);
};


#endif
