
#include "cards.h"

OneSuitCard::OneSuitCard(int num, Naipe np) : Carta(num%n_numbers + 1, (Carta::Naipe) np, false){
    
}

TwoSuitsCard::TwoSuitsCard(int num, Naipe np) : Carta(num%n_numbers + 1, (Carta::Naipe) np, false) {
    
}

FourSuitsCard::FourSuitsCard(int num, Naipe np) : Carta(num%n_numbers + 1, (Carta::Naipe) np, false) {

}

