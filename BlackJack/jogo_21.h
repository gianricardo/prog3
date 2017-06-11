//
//  jogo_21.h
//  main
//
//  Created by Andre Luigi on 08/06/17.
//
//

#ifndef jogo_21_h
#define jogo_21_h

#include <iostream>
#include "../carteado/src/p3/jogo.h"
#include "regra_21.h"
#include "../carteado/src/p3/carta.h"
#include "banco_21.h"

using namespace p3;


class BlackJack: public JogoBasico<Carta>{
public:
    //cria o jogo;
    //recebe ponteiro de regra de 21 e nome do jogador
    BlackJack(Regra21 * rules, std::string nome_jogador);
    //mostra a carta que esta escondida na mao do dealer
    void revela_mao_dealer();
    //retorna a soma dos pontos da mao do jogador na pos ops
    int soma_mao(std::size_t pos);
    //adicioa uma carta virada para cima a mao do jogador na posicao pos
    void hit(std::size_t pos);
    //inicia a partia, usar apos criar e apos reiniciar
    void inicia_partida_21( );
    //retorna posicao do jogador
    std::size_t pos_j()const;
    //retorna posicao do dealer
    std::size_t pos_d()const;
    //muda para a vez do dealer;
    void vez_do_dealer();
    //muda para a vez do jogador;
    void vez_do_jogador();
    //retorna o nome do jogador
    std::string nome_jogador();
    //realiza uma aposta
    bool apostar(int);
    //dobra o valor da aposta;
    bool dobrar_aposta ();
private:
    Banco21 Banco;
    //posicao do jogador
    std::size_t const pos_jogador = 1;
    //posicao do dealer
    std::size_t const pos_dealer = 0;
    
    
    //verifica quantos pontos a carta vale, decebe numero da carta
    int verifica_ponto(int num_carta);
};


#endif /* jogo_21_h */
