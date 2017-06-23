
#include "cards.h"

CardImage::CardImage(std::shared_ptr<QPixmap> front, std::shared_ptr<QPixmap> back) :
     _front(front), _back(back){

}

OneSuitCard::OneSuitCard(int num, Naipe np) : Carta(num, (Carta::Naipe) np, false){
    
}

TwoSuitsCard::TwoSuitsCard(int num, Naipe np) : Carta(num, (Carta::Naipe) np, false) {
    
}

FourSuitsCard::FourSuitsCard(int num, Naipe np) : Carta(num, (Carta::Naipe) np, false) {

}

