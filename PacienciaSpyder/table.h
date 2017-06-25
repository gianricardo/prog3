#ifndef TABLE_H
#define TABLE_H

#include <mesa.h>

#include "deck.h"
#include "player.h"

class OneSuitTable : public p3::MesaBasica<OneSuitCard, Player<OneSuitCard>, Deck<OneSuitCard> >
{
public:

    using p3::MesaBasica<OneSuitCard, Player<OneSuitCard>, Deck<OneSuitCard> >::MesaBasica;

    OneSuitTable();

};

#endif // TABLE_H
