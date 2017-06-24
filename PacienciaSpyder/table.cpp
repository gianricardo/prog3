#include "table.h"

OneSuitTable::OneSuitTable() : p3::MesaBasica<OneSuitCard, p3::JogadorBasico<OneSuitCard>, Deck<OneSuitCard> >()
{

}

void OneSuitTable::assign_to_scene(QGraphicsScene *scene){

    this->_monte.assign_to_scene(scene);
}
