//
//  main.cpp
//  21
//
//  Created by Andre Luigi on 22/05/17.
//  Copyright © 2017 Andre Luigi. All rights reserved.
//
//
//
//  git clone https://github.com/gianricardo/prog3.git
//  qmake -spec macx-xcode PROJECT=BlackJack
//
//

#include <iostream>
#include <vector>


#include "jogo_21.h"
#include "regra_21.h"
#include "banco_21.h"
#include "interface_21.h"
#include "ia_dealer_21.h"
#include "../carteado/src/p3/carta.h"


using namespace p3;

int main(void) {
    
    Interface I;
    
    std::string nome = I.novo();
    
    Regra21 *Rules = new Regra21();
    BlackJack Game(Rules, nome);
    
    
    bool continuar=true; //em quanto quiser jogar
    
    bool r=true;//rodada;
    
    

    while (continuar){
        Game.inicia_rodada_21();
        I.placar(Game.saldo());
        if(!Game.pode_apostar()){ //verifica se esta apto a apostar;
            I.naposta();
            continuar = false;
        }else{
            //faz aposta:
            Game.apostar(I.aposta());
            while(r){
                I.mostra_maos(Game.mao_dealer(),Game.mao_jogador());
                r = Game.jogada(I.jogue());
            }
            I.vez_dealer();
            Game.revela_mao_dealer();
            I.mostra_maos(Game.mao_dealer(),Game.mao_jogador());
            IA_Dealer D(Game);
            D.agir(Game);
            I.mostra_maos(Game.mao_dealer(),Game.mao_jogador());
            Game.verifica_ganhador();
            I.vencedor(Game.verifica_ganhador(), Game.aposta(), Game.saldo());
            Game.reiniciar();
            continuar=I.continuar();
        }
    }
    
    I.obrigado();
    
    return 0;
}

