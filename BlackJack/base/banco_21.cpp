//
//  banco_21.cpp
//  main
//
//  Created by Andre Luigi on 08/06/17.
//
//

#include "banco_21.h"

Banco21::Banco21(){
    d_cassino=999999999;
    d_jogador=10000;
    aposta=0;
}

bool Banco21::set_aposta(int a){
    if(a>d_jogador) a=d_jogador;
    if(a<5)a=5;
    if(a>1000000) a=1000000;
    aposta=a;
    return true;
}
int Banco21::get_aposta(void){
    return aposta;
}

int Banco21::get_dj(){
    return d_jogador;
}

int Banco21::get_dc(){
    return d_cassino;
}

void Banco21::resultado(bool a){
    if(a){
        d_jogador= d_jogador+aposta;
        d_cassino=d_cassino - aposta;
    }else{
        d_jogador= d_jogador-aposta;
        d_cassino=d_cassino+aposta;
    }
    if (d_jogador > 99999999) d_jogador = 999999999;
    aposta=0;
}

bool Banco21::autoriza_jogada(){
    if(d_jogador>4)return true;
    return false;
}
