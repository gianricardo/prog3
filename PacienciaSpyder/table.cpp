#include "table.h"

OneSuitTable::OneSuitTable() : p3::MesaBasica<OneSuitCard, Player<OneSuitCard>, Deck<OneSuitCard> >()
{

}

const OneSuitCard OneSuitTable::top_card(std::size_t deck){

    OneSuitCard card = ((deck == 0) ? this->_monte.top() : this->_outros_montes[deck-1].top());

    if(!card.mostra()) return OneSuitCard(0, (OneSuitCard::Naipe) 0);

    return card;
}

const OneSuitCard OneSuitTable::bottom_card(std::size_t deck){

    OneSuitCard card = ((deck == 0) ? this->_monte.bottom() : this->_outros_montes[deck-1].bottom());

    if(!card.mostra()) return OneSuitCard(0, (OneSuitCard::Naipe) 0);

    return card;
}
