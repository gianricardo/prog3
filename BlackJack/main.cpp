//
//  main.cpp
//  21
//
//  Created by Andre Luigi on 22/05/17.
//  Copyright © 2017 Andre Luigi. All rights reserved.
//

#include <iostream>
#include <vector>
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
    
    Regra Rules(2,2,-1,-1,0,52, (Regra::modo_fim::pontuacao), (Regra::condicao_vitoria::maior_pontuacao), (Regra::condicao_derrota::nenhuma));
    
    Jogo Game(&Rules,{"Dealer","Player"});
    std::vector<Carta> hand_1;
    hand_1=Game.mostra_mao_jogador_atual();
    Game.vira_cara(hand_1[0]);
    
    
    
    
    
    
    
    return 0;
}
