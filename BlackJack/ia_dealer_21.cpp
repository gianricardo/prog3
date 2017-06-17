//
//  ia_dealer_21.cpp
//  main
//
//  Created by Andre Luigi on 11/06/17.
//
//

#include "ia_dealer_21.h"

IA_Dealer::IA_Dealer (int pj){
    pontos_jogador=pj;
}

bool IA_Dealer::decidir(int mp){
    
    meus_pontos=mp;
    
    if(pontos_jogador>20){ //se o jogador ja ganhou (21) ou ja perdeu (22+)
        return false;
    }
    if(meus_pontos>21){//se o dealer ja oerdeu

        return false;
    }
    if (21-meus_pontos<21-pontos_jogador){//se o dealer esta mais perto de 21
        return false;
    }
    return true;
}
