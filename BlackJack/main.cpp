//
//  main.cpp
//  21
//
//  Created by Andre Luigi on 22/05/17.
//  Copyright © 2017 Andre Luigi. All rights reserved.
//

#include <iostream>
#include "../carteado/src/p3/baralho.h"
#include "../carteado/src/p3/carta.h"
#include "../carteado/src/p3/jogador.h"
#include "../carteado/src/p3/jogo.h"
#include "../carteado/src/p3/mesa.h"
#include "../carteado/src/p3/regra.h"

using namespace p3;
int main(void) {
    // insert code here...
    
    //
    JogadorBasico<Carta> Player("Player");
    JogadorBasico<Carta> Dealer("Dealer");
    BaralhoBasico<Carta> Deck(52);
    Deck.embaralhar();
    
    
    
    return 0;
}
