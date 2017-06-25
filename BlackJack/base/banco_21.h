//
//  banco_21.h
//  main
//
//  Created by Andre Luigi on 08/06/17.
//
//

#ifndef banco_21_h
#define banco_21_h

#include <iostream>

class Banco21{
public:
    //cria banco;
    Banco21();
    //determina valor da aposta da rodada
    //false se o valor nao vor valido
    //recebe o valor da aposta
    //a aposta minima é cinco
    bool set_aposta(int a);
    //retorna valor da aposta da rodada
    int get_aposta();
    //retorna quanto dinheiro o jogador tem
    int get_dj();
    //retorna quanto dinheiro o cassino tem
    int get_dc();
    //atualiza os valores que o cassino e o jogador tem no banco e zera a aposta
    //recebe true jogador ganha, false cassino ganha
    void resultado(bool a);
    //verifica se o jogador tem saldo para apostar
    //retorna true caso o jogador tenha dinheiro para jogar e false caso nao;
    bool autoriza_jogada();
private:
    //dinheiro do cassino no banco
    int d_cassino;
    //dinheiro do jogador no banco
    int d_jogador;
    //vamor da aposta atual
    int aposta;
};


#endif /* banco_21_h */
