#ifndef IMAGEM_CARTA_H
#define IMAGEM_CARTA_H
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include <QString>
#include <QPainter>

class imagem_carta : public QGraphicsItem
{
public:
    imagem_carta(int naipe, int numero);
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
private:
    QPixmap imagem;
};

#endif // IMAGEM_CARTA_H
