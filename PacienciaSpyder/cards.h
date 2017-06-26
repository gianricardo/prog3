
#ifndef CARDS_H
#define CARDS_H

#include <QSharedPointer>

#include <carta.h>

class OneSuitCard : public p3::Carta{
    
public:

    static const int n_numeros = 13;
    static const int n_naipes = 1;
    
    enum class Naipe {Espadas};

    using p3::Carta::Carta;

    OneSuitCard(int num, Naipe np = Naipe::Espadas);
};

#endif
