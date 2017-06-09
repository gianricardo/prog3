//
//  banco_21.cpp
//  main
//
//  Created by Andre Luigi on 08/06/17.
//
//

#include "banco_21.h"

Banco::Banco(){
    d_cassino=30000;
    d_jogador=10000;
    aposta=0;
}

bool Banco::set_aposta(int a){
    if(a>d_jogador) return false;
    if(a<5)a=5;
    aposta=a;
    return true;
}
int Banco::get_aposta(void){
    return aposta;
}

int Banco::get_dj(){
    return d_jogador;
}

int Banco::get_dc(){
    return d_cassino;
}

void Banco::resultado(bool a){
    if(a){
        d_jogador= d_jogador+aposta;
        d_cassino=d_cassino - aposta;
    }else{
        d_jogador= d_jogador-aposta;
        d_cassino=d_cassino+aposta;
    }
    aposta=0;
}

bool Banco::autoriza_jogada(){
    if(d_jogador>4)return true;
    return false;
}
