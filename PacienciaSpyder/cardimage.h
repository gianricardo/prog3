#ifndef CARDIMAGE_H
#define CARDIMAGE_H

#include <iostream>

#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

class CardImage : public QObject, public QGraphicsItem {

    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:

    CardImage() : CardImage(-1, -1) {}
    CardImage(int num, int np);

    void setCard(int num, int np){

        std::string image_name = ":/PacienciaSpyder/img/" + std::to_string(np) + '_' +
                std::to_string(num) + ".png";

        if(!_front.load(QString::fromStdString(image_name))){

            std::cout << "CardImage - No image named\""  << image_name << '\"';
        }

        _front = _front.scaled(65,100);
    }

    void setUp(bool up){

        show_front = up;
    }

    QRectF boundingRect() const {
        return QRectF(x(), y(), 65, 100);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

        Q_UNUSED(option);
        Q_UNUSED(widget);

        painter->drawPixmap(x(),y(), (show_front) ? _front : _back);
    }

signals:

    void pressed(int n_deck, int n_position);
    void released(int n_deck, int n_position);
    void moved(int n_deck, int n_position);

private:

    QPixmap _front, _back;
    bool show_front;

    //int n_deck, n_position;
};

#endif // CARDIMAGE_H
