//
//  ia_dealer_21.h
//  main
//
//  Created by Andre Luigi on 11/06/17.
//
//

#ifndef ia_dealer_21_h
#define ia_dealer_21_h

#include <iostream>

#include "jogo_21.h"


//a inteligencia artificial guarda as informacoes pertinentes tendo uma "visao" do jogo
//com esses valores ele decide o que fazer
//ele recebe novamente a referencia de jogo e realiza a acao;

class IA_Dealer{
public:
    IA_Dealer (BlackJack &Game);
    //return true caso queira hit, false caso queira parar;
    bool decidir();
    void agir (BlackJack &Game);
    
protected:
    int meus_pontos;
    int pontos_jogador;
    std::size_t minha_pos;
    std::size_t pos_jogador;
};


#endif /* ia_dealer_21_h */

