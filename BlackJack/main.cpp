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


int soma_mone(std::vector<std::pair<bool,Carta>> monte){
    int soma=0;
    for(auto a:monte){
        soma = soma+a.second.numero();
    }
    return soma;
}


int main(void) {
    // insert code here...
    
    //
    
    //Construtor
    //recebe como parametros o numero de jogadores que o jogo possui inicialmente, a quantidade de cartas que cada
    //jogador tem na primeira rodada, o numero de rodadas maximo, a pontuacao maxima que pode ser atingida, a pontuacao
    //minima que pode ser atingida, a quantidade de cartas inicial do baralho principal do jogo, e os modos de fim de
    //jogo, de vitoria e de derrota
    
    std::vector<Carta> hand;
    int $h = 9999999;
    int $p = 10000;
    // int gamble =0;
    
    Regra *Rules = new Regra(2,2,-1,-1,0,52, (Regra::modo_fim::pontuacao), (Regra::condicao_vitoria::padrao), (Regra::condicao_derrota::zero_pontos));
    JogoBasico<Carta> Game(Rules, {"Dealer","Player"});
    
    Game.novo_monte(); //cria monte do dealder
    Game.novo_monte(); //cria monte do jogador
    Game.novo_monte();
    Game.vira_carta_jogador(0); //coloca uma carta do dealer virada/
    hand=Game.mostra_mao_jogador_atual(); //pega ref. mao do dealer
    Game.move_carta_jm(hand[0],0,1,true); //coloca as cartas do dealer no seu monte
    Game.move_carta_jm(hand[1],0,1,true);
    Game.jogador_soma_pontos($h); //coloca o dinheiro do dealer
    Game.fim_jogada(); //passa pro player
    Game.vira_carta_jogador(0,1);
    Game.vira_carta_jogador(1,1);
    hand=Game.mostra_mao_jogador_atual(); //pega ref. mao jogador
    Game.move_carta_jm(hand[0],1,2,true); //passa as cartas pro monte do jogador
    Game.move_carta_jm(hand[1],1,2,true);
    Game.jogador_soma_pontos($p);//coloca o dinheiro do jogador;

    std::vector<std::pair<bool,Carta>> deck;
    
    deck =Game.mostra_monte(1);
    std::cout<<"\nMD"<<std::endl;
    std::cout<<deck[0].second.numero()<<std::endl;
    std::cout<<deck[1].second.numero()<<std::endl;
    std::cout<<"soma:"<<soma_mone(deck)<<std::endl;
    
    
    deck =Game.mostra_monte(2);
    std::cout<<"\nMP"<<std::endl;
    std::cout<<deck[0].second.numero()<<std::endl;
    std::cout<<deck[1].second.numero()<<std::endl;
    
    Game.move_carta_m(2,true,false);
    Game.vira_carta_monte(2,false);
    deck =Game.mostra_monte(2);
    std::cout<<deck[2].second.numero()<<std::endl;
    std::cout<<"soma:"<<soma_mone(deck)<<std::endl;
    
    
    Game.vira_carta_monte(1);
    deck =Game.mostra_monte(1);
    std::cout<<"\nMD"<<std::endl;
    std::cout<<deck[0].second.numero()<<std::endl;
    std::cout<<deck[1].second.numero()<<std::endl;
    std::cout<<"soma:"<<soma_mone(deck)<<std::endl;
    
    
    
    Game.reiniciar();
    std::cout<<"----------------------------------"<<std::endl;
    
    Game.novo_monte(); //cria monte do dealder
    Game.novo_monte(); //cria monte do jogador
    Game.novo_monte();
    Game.vira_carta_jogador(0); //coloca uma carta do dealer virada/
    hand=Game.mostra_mao_jogador_atual(); //pega ref. mao do dealer
    Game.move_carta_jm(hand[0],0,1,true); //coloca as cartas do dealer no seu monte
    Game.move_carta_jm(hand[1],0,1,true);
    Game.jogador_soma_pontos($h); //coloca o dinheiro do dealer
    Game.fim_jogada(); //passa pro player
    Game.vira_carta_jogador(0,1);
    Game.vira_carta_jogador(1,1);
    hand=Game.mostra_mao_jogador_atual(); //pega ref. mao jogador
    Game.move_carta_jm(hand[0],1,2,true); //passa as cartas pro monte do jogador
    Game.move_carta_jm(hand[1],1,2,true);
    Game.jogador_soma_pontos($p);//coloca o dinheiro do jogador;
    

    
    deck =Game.mostra_monte(1);
    std::cout<<"\nMD"<<std::endl;
    std::cout<<deck[0].second.numero()<<std::endl;
    std::cout<<deck[1].second.numero()<<std::endl;
    std::cout<<"soma:"<<soma_mone(deck)<<std::endl;
    
    
    deck =Game.mostra_monte(2);
    std::cout<<"\nMP"<<std::endl;
    std::cout<<deck[0].second.numero()<<std::endl;
    std::cout<<deck[1].second.numero()<<std::endl;
    
    Game.move_carta_m(2,true,false);
    Game.vira_carta_monte(2,false);
    deck =Game.mostra_monte(2);
    std::cout<<deck[2].second.numero()<<std::endl;
    std::cout<<"soma:"<<soma_mone(deck)<<std::endl;
    
    
    Game.vira_carta_monte(1);
    deck =Game.mostra_monte(1);
    std::cout<<"\nMD"<<std::endl;
    std::cout<<deck[0].second.numero()<<std::endl;
    std::cout<<deck[1].second.numero()<<std::endl;
    std::cout<<"soma:"<<soma_mone(deck)<<std::endl;
    
    
    return 0;
}
