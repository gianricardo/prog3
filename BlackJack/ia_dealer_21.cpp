//
//  ia_dealer_21.cpp
//  main
//
//  Created by Andre Luigi on 11/06/17.
//
//

#include "ia_dealer_21.h"

IA_Dealer::IA_Dealer(BlackJack &Game){
    minha_pos=Game.pos_d();
    pos_jogador=Game.pos_j();
    pontos_jogador=Game.soma_mao(pos_jogador);
    meus_pontos=Game.soma_mao(minha_pos);
}

bool IA_Dealer::decidir(){
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


void IA_Dealer::agir (BlackJack &Game){
    meus_pontos=Game.soma_mao(minha_pos);
    bool pede=decidir(); //decide se pede hit
    while (pede){
        Game.hit(minha_pos); //se verdadeiro pede
        meus_pontos=Game.soma_mao(minha_pos);
        pede=decidir(); //decide se pede hit na proxima
    }
    return;
}
