/*
 * jogador.cpp
 *
 *  Created on: 15 de mai de 2017
 *      Author: aluno
 */
#include <iostream>
#include "jogador.h"

namespace p3 {

/* Recebe o nome no construtor */
Jogador::Jogador(std::string name, int posicao) {
	_posicao=pos;
	_nome=name;
	_apto_para_jogar=true;
}

Jogador::~Jogador() {

}

/* Recebe uma carta como argumento e insere no final
 * do vector _mao. */
void Jogador::recebe_carta(Carta card){
	_mao.push_back(card);
}

Carta Jogador::joga_carta(){
	int car=seleciona_carta();
	Carta c=_mao[car];
	_mao.erase(_mao.begin()+car);
	return c;
}

/* Recebe a asdas */
int Jogador::seleciona_carta(){
	int number, count=0;
	Carta::Naipe np;
	std::cin>>number;
	std::cin>>np;
	Carta card(number,np,);
	Carta aux=_mao[count];
	while(card!=*aux && count<_mao.size()){
		count++;
		aux=_mao[count];
	}
	if(count==_mao.size){
		return seleciona_carta();
	}
	return count;
}

int Jogador::pontuacao(){

	return _pontuacao;
}

void Jogador::soma_pontuacao(int soma){

	_pontuacao = _pontuacao + soma;
}

void Jogador::muda_aptidao(){
	 _apto_para_jogar = !( _apto_para_jogar);
}

bool Jogador::esta_apto(){
	return _apto_para_jogar;

}
} /* namespace p3 */


