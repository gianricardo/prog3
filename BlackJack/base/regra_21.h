//
//  regra_21.h
//  main
//
//  Created by Andre Luigi on 08/06/17.
//
//

#ifndef regra_21_h
#define regra_21_h

#include <iostream>
#include "../../carteado/src/p3/regra.h"
#include "../../carteado/src/p3/carta.h"
using namespace p3;


class Regra21: public Regra{
public:
    //cria regra com as especificacoes de 21
    Regra21();
    //verifica a pontuacao da carta de acordo com o seu numero
    //recebe o numero da carta
    //retorna quantos pontos ela vale
    int verifica_ponto (int a);
    
};




#endif /* regra_21_h */
