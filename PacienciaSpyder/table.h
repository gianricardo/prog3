#ifndef TABLE_H
#define TABLE_H

#include <map>

#include <mesa.h>

#include "deck.h"

class OneSuitTable : public p3::MesaBasica<OneSuitCard, p3::JogadorBasico<OneSuitCard>, Deck<OneSuitCard> >
{
public:

    using p3::MesaBasica<OneSuitCard, p3::JogadorBasico<OneSuitCard>, Deck<OneSuitCard> >::MesaBasica;

    OneSuitTable();

    void set_images(std::map<OneSuitCard, std::string> front_images , std::string back_image);
};

#endif // TABLE_H
