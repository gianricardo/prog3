#include "cardimage.h"

CardImage::CardImage(int num, int np) : n_deck(-1), n_position(-1), _handler(nullptr),
    opacityeffect(new QGraphicsOpacityEffect){

    if(num != -1) setCard(num, np);

    _back.load(":/PacienciaSpyder/img/back.png");

    _back = _back.scaled(x_size, y_size);

    setAcceptedMouseButtons(Qt::AllButtons);
    //setFlag( QGraphicsItem::ItemIsFocusable );

    opacityeffect->setOpacity(1);
    this->setGraphicsEffect(opacityeffect);

    show_front = false;
}
