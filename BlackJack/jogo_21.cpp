//
//  jogo_21.cpp
//  main
//
//  Created by Andre Luigi on 08/06/17.
//
//

#include "jogo_21.h"

BlackJack::BlackJack(Regra21 *Rules, std::string nome_jogador) : JogoBasico(Rules, {"Dealer", nome_jogador}){
    
}

void BlackJack::revela_mao_dealer(){
    vira_carta_jogador(1,0);
}


int BlackJack::soma_mao(std::size_t pos){
    int soma=0;
    for(auto a:mostra_mao_jogador(pos)){
        soma = soma+verifica_ponto(a.numero());
    }
    return soma;
}

int BlackJack::verifica_ponto (int a){
    if(a>10) return 10;
    return a;
}

void BlackJack::hit(std::size_t player_pos){
    move_carta_mj(0,player_pos,false);
    int card_pos=-1;
    for(auto a:mostra_mao_jogador(player_pos)){
        card_pos++;
    }
    vira_carta_jogador(card_pos,player_pos);
}

void BlackJack::inicia_partida_21( ){
    vira_carta_jogador(0,0); //coloca uma carta do dealer virada para cima
    vira_carta_jogador(0,1);//vira as duas cartas do jogador
    vira_carta_jogador(1,1);
}

std::size_t BlackJack::pos_j()const{
    return pos_jogador;
}
std::size_t BlackJack::pos_d()const{
    return pos_dealer;
}

void BlackJack::vez_do_dealer(){
    muda_jogador_atual((int)pos_dealer);
}

void BlackJack::vez_do_jogador(){
    muda_jogador_atual((int)pos_jogador);
}

std::string BlackJack::nome_jogador(){
    std::string n = "-";
    if(posicao_jogador_atual() ==pos_dealer){
        vez_do_jogador();
        n = nome_jogador_atual();
        vez_do_dealer();
    }else {n = nome_jogador_atual();}
    return n;
}


bool BlackJack::apostar(int a){
    return Banco.set_aposta(a);
    
}

bool BlackJack::dobrar_aposta(){
    return Banco.set_aposta(Banco.get_aposta()*2);
}

bool BlackJack::verifica_ganhador(){
    if(soma_mao(pos_jogador)==21){ //se o jogador ffizer 21, jogador vence
        return true;
    }
    if(soma_mao(pos_dealer)>21){ //se o dealer estoura, jogador vence
        return true;
    }
    if(soma_mao(pos_jogador)>21){ //se o jogador estoura mas o dealer nao o cassino ganha
        return false;
    }
    
    if(21-soma_mao(pos_jogador)<21-soma_mao(pos_dealer)){//se jogador se aproxima mais de 21 ele ganha
        return true;
    }
    
    return false; //se nenhuma das anteriores, o cassino ganha

}


