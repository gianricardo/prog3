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

void CardImage::setCard(int num, int np){

    std::string image_name = ":/PacienciaSpyder/img/" + std::to_string(np) + '_' +
            std::to_string(num) + ".png";

    if(!_front.load(QString::fromStdString(image_name))){

        std::cout << "CardImage - No image named\""  << image_name << '\"';
    }

    _front = _front.scaled(x_size, y_size);
}

void CardImage::setUp(bool up){

    show_front = up;
}

void CardImage::setDeck(int deck){

    n_deck = deck;
}

int CardImage::deck() const {

    return n_deck;
}

void CardImage::setDeckPosition(int deck_position){

    n_position = deck_position;
}

int CardImage::deckPosition() const {

    return n_position;
}

void CardImage::setMouseHandler(CardImageMouseEventHandler *handler){

    _handler = handler;
}

void CardImage::setTransparent(bool op){

    if(op) opacityeffect->setOpacity(0.8);
    else opacityeffect->setOpacity(1);
}

QRectF CardImage::boundingRect() const {

    return QRectF(x(), y(), x_size, y_size);
}

void CardImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(x(),y(), (show_front) ? _front : _back);
}

void CardImage::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if(event->button() != Qt::LeftButton) return;

    if(_handler != nullptr) _handler->click_event(n_deck, n_position);
}

BlankCardImage::BlankCardImage(){

    blank_image.load(":/PacienciaSpyder/img/blank.png");

    blank_image = blank_image.scaled(x_size, y_size);
}

void BlankCardImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                           QWidget *widget) {

    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(x(),y(), blank_image);
}


