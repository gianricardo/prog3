
#include "cards.h"

CardImage::CardImage(QSharedPointer<QPixmap> front, QSharedPointer<QPixmap> back) :
     _front(front), _back(back){

}

OneSuitCard::OneSuitCard(int num, Naipe np) : Carta(num, (Carta::Naipe) np, false){
    
}

TwoSuitsCard::TwoSuitsCard(int num, Naipe np) : Carta(num, (Carta::Naipe) np, false) {
    
}

FourSuitsCard::FourSuitsCard(int num, Naipe np) : Carta(num, (Carta::Naipe) np, false) {

}

