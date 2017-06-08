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

class Banco{
public:
    //cria banco;
    Banco();
    //determina valor da aposta da rodada
    //false se o valor nao vor valido
    //a aposta minima é cinco
    bool set_aposta(int a);
    //mostra valor da aposta da rodada
    int get_aposta();
    //mostra quanto dinheiro o jogador tem
    int get_dj();
    //mostra quanto dinheiro o cassino tem
    int get_dc();
    //atualiza os valores que o cassino e o jogador tem no banco e zera a aposta
    //entra true jogador ganha, false cassino ganha
    void resultado(bool a);
    //true caso o jogador tenha dinheiro para jogar e false caso nao;
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
