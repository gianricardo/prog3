#include "carta.h"

Carta::Carta(unsigned int val)
{
    clicked = false;
    verso.load(":/new/back_card.png");
    if(val==1){
        frente.load("/new/trunfo_1c.jpg");
    }else{
        frente.load(":/new/trunfo_1a.jpg");
    }
    verso = verso.scaled(150,225);
    frente = frente.scaled(150,225);
    setFlag( QGraphicsItem::ItemIsFocusable );
    setAcceptedMouseButtons(Qt::RightButton | Qt::LeftButton);
    setPos(0,0);
}

QRectF Carta::boundingRect() const
{
    return QRectF(x(),y(),150,225);
}

void Carta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(!clicked){
        painter->drawPixmap(x(),y(),verso);
    }else{
        painter->drawPixmap(x(),y(),frente);
    }
}

void Carta::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clicked = !clicked;
    setPos(x()+10,y());
    if(event->button() == Qt::RightButton){
        setPos(0,0);
    }
    update();
    QGraphicsItem::mousePressEvent(event);
}
