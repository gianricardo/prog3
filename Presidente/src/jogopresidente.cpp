/*
 * jogopresidente.cpp
 *
 *  Created on: 8 de jun de 2017
 *      Author: adolfo
 */

#include "jogopresidente.h"

JogoPresidente::JogoPresidente(p3::Regra *r,std::vector<std::string> p) : p3::Jogo(r,p){
}

JogoPresidente::~JogoPresidente() {
}

int JogoPresidente::acha_carta_jogavel(std::vector<Carta> v,int numerocartas,int valor){
	int jogavel=0;
	for(auto k:v){
		if(k.numero()>valor && how_many_in_the_hand(v,k.numero())>=numerocartas){
			jogavel=k.numero();
		}
	}
	return jogavel;
}

void JogoPresidente::joga_cartas(int carta,int numerocartas){
	//retirar as primeiras numerocartas cartas com numero igual a carta
	int i=0;
	while(i!=numerocartas){
		for(int j=0;j<4;j++){
			if(move_carta_jm(Carta(carta,(Carta::Naipe)j),_jog_atual,i+1,true)){
				i++;
				break;
			}
		}
	}
}

int JogoPresidente::how_many_in_the_hand(std::vector<Carta> v,int valor){
	int count=0;
	for(auto c : v){
		if(c.numero()==valor) count++;
	}
	return count;
}

void JogoPresidente::fim_jogada(){
	if(!_jogando) return;
	if(numero_jogadores_aptos()==0){
		_jog_atual = _positions[0];
		jogador_soma_pontos(3,_positions[0]);
		jogador_soma_pontos(2,_positions[1]);
		jogador_soma_pontos(1,_positions[2]);
		limpa_outros_montes();
		_rodada++;
		verifica_jogadores_derrotados();
		verifica_fim_de_jogo();
		verifica_vitoria();
		restaurar_monte_inicial();
		distribuir();
		muda_aptidao(0);
		muda_aptidao(1);
		muda_aptidao(2);
		muda_aptidao(3);
	}
}

void JogoPresidente::add_position(int jogador){
	_positions.push_back(jogador);
}

int JogoPresidente::retorna_bobo(){

}

int JogoPresidente::retorna_pres(){

}

int JogoPresidente::retorna_vicebobo(){

}

int JogoPresidente::retorna_vicepres(){

}

std::vector<int> JogoPresidente::find_highest(int numbercards){

}

std::vector<int> JogoPresidente::find_lowest(int numbercards){

}

void JogoPresidente::pass_card(std::vector<int> v,int pos1,int pos2){

}
