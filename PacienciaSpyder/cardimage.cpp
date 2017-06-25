#include "cardimage.h"

CardImage::CardImage(int num, int np) : _handler(nullptr), n_deck(-1), n_position(-1) {

    if(num != -1) setCard(num, np);

    _back.load(":PacienciaSpyder/img/back.png");

    _back = _back.scaled(65,100);

    setAcceptedMouseButtons(Qt::AllButtons);
    //setFlag( QGraphicsItem::ItemIsFocusable );

    show_front = false;
}
