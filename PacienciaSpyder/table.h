#ifndef TABLE_H
#define TABLE_H

#include <mesa.h>

#include "deck.h"

class OneSuitTable : public p3::MesaBasica<OneSuitCard, p3::JogadorBasico<OneSuitCard>, Deck<OneSuitCard> >
{
public:

    using p3::MesaBasica<OneSuitCard, p3::JogadorBasico<OneSuitCard>, Deck<OneSuitCard> >::MesaBasica;

    OneSuitTable();

    void assign_to_scene(QGraphicsScene *scene);

};

#endif // TABLE_H
