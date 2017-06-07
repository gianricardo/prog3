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


#include "../carteado/src/p3/baralho.h"
#include "../carteado/src/p3/carta.h"
#include "../carteado/src/p3/jogador.h"
#include "../carteado/src/p3/jogo.h"
#include "../carteado/src/p3/mesa.h"
#include "../carteado/src/p3/regra.h"

using namespace p3;

Regra * regras_21(void){
    Regra *Rules = new Regra(2,2,-1,-1,0,52, (Regra::modo_fim::pontuacao), (Regra::condicao_vitoria::padrao), (Regra::condicao_derrota::zero_pontos));
    return Rules;
    //regras é destruido (desalocado) pelo destrutor de Jogo Basico
}

void inicia_partida_21(JogoBasico<Carta> *Game){
    std::vector<Carta> hand_aux;
    Game->novo_monte(); //cria monte do dealder
    Game->novo_monte(); //cria monte do jogador
    Game->vira_carta_jogador(0,0); //coloca uma carta do dealer virada para cima
    hand_aux=Game->mostra_mao_jogador_atual(); //pega ref. mao do dealer
    Game->fim_jogada(); //passa pro player
    Game->vira_carta_jogador(0,1);//vira as duas cartas do jogador
    Game->vira_carta_jogador(1,1);

}

void hit(JogoBasico<Carta> &Game, std::size_t player_pos){
    Game.move_carta_mj(player_pos,true,false);
    int card_pos=-1;
    for(auto a:Game.mostra_monte(player_pos)){
        card_pos++;
    }
    Game.vira_carta_monte(card_pos,false);
}



int soma_mao(std::vector<Carta> mao){
    int soma=0;
    for(auto a:mao){
        if(a.numero()>10){
            soma = soma+10;
        }
        else{soma = soma+a.numero();}
    }
    return soma;
}

void mostra_mao(std::vector<Carta> mao){
    for (auto a:mao){
        std::cout<<a.numero()<<std::endl;
    }
    
}

void mostra_soma(std::vector<Carta> mao){
    std::cout<<"Soma:"<<soma_mao(mao)<<std::endl;
    
}

int main(void) {
    
    
    std::vector<std::pair<bool,Carta>> deck_dealer;
    std::vector<std::pair<bool,Carta>> deck_player;
   // std::size_t const deck_dealer_pos=1;
  //  std::size_t const deck_player_pos=2;
    std::string player_name= "Player";
//   int $h = 9999999;
//   int $p = 10000;
//  int gamble =0;
    
    
    JogoBasico<Carta> Game(regras_21(), {"Dealer", player_name});
    
    
    inicia_partida_21(&Game);
    
    //Game.mostra_mao_jogador(0);
    
    
    
    
    //Game.reiniciar();
    
    //inicia_partida_21(&Game);
    
    auto vet = Game.mostra_mao_jogador(0);

    std::cout<< vet[0].numero()<<std::endl;
    std::cout<< vet[1].numero()<<std::endl;
  
    
    // std::cout<<Game.mostra_mao_jogador(1)[0].numero()<<std::endl;
    
    
    return 0;
}
