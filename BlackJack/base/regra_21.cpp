//
//  regra_21.cpp
//  main
//
//  Created by Andre Luigi on 08/06/17.
//
//

#include "regra_21.h"
using namespace p3;

Regra21::Regra21() :  Regra(2,2,-1,-1,0,52, (Regra::modo_fim::pontuacao), (Regra::condicao_vitoria::padrao), (Regra::condicao_derrota::zero_pontos)){
    
}

int Regra21::verifica_ponto (int a){
    if(a>10) return 10;
    return a;
}

