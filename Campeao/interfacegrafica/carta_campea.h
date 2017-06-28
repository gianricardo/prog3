#ifndef CARTA_CAMPEA_H
#define CARTA_CAMPEA_H


#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include <QString>
#include <QPainter>
class Carta_campea  : public QGraphicsItem
{
public:
    Carta_campea(int numero, int naipe);  //a imagem da carta dependerá de seu valor e seu naipe
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
private:
    QPixmap carta_imagem;
};

#endif // CARTA_CAMPEA_H
