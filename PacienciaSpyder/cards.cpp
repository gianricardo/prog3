
#include "cards.h"


CardImage::CardImage(int num, int np){

    std::string image_name = ":/PacienciaSpyder/img/" + std::to_string(num) + '_' + std::to_string(np) + ".png";

    _front.load(QString::fromStdString(image_name));
    _back.load(":PacienciaSpyder/img/back.png");

    _front = _front.scaled(65,100);
    _back = _back.scaled(65,100);

    setAcceptedMouseButtons(Qt::AllButtons);
    //setFlag( QGraphicsItem::ItemIsFocusable );

    show_front = false;

}

OneSuitCard::OneSuitCard(int num, Naipe np) : Carta(num, (Carta::Naipe) np, false){

}

void OneSuitCard::assign_to_scene(QGraphicsScene *scene){

    scene->addItem(_image.data());
}




