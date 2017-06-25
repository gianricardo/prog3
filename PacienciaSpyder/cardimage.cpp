#include "cardimage.h"

CardImage::CardImage(int num, int np){

    if(num != -1) setCard(num, np);

    _back.load(":PacienciaSpyder/img/back.png");

    _back = _back.scaled(65,100);

    setAcceptedMouseButtons(Qt::AllButtons);
    //setFlag( QGraphicsItem::ItemIsFocusable );

    show_front = false;
}
