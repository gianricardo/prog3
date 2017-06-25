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
#include "../../carteado/src/p3/jogo.h"
#include "regra_21.h"
#include "../../carteado/src/p3/carta.h"
#include "banco_21.h"
#include "interface_21.h"
#include "ia_dealer_21.h"
#include "InterfaceGrafica/mainwindow.h"


using namespace p3;


class BlackJack: public JogoBasico<Carta>{
public:
    //cria o jogo;
    //recebe ponteiro de regra de 21 e nome do jogador
    BlackJack(Regra21 * rules, std::string nome_jogador);
    //mostra a carta que esta escondida na mao do dealer
    void revela_mao_dealer();
    //retorna a soma dos pontos da mao do participante na posicao pos
    //recebe a posicao do participante pos
    int soma_mao(std::size_t pos);
    //adicioa uma carta virada para cima a mao do participante na posicao pos
    void hit(std::size_t pos);
    //inicia a partia, usar apos criar e apos reiniciar
    void inicia_rodada_21( );
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
    //recebe o valor da nova aposta
    void apostar(int);
    //dobra o valor da aposta;
    //torna allin caso tenha menos saldo que a aposta dobrada
    //retorna false caso nao consiga apostar e true caso consiga
    bool dobrar_aposta ();
    //verifica ganhador
    //retorna: true=jogador, false=dealer;
    bool verifica_ganhador();
    //verifica se o jogador pode apostar;
    //true se pode, false se nao
    bool pode_apostar();
    //mostra quanto dinheiro o jogador tem no banco
    int saldo();
    //mostra a mao do dealer
    std::vector<Carta> mao_dealer();
    //mostra a mao do jogador
    std::vector<Carta> mao_jogador();
    //realiza a jogada
    //recebe 1 para hit, 2 para dobrar a aposta e 3 para encerrar jogada
    //retorna true caso o jogador queira continuar jogando e false caso nao
    bool jogada(int i);
    //retorna o valor da ultima aposta
    int aposta();
    //gerencia a partida, recebe interface grafica (MainWindow)
    void play (MainWindow & I);

private:
    //banco
    Banco21 Banco;
    //posicao do jogador
    std::size_t const pos_jogador = 1;
    //posicao do dealer
    std::size_t const pos_dealer = 0;
    //valor da ultima aposta
    int ultima_aposta;
    
};


#endif /* jogo_21_h */
