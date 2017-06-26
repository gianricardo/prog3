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
    //recebe o inteiro referente ao naipe e outro ao numero da carta
    //os valores de naipes seguem a enumeracao prsente na classe Carta
    imagem_carta(int naipe, int numero);
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
private:
    QPixmap imagem;
};

#endif // IMAGEM_CARTA_H
